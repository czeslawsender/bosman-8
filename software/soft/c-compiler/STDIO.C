/* Copyright (c) by SuperSoft, Inc., 1982 */

/*	stdio.c
 *
 *	This version has:
 *	User codes in file specs (eg b/6:file)
 *	Serial devices CON, RDR, PUN, LST may be opened and treated as files.
 *	Structures
 *	Fix for execl done on 6 July 1982  MQH
 *	Fix to fclose 1982 July 9 RB
 *	Fix to getw 1982 July 9 RB
 *	Fix to exec 1982 Sept 19 RB
 *	Fix to cpmver, seek, and unlink 1982 Sept 29 RB
 *	Full setup for C 1.2.2
 *	Fix SET_DRIVE call in CP/M 1.4 code
 *	Added byte-wise-ness 1982 Dec 30 RV
 *
 */

#define	STDIOEDIT	38

/*
 *
 * open(filename, mode) mode = 0,1,2
 * creat(filename, prot)
 * close(fd)
 * fopen(filename, mode, buffer_size) mode = "r","w","a","rw"
 * write(fd, buffer, byte_count)
 * read(fd, buffer, byte_count)
 * cio(mode, fcb_pointer, buffer, byte_count)
 * cpmver()
 * seek(fd, offset, code)	code = 0,1,2,3,4,5
 * tell(fd)	tell returns bytes
 * otell(fd)	otell returns bytes % 512
 * rtell(fd)	rtell returns bytes / 512
 * fabort(fd)
 * exec(p)
 * execl(nargs)
 */

#include	"customiz.h"
#include	"stdio.h"

#ifdef	SEEK
#define	RANDIO
#ifdef	CPM1p4
#define	CPM1p4SEEK
#endif	CPM1p4
#else	SEEK
#ifdef	BYTEWISE
#define	RANDIO
#endif	BYTEWISE
#endif	SEEK

#define	RS	REC_SIZE

static unsigned serialout();
static unsigned xsize();

/* functions between ==== are machine dependent */
cpmver()
{
#ifdef	CPM1p4
#asm
	push	b
	mvi	c,12
	call	5
	mvi	h,0
	pop	b
#endasm
#else	CPM1p4
	return 0x20;
#endif	CPM1p4
}

FILE *
open(filename, mode)
 char	*filename;
 unsigned mode;
{
	register FILE *fd;

	if((fd = fillfcb(filename)) == ERROR)
		return ERROR;

	if((fd->fd_fm = mode) > FCB_R_W)
		return Xseterr(INVMODE,fd);

	switch(fd->fd_dc) {
#ifdef SERIAL
	case NUL:
	case CON:
		break;
	case RDR:
		if(mode != FCB_READ)
			return Xseterr(BADDEV,fd);
		break;
	case LST:
	case PUN:
		if(mode != FCB_WRITE)
			return Xseterr(BADDEV,fd);
		break;
#endif	SERIAL
	default:
		xsetdma(INIT_DMA);
		if(ybdos(CC_OPEN, fd) == ERROR) {
			free(fd);
			return ERROR;
		}
	}

	/* check to see if trying to write a read-only file */
	if( ((mode+1)&2) && (fd->fd_ext[0]&0x80) ) {
		close(fd);
		return ERROR;
	}
	return fd;
}

FILE *
creat(filename, mode)
 char	*filename;
 unsigned mode;
{
	register FILE *fd;

	if((fd = fillfcb(filename)) == ERROR)
		return ERROR;

	fd->fd_fm = FCB_WRITE;
	switch(fd->fd_dc)
	{
#ifdef SERIAL
	case RDR:
		return Xseterr(BADDEV,fd);
	case NUL:
	case CON:
	case LST:
	case PUN:
		break;
#endif SERIAL
	default:
		xbdos(CC_DELETE, fd);
		if(ybdos(CC_CREAT, fd) == ERROR) {
			free(fd);
			return ERROR;
		}
#ifdef	CPM1p4SEEK
		fd->fd_me = 0;
#endif	CPM1p4SEEK
	}
	return fd;
}

chmod(filename, mode)
 char *filename;
 unsigned mode;
{
	register FILE *fd;

	/* the only purpose of this function under CP/M is to
	 * disallow write to file "owner"
	 */
#ifdef	CPM1p4
	if((mode&0200) || cpmver()==0)
		return SUCCESS;
#endif	CPM1p4

	if((fd = fillfcb(filename)) == ERROR)
		return ERROR;

	switch(fd->fd_dc)
	{
#ifdef SERIAL
	case RDR:
	case CON:
	case LST:
	case PUN:
		break;
#endif SERIAL
	default:
		fd->fd_ext[0] |= 0x80;
		if(ybdos(CC_ATTRIBS,fd)==ERROR) {
			return Xseterr(NOFILE,fd);
		}
	}
	fabort(fd);
	return SUCCESS;
}

close(_fd)
 FILE	*_fd;
{
	register FILE	*fd;
	int	t;

	if(!isfd(fd = _fd))
		return SUCCESS;

	t = closeio(fd);
	free(fd);
	return t;
}

