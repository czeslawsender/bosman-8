/* crunt2.c	commonly used functions written in C.
 *
 *	MQH 2/82
 *
 * This file contains runtime support functions not written in
 * assembly language.
 * This file should be included or linked into most programs, as
 * it eliminates most dependencies between other files in the package.
 *
 *	mqh 7/28 movmem() edited
 *	For C 1.2.0
 */

#include	"customiz.h"
#include	"stdio.h"


strlen(s)
 char *s;
{
	register char *x;

	for(x=s;*x++;);
	return x-s-1;
}

isalpha(c)
 char c;
{
	register char cc;

	return isupper(cc=c) || islower(cc);
}

isupper(c)
 char c;
{
	register char cc;

	return (cc = c) >= 'A' && cc <= 'Z';
}

islower(c)
 char c;
{
	register char cc;

	return (cc = c) >= 'a' && cc <= 'z';
}

isdigit(c)
 char c;
{
	register char cc;

	return (cc = c) >='0' && cc <= '9';
}

iswhite(c)
 char	c;
{
	switch(c)
	{
	case ' ':
	case '\t':
	case '\r':
	case '\n':
	case '\f':
		return TRUE;
	default:
		return FALSE;
	}
}

toupper(c)
 char	c;
{
	register char cc;

	if((cc = c) >= 'a' && cc <= 'z')
		return cc - ' ';
	return cc;
}

puts(s)
 char *s;
{
	register char *ss;

	for(ss=s; *ss; )
		putchar(*ss++);

	return s;
}

gets(line)
 char *line;
{
	register char *p;
	char *temp;
	char c;

	for(p = line; ; ) {
		switch(c=getchar()) {
		 case 'Z'-'@':
			if(p == line) {
				*p = 0;
				return NULL;
			}
		 case '\n':
		 case '\r':
			*p = 0;
			return line;
		 case 'G'-'@':
			*p = 0;
			return ERROR;
		 case 'U'-'@':
		 case 'X'-'@':
			putchar('\n');
			p = line;
			break;
		 case 0x7f:
			if(p == line)
				break;
			putchar('\b');
		 case '\b':
			putchar(' ');
			if(p != line) {
				putchar('\b');
				--p;
			}
			break;
		 case 'R'-'@':
			putchar('\n');
			for(temp = p, p = line; p < temp; )
				putchar(*p++);
			break;
		 default:
			*p++ = c;
			break;
		}
	}
}

#ifdef	REDIRECT
cput(c)
 char c;
{
	if(stdout)
		putc(c, stdout);
	else
		cconout(c);
}
#else	REDIRECT
cput(){}
#define cput	cconout
#endif	REDIRECT

putchar(c)
 char c;
{
	if(c=='\n')
		cput('\r');

	cput(c);
}

char *ccugot;			/* points to ungotten character */

getchar()
{
	register int c;

	ccugot = "";		/* *ccugot is static, initialized to 0 */
	if(*ccugot) {
		c = *ccugot;
		*ccugot = 0;
#ifdef	REDIRECT
	} else if(stdin) {
		c = getc(stdin);
#endif	REDIRECT
	} else
		c = cconin();

	switch(c) {
	case '\r':
		cconout(c = '\n');
		break;
#ifdef _EOF
	case _EOF:
		c = -1;
		break;
	}
#endif
	return c;
}

/*
 * Note: Some linkage editors only use six chars of a symbol. Therefore
 *	ungetchar() is now ugetchar().
 *	Stdio.h contains a #define ungetchar	ugetchar
 */

ugetchar(c)
 char c;
{
	*ccugot = c;
}

movmem(source,dest,count)
 char *dest,*source;
 int count;
{
	register char *d;	/* trashed by ccld.r() */

	if((d = dest) == source || count == 0)
		return d;

	if(d < source)
		ccldir(d, source, count);
	else
		cclddr(d+count-1, source+count-1, count);

	return dest+count;	/* dest instead of d because 8080 ccld.r()
				 * trashes the register variable
				 */
}