isfd(_fd)
 FILE *_fd;
{
	register FILE *fd;

	/* fd's should be linked together so that this is a
	 * algorithm instead of a heuristic.  Also so that
	 * exit can close all open fd's
	 */
	if((fd = _fd) != ERROR || fd!=NULL)
		switch(fd->fd_fm)
		{
		case 0:
		case 1:
		case 2:
		case 'R':
		case 'W':
		case 'A':
		case 'X':
			return TRUE;
		}

	return FALSE;
}

/* close fd without a free
 *	no call to isfd(fd):
 *	all callers should check
 */
static
closeio(_fd)
 FILE *_fd;
{
	register FILE *fd;
	char tmp[3];
	int t;

	fd = _fd;
#ifdef	SERIAL
	if(isserial(fd))
		t = SUCCESS;
	else
#endif	SERIAL
#ifdef	BYTEWISE
	{
		xselect(fd, tmp);
		t = xflush(fd);
		t |= zbdos(CC_CLOSE, fd);
		xrestore(fd, tmp);
	}
#else	BYTEWISE
		t = ybdos(CC_CLOSE, fd);
#endif	BYTEWISE

	ffabort(fd);
	return t;
}

fabort(fd)
 FILE	*fd;
{
	if(ffabort(fd)==ERROR)
		return ERROR;

	free(fd);
	return SUCCESS;
}

static
ffabort(_fd)
 FILE	*_fd;
{
	register FILE	*fd;

	if(!isfd(fd=_fd))
		return seterr(INVFD);

	if(fd->fd_ps)		/* free the buffered sub-field */
		free(fd->fd_ps);
#ifdef	BYTEWISE
	if(fd->fd_br)		/* free the bytewise sub-field */
		free(fd->fd_br);
#endif	BYTEWISE

	return SUCCESS;
}

isserial(_fd)
 FILE *_fd;
{
#ifdef	SERIAL
	if(!isfd(_fd))
		return seterr(INVFD);

	switch(_fd->fd_dc) {
	case NUL:
	case CON:
	case RDR:
	case LST:
	case PUN:
		return 1;
	}
#endif	SERIAL
	return 0;
}

isatty(fd)
 FILE *fd;
{
	return isfd(fd) && fd->fd_dc==CON;
}

unsigned cio();

/* currently does not check isfd(fd) */
read(_fd, buffer, byte_count)
 FILE *_fd;
 char *buffer;
 unsigned  byte_count;
{
	register FILE	*fd;

	switch((fd = _fd)->fd_fm) {
	case FCB_READ:
	case FCB_R_W:
	case 'R':
	case 'X':
		return cio(CC_READ, fd, buffer, byte_count);
	}
	return seterr(INVMODE);
}

/* currently does not check isfd(fd) */
write(_fd, buffer, byte_count)
 FILE *_fd;
 char *buffer;
 unsigned byte_count;
{
	register FILE	*fd;

	switch((fd = _fd)->fd_fm)
	{
	case FCB_WRITE:
	case FCB_R_W:
	case 'W':
	case 'A':
	case 'X':
		return cio(CC_WRITE, fd, buffer, byte_count);
	}
	return seterr(INVMODE);
}

static
unsigned
cio(mode, _fd, buffer, byte_count)
 FILE *_fd;
 char	mode, *buffer;
 unsigned byte_count;
{
	register FILE	*fd;
	unsigned bytes;
	int	bc;
	char	tmp[3];

	fd = _fd;
#ifdef SERIAL
	switch(fd->fd_dc) {
	case NUL:
		return (mode == CC_READ) ? 0 : byte_count;
	case CON:
		if(mode == CC_READ) {
			*buffer = bdos0(CC_CONIN);
			return 1;
		}
		return serialout(CC_CONOUT, buffer, byte_count);
	case RDR:
		*buffer = bdos0(CC_RDR);
		return 1;
	case LST:
		return serialout(CC_LST, buffer, byte_count);
	case PUN:
		return serialout(CC_PUN, buffer, byte_count);
	}
#endif	SERIAL
	xselect(fd, tmp);
#ifdef	BYTEWISE
	for(bytes = 0; byte_count; ) {
		if((bc = byte_count > (bc = RS - fd->fd_rbyt)
		   ? bc : byte_count) != RS) {
			if(mode == CC_WRITE) {
				if(xfill(fd, CC_WRITE) == ERROR)
					break;
				movmem(buffer, &fd->fd_br[fd->fd_rbyt], bc);
				fd->fd_st |= FS_DIRTY;
			} else {
				if(xfill(fd, CC_READ) == ERROR)
					break;
				movmem(&fd->fd_br[fd->fd_rbyt], buffer, bc);
			}
		} else {
			if(xflush(fd) == ERROR)
				break;
			fd->fd_st &= ~FS_VALID;
			if(xbio(mode, fd, buffer) == ERROR)
				break;
		}
		buffer += bc;
		bytes += bc;
		byte_count -= bc;
		if((fd->fd_rbyt += bc) >= RS) {
			++fd->fd_rrec;
			fd->fd_rbyt = 0;
		}
	}
#else	BYTEWISE
	bc = byte_count/RS + (byte_count%RS && mode == CC_WRITE);
	for(bytes = 0; bc--; ) {
		if(xbio(mode, fd, buffer) == ERROR)
			break;
		buffer += RS;
		bytes += RS;
#ifdef	RANDIO
		++fd->fd_rrec;
#endif	RANDIO
	}
#endif	BYTEWISE
	xrestore(fd, tmp);
	return bytes;
}

static
xfill(_fd, mode)
 FILE *_fd;
 int mode;
{
#ifdef	BYTEWISE
	register FILE	*fd;

	fd = _fd;
	if(!(fd->fd_st & FS_VALID) || (fd->fd_rrec != fd->fd_brec)) {
		if(!fd->fd_br)
			if(!(fd->fd_br = malloc(RS)))
				return seterr(NOMEM);
		if(xflush(fd) == ERROR)
			return ERROR;
		fd->fd_st &= ~FS_VALID;
		fd->fd_brec = fd->fd_rrec;
		if(xbio(CC_READ, fd, fd->fd_br) == ERROR && mode == CC_READ)
			return ERROR;
		fd->fd_st |= FS_VALID;
	}
	return SUCCESS;
#endif	BYTEWISE
}

static
xflush(_fd)
 FILE *_fd;
{
#ifdef	BYTEWISE
	register FILE	*fd;
	unsigned trec;
	int t;

	if((fd = _fd)->fd_st & FS_DIRTY) {
		trec = fd->fd_rrec;
		fd->fd_rrec = fd->fd_brec;
		if((t = xbio(CC_WRITE, fd, fd->fd_br)) != ERROR)
			fd->fd_st &= ~FS_DIRTY;
		fd->fd_rrec = trec;
		return t;
	}
	return SUCCESS;
#endif	BYTEWISE
}

static
xbio(mode, _fd, buf)
 int mode;
 FILE *_fd;
 char *buf;
{
	register FILE *fd;
#ifdef	CPM1p4SEEK
	int t1;
#endif	CPM1p4SEEK

	fd = _fd;
#ifdef	RANDIO
#ifdef	CPM1p4
	if(cpmver() == 0) {
		if(fd->fd_ex !=  fd->fd_rrec/EXT_SIZE) {
			xclose(fd);
			fd->fd_ex = fd->fd_rrec/EXT_SIZE;
			if(zbdos(CC_OPEN, fd) == ERROR) {
				if(mode != CC_WRITE
				   || zbdos(CC_CREAT, fd) == ERROR)
					return ERROR;
			}
		}
		fd->fd_nr = fd->fd_rrec%EXT_SIZE;
	} else
#endif	CPM1p4
	{
		mode += 13;
	}
#endif	RANDIO
	xsetdma(buf);
#ifdef	CPM1p4SEEK
	t1 = bdos(mode, fd) == 0? SUCCESS: seterr(0x200+mode);
	if(fd->fd_ex > fd->fd_me)
		fd->fd_me = fd->fd_ex;
	return t1;
#else	CPM1p4SEEK
	return bdos(mode, fd) == 0? SUCCESS: seterr(0x200+mode);
#endif	CPM1p4SEEK
}

static
unsigned
serialout(dev, bp, byte_count)
 char	dev, *bp;
 int	byte_count;
{
#ifdef SERIAL
	register unsigned bytes;

	for(bytes = 0; ++bytes <= byte_count; )
		bdos(dev, *bp++);
	return bytes-1;
#endif	SERIAL
}

static
cmpu(a0, b)
 char *a0, *b;
{
#ifdef	SERIAL
	register char *a;

	for(a = a0; *a; ++a)
		if(*a != toupper(*b++))
			return 0;
	return 1;
#endif	SERIAL
}

/*	This function predates structures. It should be modified to access
 *	file descriptors by member names, yet, as it works properly, we shall
 *	let it kludge along a little longer.
 */
static
fspec(fps, fcb)		/* parse fspec. if valid return SUCCESS and set up */
 char *fps, *fcb;	/* low 16 bytes of fcb, else return false.device*/
			/* codes CON..NUL reserved for serial devices.	*/
{
	register char *fp;
	FILE *xfcb;
	int c;

	if(*(fp = fps) == 0)
		return seterr(FSPECERR);

	xfcb = fcb;
	if((*fcb = chkserial(fp)) == 0) {
		if(fp[1] == ':' || fp[1] == '/') {
			if((*fcb = toupper(*fp++) - '@') > MAX_DRIVE)
				return seterr(FSPECERR);
		} else
			*fcb = 0;

		if(*fp == '/') {
			for(++fp, c = 0; isdigit(*fp); )
				c = (10 * c) + *fp++ - '0';

			if(c > MAX_USER || *fp != ':')
				return seterr(FSPECERR);

			xfcb->fd_user = c;
		}
		else
			xfcb->fd_user = DEF_USER;

		if(*fp == ':')
			++fp;
	}

	setmem(++fcb, 8 + 3, ' ');
	for(c = 0; ; ) {
		if(*fp == '.') {
			++fp;
			/* already started the ext? */
			if(fcb > xfcb->fd_ext)
				return seterr(FSPECERR);
			fcb = xfcb->fd_ext;
			c = 5;
		}
		*fcb++ = toupper(*fp++);
		if(*fp == '\0')
			break;
		if(++c > 8)
			return seterr(FSPECERR);
	}
	return SUCCESS;
}