char *
setmem(dest,count,byte)
 char *dest;
 int count;
 char byte;
{
	register char *d;	/* trashed by ccldir() */

	if(count) {
		*(d = dest) = byte;
		ccldir(d+1, d, count-1);
	}
	return dest;	/* ..rather than d */
}

xmain()
{
	char **gargv;

	exit(main(loadargs(&gargv), gargv));
}

loadargs(argv)	/* set up argv and argc for C program */
 char **argv;
{
	register int argl;
	char *tmp[64];

	tmp[0] = "";
	argl = tmp;
	argl = loadline(&tmp[1], &tmp[65]
			, comline(), comline()+comlen()) - argl;
	movmem(tmp, *argv = evnbrk(argl), argl) ;
	return argl/sizeof(*argv);
}

loadline(_app, npp, lcp, ncp)
 char **_app, **npp;
 char *lcp, *ncp;
{
	register char **app;
#ifdef	REDIRECT
	FILE *fd;
	char line[128];
#endif	REDIRECT

	for(app = _app; app < npp && (*app = nextarg(&lcp, ncp)); ) {
		switch(**app) {
#ifdef	REDIRECT
		 case '@':		/* command line indirection	*/
			if(!(fd = fopen(*app+1, "r", 128)))
				break;
			while(fgets(line, sizeof(line), fd))
				app = loadline(app, npp, line
						,line+strlen(line)) ;
			fclose(fd);
			break;
		 case '<':		/* input redirection 		*/
			stdin = fopen(*app+1, "r", 128);
			break;
		 case '>':		/* output redirection 		*/
			stdout = fopen(*app+1, "w", 128);
			break;
#endif	REDIRECT
		 default:
			++app;
		}
	}
	return app;
}

nextarg(p2,com_end)
 char **p2;
 char *com_end;
{
	register char *p;
	char *q, dlmt, tmp[128];
	int count;

	for(p = *p2;; ++p) {
		if(p>=com_end)
			return 0;
		if(!iswhite(*p))
			break;
	}
	switch(*p) {
	case '\'':
	case '"':
		dlmt = *p++;	break;
	default:
		dlmt = 0;	break;
	}
	for(q=tmp, count=1
		;(dlmt ? *p != dlmt : !iswhite(*p)) && p < com_end; ++count) {
		if(*p == '\\')
			++p; /* should be more elaborate */
		*q++ = *p++;
	}
	*q = 0;
	movmem(tmp, q = sbrk(count), count);
	*p2 = p + 1;
	return q;
}

sbrk(p)
 int p;
{
	register char *save;
	extern char *ccedata;

	save = ccedata;
	/* check for overflow */
	if(save+p>save)	{
		if(p<0)
			return -1;
	} else {
		if(p>0)
			return -1;
	}

	if(brk(save+p))
		return -1;
	return save;
}

ubrk(i)		/* unlike sbrk(), ubrk() and evnbrk() want a unsigned */
 unsigned i;
{
/*
 *	Chop one possibly very large, unsigned i into two smaller
 *	positive signed values to satisfy the domain of sbrk().
 *	Note the assumption of a 16 bit word.
 *	We assume that consecutive sbrks() return contigous RAM.
 */
	register unsigned i1;
	register int j;
	register char *p;

	p = sbrk(0);
	if(!i)
		return p;

	if(sbrk(i1 = (i >> 1) & 0x7FFF) == -1)
		return -1;

	if(sbrk(i - i1) == -1) {
		j = i1;
		sbrk(-j);
		return -1;
	}
	return p;
}

wrdbrk(i)
 unsigned i;
{
#ifdef ODDOK
	return sbrk(i);
#else
	return evnbrk(i);
#endif
}

evnbrk(i)
 unsigned i;
{
	sbrk(sbrk(0)&1);
	return ubrk(i);
}

exit(i)
 int i;
{
#ifdef REDIRECT
	fclose(stdout);
	fclose(stderr);
#endif REDIRECT
	ccexit(i);
}
e = ccedata;
	/* check for overflow */
	if(save+p>save)	{
		