static
chkserial(_fp)
 char *_fp;
{
#ifdef SERIAL
	register char *fp;

	if(cmpu("CON:", (fp = _fp)))	return CON;
	else if(cmpu("RDR:", fp))	return RDR;
	else if(cmpu("LST:", fp))	return LST;
	else if(cmpu("PUN:", fp))	return PUN;
	else if(cmpu("NUL:", fp))	return NUL;
	else
#endif	SERIAL
					return 0;
}

static
fillfcb(filename)
 char	*filename;
{
	register FILE	*fd;

	if((fd = malloc(SIZE_FD))==NULL)
		return seterr(NOMEM);

	setmem(fd, SIZE_FD, 0);
#ifdef	CPM1p4SEEK
	fd->fd_me = 255;
#endif	CPM1p4SEEK
	if(fspec(filename, fd)==ERROR) {
		free(fd);
		return ERROR;
	}
	return fd;
}
/* functions between ==== are machine dependent */
/* functions between ++++ are machine independent in the
 * sense that the source does not have to be altered for a
 * new machine--note that the operation of some of these
 * functions will still vary depending upon the machine,
 * however this variance is in some accepted way
 */

FILE *
fopen(filename, mode, buffer_size)
 char	*filename, *mode;
 unsigned buffer_size;
{
	register FILE	*fd;

	switch(toupper(*mode)) {
	case 'R':
		if((fd = open(filename, FCB_READ)) != ERROR)
			break;
		if(toupper(mode[1]) != 'W')
			return NULL;
	case 'W':
		if((fd = creat(filename, 0)) == ERROR)
			return NULL;
		break;
#ifdef APPENDMODE
	case 'A':
		if((fd = open(filename, FCB_WRITE)) == ERROR
		 || (fd = creat(filename, ~0))==ERROR) {
			close(fd);
			return NULL;
		}
		{
#ifdef	SEEK
			seek(fd, 0, LAST);
#else	SEEK
			char buf[RS];
			while(read(fd, buf, sizeof buf) > 0)
				;
#endif	SEEK
		}
		break;
#endif	APPENDMODE
	default:
		seterr(INVMODE);
		return NULL;
	}

	return fdopen(fd, mode, buffer_size);
}

/* fdopen destroys the old fd.  Is this ok? */
fdopen(fd, mode, buffer_size)
 FILE *fd;
 char *mode;
 unsigned buffer_size;
{
	register struct seq_buf *p;

	if(ffabort(fd)==ERROR)
		return NULL;

#ifdef	BYTEWISE
	if(buffer_size < 1)
		buffer_size = 1;
#else	BYTEWISE
	if(buffer_size < RS)
		buffer_size = RS;
#endif	BYTEWISE

	if( !(p = fd->fd_ps = malloc(buffer_size + SIZE_SB)) ) {
		close(fd);
		seterr(NOMEM);
		return NULL;
	}

	p->ap = &p->bu;
	p->ac = 0;
	p->bs = buffer_size;

	switch(fd->fd_fm = toupper(*mode)) {
	case 'A':
	case 'W':
		break;
	default:
		fd->fd_fm = toupper(mode[1]) == 'W'? 'X': 'R';
	}
	return fd;
}

freopen(filename, mode, fd, buf_size)
 char *filename;
 char *mode;
 unsigned buf_size;
 FILE *fd;
{
	register FILE *fd1;

	if(!isfd(fd) || closeio(fd)==ERROR)
		return NULL;

	if((fd1=fopen(filename, mode, buf_size))==NULL) {
		free(fd);
		return NULL;
	}

	/* substitute contents of fd1 for fd */
	movmem(fd1, fd, SIZE_FD);	/* sizeof FILE */
	free(fd1);

	return fd;
}

fclose(_fd)
 FILE	*_fd;
{
	register FILE	*fd;
	int stat;

	if(!isfd(fd = _fd))
		return seterr(INVFD);

	stat = 0;
	if(fd->fd_fm != 'R' && fd->fd_fm != FCB_READ) {
#ifdef	_EOF
		if(putc(_EOF,fd) == ERROR)
			stat = ERROR;
#endif	_EOF
		stat |= fflush(fd);

	}
	return close(fd) | stat;
}

/* currently does not check isfd(fd) */
getc(fd)
 FILE *fd;
{
	register struct seq_buf	*p;

	switch(fd->fd_fm) {
	case 'R':
	case 'X':
		p = fd->fd_ps;
		if(p->ac <= 0)
		{
			if((p->ac = read(fd, &p->bu, p->bs)) <= 0)
				return seterr(EOFERR);

			p->ap = &p->bu;
		}
		--(p->ac);
		return *p->ap++;
	}
	return seterr(INVFD);
}

fgetc(fd)
 FILE *fd;
{
	return getc(fd);
}

/* currently does not check isfd(fd) */
ungetc(c, fd)
 char	c;
 FILE *fd;
{
	register struct seq_buf	*p;

	switch(fd->fd_fm) {
	case 'R':
	case 'X':
		p = fd->fd_ps;
		++(p->ac);
		return *--(p->ap) = c;
	}
	return seterr(INVFD);
}

/* currently does not check isfd(fd) */
putc(c, fd)
 char	c;
 FILE *fd;
{
	register struct seq_buf *p;

	switch(fd->fd_fm) {
	case 'X':
	case 'W':
	case 'A':
		p = fd->fd_ps;
		if(p->ac >= p->bs && bufwrite(fd) == ERROR)
			return ERROR;
		++(p->ac);
		return *p->ap++ = c;
	}
	return seterr(INVFD);
}

/* currently does not check isfd(fd) */
fputc(c, fd)
 char c;
 FILE *fd;
{
	return putc(c, fd);
}

/* currently does not check isfd(fd) */
fflush(_fd)
 FILE	*_fd;
{
	register FILE	*fd;

	switch((fd = _fd)->fd_fm) {
	case 'X':
	case 'W':
	case 'A':
		return bufwrite(fd);
	case 'R':
		fd->fd_ps->ac = 0;
		return SUCCESS;
	}
	return seterr(INVFD);
}

/* machine independent */
/* currently does not check isfd(fd) */
static
bufwrite(fd)
 FILE	*fd;
{
	register struct seq_buf	*p;

	p = fd->fd_ps;
	/*
	 * test for write() < p->ac because
	 * sometimes CP/M write outputs extra bytes
	 * if the request is not a multiple of RS
	 */
	if(write(fd, &p->bu, p->ac) < p->ac)
		return ERROR;

	p->ap = &p->bu;
	p->ac = 0;
	return SUCCESS;
}

static
seterr(err)
 int err;
{
	errno = err;
	return ERROR;
}

/* really put two bytes out, machine independently */
/* currently does not check isfd(fd) */
put2b(i, fd)
 int	i, fd;
{
	if(putc((i>>8)&0xff, fd) == ERROR || putc(i, fd) == ERROR)
		return ERROR;
	return i;
}

/* currently does not check isfd(fd) */
putw(i, fd)
 int	i, fd;
{
	return fwrite(&i, sizeof i, 1, fd);
}

/* currently does not check isfd(fd) */
get2b(fd)
 FILE	*fd;
{
	register int r1;
	int r2;

	if((r1 = getc(fd)) == ERROR ||
	   (r2 = getc(fd)) == ERROR)
		return ERROR;
	return (r1<<8) | (r2&0xff);
}

/* currently does not check isfd(fd) */
getw(fd)
 FILE *fd;
{
	int i;

	i = 0;
	if(fread(&i, sizeof i, 1, fd)==0)
		return ERROR;
	return i;
}

/* machine independent if you assume byte order is ok */
/* currently does not check isfd(fd) */
fwrite(buf, sizeofitem, nitems, fd)
 char *buf;
 unsigned sizeofitem;
 unsigned nitems;
 FILE *fd;
{
	register unsigned s;
	unsigned n;

	for(n = nitems; n; --n)
		for(s = sizeofitem; s; --s)
			if(putc(*buf++, fd) == ERROR)
				break;

	return nitems-n;
}

/* machine independent if you assume byte order is ok */
/* currently does not check isfd(fd) */
fread(buf, sizeofitem, nitems, fd)
 char *buf;
 unsigned sizeofitem;
 unsigned nitems;
 FILE *fd;
{
	register unsigned s;
	unsigned n;
	int i;

	for(n = nitems; n; --n)
		for(s = sizeofitem; s; --s) {
			if((i = getc(fd)) == ERROR)
				break;
			*buf++ = i;
		}

	return nitems-n;
}

/* machine independent, note: pputc!=putc */
/* currently does not check isfd(fd) */
fputs(s, stream)
 char *s;
 FILE *stream;
{
	register char *ss;

	for(ss=s; *ss; ++ss)
		if(pputc(*ss, stream)==ERROR)
			return ERROR;
	return ss-s;
}

/* machine independent, note: pgetc!=putc */
/* currently does not check isfd(fd) */
fgets(s, n, fd)
 char *s;
 unsigned n;
 FILE *fd;
{
	register char *cs;
	int c;

	for(cs=s; --n; ++cs) {
		switch(c = pgetc(fd)) {
#ifdef _EOF
		 case _EOF:
			ungetc(c, fd) ;
#endif
		 case ERROR:
			*cs = '\0';
			if(*s != '\0')
				return s;
			return NULL;
		 case '\n':
			*cs = '\0';
			return s;
		 default:
			*cs = c;
		}
	}
	*cs = '\0';
	return s;
}

/* machine independent */
/* currently does not check isfd(fd) */
ferror(fd)
 FILE *fd;
{
	return errno!=0;
}

/* machine independent */
/* currently does not check isfd(fd) */
clearerr(fd)
 FILE *fd;
{
	errno = 0;
}

/* machine independent */
fileno(fd)
 FILE *fd;
{
	if(!isfd(fd))
		return NULL;
	return fd;
}

mktemp(f)
 char *f;
{
	register char *p;

	if((p=substr("X", f))==NULL)
		p = f+strlen(f);

	for(p[0] = p[1] = '0';;) {
		if(++(p[1]) == '9'+1) {
			if(++(p[0])=='9'+1)
				return NULL;
			p[1] = '0';
		}
		if(access(f,0)==ERROR)
			return f;
	}
}
/* end of machine independent functions +++++ */

static
xselect(_fd, tmp)	/* preserve user and drive code, and select	*/
 FILE *_fd;		/* user & drive specified in fd			*/
 char *tmp;
{
	register FILE	*fd;

	fd = _fd;
#ifdef	CPM1p4
	if(cpmver() == 0) {
		tmp[0] = bdos0(GET_DRIVE);
		bdos(SET_DRIVE, (tmp[1] = fd->fd_dc)? fd->fd_dc-1: tmp[0]);

		fd->fd_dc = 0;
		fd->fd_user = 0;
	} else
#endif	CPM1p4
	{
		if(fd->fd_user != DEF_USER) {
			tmp[2] = bdos(CC_USER, 255);
			bdos(CC_USER, fd->fd_user);
		}
	}
}

static
xrestore(_fd, tmp)
 FILE *_fd;
 char *tmp;
{
	register FILE	*fd;

	fd = _fd;
#ifdef	CPM1p4
	if(cpmver() == 0) {
		fd->fd_dc = tmp[1];
		bdos(SET_DRIVE, tmp[0]);
	} else
#endif	CPM1p4
	{
		if(fd->fd_user != DEF_USER)
			bdos(CC_USER, tmp[2]);
	}
}

static
bdos0(fn)
 int fn;
{
	return bdos(fn, 0);
}

static
xbdos(fn, _fd)
 int fn;
 FILE *_fd;
{
	register FILE	*fd;
	int	t;
	char	tmp[3];

	xselect((fd = _fd), tmp);
	t = bdos(fn, fd);
	xrestore(fd, tmp);
	return t;
}

static
ybdos(fn, fd)
 int fn;
 FILE *fd;
{
	return xbdos(fn, fd) != BDOSERR? SUCCESS: seterr(0x200+fn);
}

static
zbdos(fn, fd)
 int fn;
 FILE *fd;
{
	return bdos(fn, fd) != BDOSERR? SUCCESS: seterr(0x200+fn);
}

static
xsetdma(buf)
 char *buf;
{
	bdos(SET_DMA, buf);
}

seek(_fd, off, code)
 FILE *_fd;
 int off, code;
{
#ifdef	SEEK
	register FILE *fd;
	unsigned uoff;
	int rbyt;

	if(isserial(fd = _fd))
		return 0;

	uoff = off;
	switch(code) {
	 case START:
		fd->fd_rrec = uoff/RS;
		rbyt = uoff%RS;
		break;
	 case CURRENT:
		fd->fd_rrec += off/RS;
		rbyt = fd->fd_rbyt + off%RS;
		break;
	 case LAST:
		fd->fd_rrec = xsize(fd) + off/RS;
		rbyt = off%RS;
		break;
	 case START+3:
		fd->fd_rrec = uoff*(512/RS);
		rbyt = 0;
		break;
	 case CURRENT+3:
		fd->fd_rrec += off*(512/RS);
		rbyt = fd->fd_rbyt;
		break;
	 case LAST+3:
		fd->fd_rrec = xsize(fd) + off*(512/RS);
		rbyt = 0;
		break;
	 default:
		return seterr(INVSEEK);
	}
#ifdef	BYTEWISE
	if(rbyt < 0) {
		--fd->fd_rrec;
		rbyt += RS;
	} else if(rbyt >= RS) {
		++fd->fd_rrec;
		rbyt -= RS;
	}
	fd->fd_rbyt = rbyt;
#else	BYTEWISE
	if(rbyt)
		return seterr(INVREC);
#endif	BYTEWISE
	return SUCCESS;
#endif	SEEK
}

unsigned
tell(_fd)		/* tell returns bytes. */
 FILE *_fd;
{
#ifdef	SEEK
	register FILE	*fd;

	fd = _fd;
	return fd->fd_rrec * 128 + fd->fd_rbyt;
#endif	SEEK
}

unsigned
rtell(_fd)		/* tell returns bytes / 512. */
 FILE *_fd;
{
#ifdef	SEEK
	return _fd->fd_rrec >> 2;
#endif	SEEK
}

unsigned
otell(_fd)		/* otell returns bytes % 512 */
 FILE *_fd;
{
#ifdef	SEEK
	register FILE	*fd;

	fd = _fd;
	return (fd->fd_rrec % 4) * 128 + fd->fd_rbyt;
#endif	SEEK
}

static
unsigned
xsize(_fd)
 FILE *_fd;
{
#ifdef	SEEK
	register FILE	*fd;
	FILE	tfd;
	char	tmp[3];

	xselect((fd = _fd), tmp);
#ifdef	BYTEWISE
	xflush(fd);
#endif	BYTEWISE
	movmem(_fd, (fd = &tfd), SIZE_FD);
#ifdef	CPM1p4
	if(cpmver() == 0) {
		if(fd->fd_me != fd->fd_ex) {
			xclose(fd);
			for(fd->fd_ex = fd->fd_me & 0x0f
			   ; bdos(CC_OPEN, fd) == BDOSERR
			   ; --fd->fd_ex) ;
			_fd->fd_me = fd->fd_ex;
		}
		fd->fd_rrec = fd->fd_ex * EXT_SIZE + fd->fd_rc;
	} else
#endif	CPM1p4
	{
		xclose(fd);
		bdos(CC_CFS, fd);
	}
	xrestore(_fd, tmp);
	return fd->fd_rrec;
#endif	SEEK
}

static
xclose(_fd)
 FILE	*_fd;
{
#ifdef	SEEK
	register FILE	*fd;

	xsetdma(INIT_DMA);
	bdos(CC_CLOSE, (fd = _fd));
	setmem(&fd->fd__fcbr1, &fd->fd_rrec - &fd->fd__fcbr1, 0);
#endif	SEEK
}

/* machine independent */
exec(p)
 char *p;
{
#ifdef	EXEC
	int execl(.);

	return execl(p, 0);
#endif	EXEC
}

#ifdef	CPM86

/*
 * These two functions should work under cpm-86 version 1.1.
 * However they have not been tested since we haven't recieved
 * our upgrade to 1.1 yet.
 */


#define EXECAREA	(0x0080)
#define EXEC_PROG	47

/* execl(progname, arg0, arg1, ... ) -- arg0 is ignored because of cp/m bug */

execl(nargs)	/* set up command line */
 int nargs;	/* then exec */
{
#ifdef	EXEC
	register char *l, *p;
	int *ip;

	if(nargs > 0) {
		ip = &nargs;
		/* construct progname line */
		for(p = ip[nargs]; *p; )
			*l++ = toupper(*p++);

		*l++ = ' ';

		--nargs;	/* skip over arg0, because of cp/m bug */

		/* construct command line */
		for(l = EXECAREA; --nargs>0; ) {
			if(nargs!=1) {	/* arg0 is ignored */
				for(p = ip[nargs]; *p; )
					*l++ = toupper(*p++);

				*l++ = ' ';
			}
		}
		*l = 0;

		xsetdma(EXECAREA);
		bdos0(EXEC_PROG);
	}

	return seterr(ENOEXEC);
#endif	EXEC
}
#else	CPM86

#define FCB_SIZE	33
#define EXECAREA	(0x0080)
#define DEF_FCB		0x005c

/* execl(progname, arg0, arg1, ... ) -- arg0 is ignored because of cp/m bug */

execl(nargs)	/* set up command line & default fcb just like cpm */
 int nargs;	/* then exec */
{
#ifdef	EXEC
	register int *ip;
	char *c, *l, *p, prog[30], hld80[128], tmp[3];
	FILE fcb;
	FILE *fd, *fd1;
	int (*fn)();	/* a coersion would be better */
	extern char xstart[], xfcb1[], xfcb2[], xend[];

	if(nargs < 1)
		return seterr(ENOEXEC);

	ip = &nargs;
	strcpy(prog, ip[nargs]);		/* get program name */
	/* if explicit extension missing, use ".COM" */
	for(c = prog; ; ++c)
	{
		switch(*c) {
		case 0:
			strcpy(c, ".COM");
			break;
		case '.':
			break;
		default:
			continue;
		}
		break;
	}

	/* Construct default fcb at DEF_FCB from args 3 & 4 */
	setmem(DEF_FCB, FCB_SIZE, 0);

	/* --nargs because arg0 can't exist: bug in cp/m */
	if(--nargs > 2) {
		fspec(ip[nargs - 1], &fcb);
		movmem(&fcb, DEF_FCB, 12);
		if(nargs > 3) {
			fspec(ip[nargs - 2], &fcb);
			movmem(fcb.fd_name, DEF_FCB + 16, 11);
		}
		else
			setmem(DEF_FCB + 16, 11, ' ');
	}

	/* construct command line */
	for(l = hld80 + 1; --nargs > 1; ) {
		for(p = ip[nargs]; *l++ = *p++; )
			;
		*l++ = ' ';
	}
	*--l = 0;
	hld80[0] = l-hld80-2;


	if(chkserial(prog) || (fd1 = open(prog, 0)) == ERROR)
		return seterr(OPENERR);


	/* we endup with default drive and user specified by prog */
	xselect(fd1, tmp);
	if(hld80[0] != 0)	/* any args? */
	{
		if((fd = creat("$.$", 0)) == ERROR
		 || write(fd, hld80, sizeof hld80) != sizeof hld80
		 || seek(fd, 0, 0) == ERROR)
			return Xseterr(ENOSPC,fd);

		movmem(fd, xfcb2, FCB_SIZE);
	} else {
		setmem(xfcb2, FCB_SIZE, 0);
	}

	movmem(xstart, EXECAREA, xend-xstart);
	movmem(fd1, xfcb1, FCB_SIZE);

	(*(fn = EXECAREA))();
#endif	EXEC
}
#endif	CPM86

/*
 * rarely used buffered i/o routines
 */

#ifdef	DEBUG
dumpfcb(_fd)	/* This routine dumps a fd for debugging purposes */
 FILE	*_fd;
{
	register FILE	*fd;
	int i;

	printf("fcb @%x:\n", (fd = _fd));
	printf("dc %x\n", fd->fd_dc);
	puts("name.fd_ext : ");
	for(i = 0; i < 8; ++i)
		putchar(fd->fd_name[i]);
	putchar('.');
	for(i = 0; i < 3; ++i)
		putchar(fd->fd_ext[i]);
	putchar('\n');
	printf("ex %x\n", fd->fd_ex);
	printf("rc %x\n", fd->fd_rc);
	printf("nr %x\n", fd->fd_nr);
	printf("rrec %x\n", fd->fd_rrec);
	printf("rbyt %x\n", fd->fd_rbyt);
	printf("brec %x\n", fd->fd_brec);
	printf("user %x\n", fd->fd_user);
	printf("fm %x\n", fd->fd_fm);
#ifdef	CPM1p4SEEK
	printf("me %x\n", fd->fd_me);
#endif	CPM1p4SEEK
	printf("st %x\n", fd->fd_st);
	printf("ps %x\n", fd->fd_ps);
}
#endif	DEBUG

/* currently does not check isfd(fd) */
pgetc(fd)
 FILE	*fd;
{
	register char	c;

	if((c = getc(fd)) == '\r')
		if((c = getc(fd)) != '\n') {
			ungetc(c, fd);
			c = '\r';
		}
	return c;
}

/* currently does not check isfd(fd) */
pputc(c, fd)
 char	c;
 FILE	*fd;
{
	if(c == '\n')
		if(putc('\r', fd) == ERROR)
			return ERROR;
	return putc(c, fd);
}

/* Not strictly compatible with unix, except in the following sense:
 * under unix, a rename(f2, f1) would be link(f1, f2) unlink(f1).
 * This would work given link as below.
 * It is actually possible to simulate link
 * under CP/M, except that only open files would have their fcbs updated,
 * unopened links would have old file info in it.
 */
link(f1, f2)
 char *f1, *f2;
{
	return rename(f1, f2);
}

rename(f_new, f_old)
 char *f_new;
 char *f_old;
{
	register struct filedesc *new;
	struct filedesc *old;
	int i;

	if((old=fillfcb(f_old)) == ERROR )
		return ERROR;

	if((new=fillfcb(f_new)) == ERROR ) {
		fabort(old);
		return ERROR;
	}

	if(new->fd_dc != old->fd_dc || new->fd_user != old->fd_user) {
		i = seterr(ERLINK);
	} else {
						/* sizeof something */
		movmem(&new->fd_dc, &old->fd__fcbr2[0], 16);
		i = ybdos(CC_RENAME, old);
	}

	fabort(new);
	fabort(old);
	return i;
}

unlink(filename)
 char	*filename;
{
	register FILE *fd;
	int i;

	if((fd = fillfcb(filename)) == ERROR)
		return ERROR;

	if(isserial(fd))
		return Xseterr(BADDEV,fd);

	i = ybdos(CC_DELETE, fd);
	fabort(fd);
	return i;
}

/* machine dependent--a no-op under cp/m or mp/m */
lock(flag)
 int flag;
{
}

/* machine dependent--a no-op under cp/m or mp/m */
nice(incr)
 int incr;
{
}


/* machine dependent--a no-op under cp/m or mp/m */
wait(status)
 int status;
{
	return ERROR;
}

access(f, mode)
 char *f;
 unsigned mode;
{
	register unsigned m;
	FILE *i;

	if(mode&1)
		mode |= 4;	/* execute, under CP/M, implies read */

	/* set read/write bits */
	/* exists (mode==0), under CP/M, means read */

	if((i=open(f, mode? (((mode>>1)&3)-1): 0)) == ERROR)
		return ERROR;

	if((mode&1) && usubstr(f,".com")==NULL)	/* execute */
		return ERROR;

	return close(i);
}

Xseterr(eno,fd)
 int eno;
 FILE *fd;
{
	fabort(fd);
	return seterr(eno);
}

	return i;
}

unlink(filename)
 char	*filename;