/* func.c	misc. machine independent functions written in C.
 *
 *		MQH 2/82
 *		RB  4/82 -- efficiency mods
 *		RB  3/20/83 -- setup for C 1.2
 *		RB  1/5/83  fixes for signed character systems
 *
 *	All of these functions are machine independent, with the exception
 *	of bios.
 */

#include	"customiz.h"
#include	"stdio.h"

#define _TRUE	(1/*1 == 1*/)
#define _FALSE	(0/*!_TRUE*/)

isalnum(c)
 char c;
{
	register char cc;

	return isalpha(cc = c) || isdigit(cc);
}

isascii(c)
 char c;
{
	return (c&0x80)==0;
}

iscntrl(c)
 char c;
{
	return (c&0xE0)==0;
}

ispunct(c)
 char c;
{
	register char cc;

	return isascii(cc = c) && !iscntrl(cc) && !isalnum(cc);
}

isprint(c)
 char c;
{
	register int cc;

	return (cc = c&0xff) >= ' ' && cc <= '~';
}

isspace(c)
 char c;
{
	switch(c) {
	case ' ':
	case '\t':
	case '\n':
		return _TRUE;
	default:
		return _FALSE;
	}
}

isnumeric(c,radix)
 char	c;
 int	radix;
{
	register char cc;

	cc = toupper(c);
	if(radix <= 10)
		return (cc >= '0' && cc <= '0' + (radix - 1));
	else
		return (cc >= '0' && cc <= '9')
		    || (cc >= 'A' && cc <= 'A' + (radix - 11));
}

tolower(c)
 char c;
{
	register char cc;

	return isupper(cc=c)? (cc + ' '): cc;
}

strncpy(d,s,n)
 char *d, *s;
 int n;
{
	register char *dd;

	for(dd = d; n--; )
		*dd++ = *s? *s++: 0;

	return d;
}

strcpy(d,s)
 char *d, *s;
{
	register char *rd;

	for(rd=d; *rd++ = *s++; )
		;

	return rd;
}

strcat(d,s)
 char *d, *s;
{
	register char *dd;

	for(dd = d; *dd++; )
		;

	for(--dd; *dd++ = *s++;)
		;

	return d;
}

strncat(d,s,n)
 char *d, *s;
 int n;
{
	register char *dd;

	for(dd = d; *dd++;)
		;

	for(--dd;;) {
		if(!n--) {
			*dd = 0;
			break;
		}
		if(!(*dd++ = *s++))
			break;
	}

	return d;
}

#ifdef STREQ		/* in assembly language on 8080			*/
streq(pattern,str)	/* Like substr, but it returns the end of string */
 char pattern[],str[];	/* instead of the beginning of string		*/
{
	register char *s;
	char *pat;

	for(pat=pattern, s=str; *pat; ) {
		if(*s++ != *pat++)
			return 0;
	}
	return s-str;
}
#endif

strcmp(s,t)
 char *s, *t;
{
	register char *ss;

	for(ss = s;;) {
		if(*ss != *t++)
			return *ss-t[-1];
		if(*ss++ == '\0')
			return 0;
	}
}

strncmp(s,t,n)
 char *s, *t;
 unsigned n;
{
	register char *ss;

	for(ss = s; --n; ) {
		if(*ss != *t++)
			return *ss-t[-1];
		if(*ss++ == '\0')
			return 0;
	}
	return *ss-*t;
}

char *
rindex(s,c)
 char *s, c;
{
	register char *ss;
	char *match;

	for(match = 0, ss = s; *ss; )
		if(*ss++==c)
			match = ss-1;

	return match;
}

/*
 *	is A a substring of B ?
 */
char *
substr(pa,pb)
 char *pa;
 char *pb;
{
	register char *a;
	char *b;
	char *saveb;

	for(a=pa, saveb=b=pb; ; ) {
		if(*a == '\0')
			return saveb;
		if(*b == '\0')
			return NULL;
		if(*a++ != *b++) {
			a = pa;
			saveb = b;
		}
	}
}

/*
 *	is A a substring of B (case irrelevent) ?
 */
char *
usubstr(pa,pb)
 char *pa;
 char *pb;
{
	register char *a;
	char *b;
	char *saveb;

	for(a=pa, saveb=b=pb; ; ) {
		if(*a == '\0')
			return saveb;
		if(*b == '\0')
			return NULL;
		if(toupper(*a++) != toupper(*b++)) {
			a = pa;
			saveb = b;
		}
	}
}

atoi(n)
 char *n;
{
	register int val; 
	char c;
	char sign;

	while(iswhite(*n++))
		;

	switch(*--n) {
	case '-':
		sign = 1;
		++n;
		break;
	case '+':
		++n;
	default:
		sign = 0;
	}

	for(val=0; isdigit(c = *n++);)
		val = val*10 + c - '0';

	return sign? -val: val;
}

#define MHZ	4
sleep(n)	/* n = xths of seconds on Z80 with speed of MHZ */
 unsigned n;
{
	register unsigned i;

	for( ; --n; )
		for(i = MHZ * 0x900; --i; )
			;
}

#ifndef	ABSVAL
abs(n)
 int	n;
{
	register int nn;

	return (nn=n) < 0? -nn: nn;
}
#endif

absval(n)	/* abs is reserved on certain 8086 assemblers */
 int	n;
{
	register int nn;

	return (nn=n) < 0? -nn: nn;
}

min(a,b)
 int a, b;
{
	return a<b? a: b;
}

max(a,b)
 int a, b;
{
	return a<b? b: a;
}

kbhit()	/* remove me.. */
{
	return cconst();	/* rename me... */
}

pause()
{
	for(;!kbhit();)
		;	
}

putdec(nn)		/* display decimal number w/out printf's overhead */
 int nn;
{
	register unsigned n;

	n = nn>=0? nn: (putchar('-'), -nn);

	if(nn = n/10)
		putdec(nn);

	putchar(n%10+'0');
}

int ccrand;

srand(seed)
 int seed;
{
	register int i;

	if(!seed) {
		puts("Wait a moment, then strike a key");
		for(;!kbhit();++i)
			;
		ccrand = i;
	}
	else
		ccrand = seed;
}

rand()
{
#define M	32749
#define A	32719
#define C	3

	return ccrand = (ccrand * A + C) % M;
}

/* the rest of these functions are not often used */

char
peek(a)
 char *a;
{
	return *a;
}

poke(a,c)
 char *a, c;
{
	*a = c;
}

initw(var,string)
 int *var;
 char *string;
{
	while(string)
		*var++ = getval(&string);
}

initb(var,string)
 char *var, *string;
{
	while(string)
		*var++ = getval(&string);
}

getval(strptr)
 int *strptr;
{
	register char *p;
	int n;

	p = *strptr;
	if(*p == 0)
		return *strptr = 0;

	for(n = 0; isdigit(*p); )
		n = n * 10 + *p++ - '0';

	while(*p && !isdigit(*p))
		++p;

	*strptr = p;
	return n;
}

qsort(base, nrecs, reclen, cmpfn)
 int nrecs, reclen;
 char *base; int (*cmpfn)();
{
	register char *jd;
	int gap, ngap, i, j;
	int t1, t2;

	t1 = nrecs*reclen;
	for(ngap = nrecs/2; ngap > 0; ngap /= 2) {
		gap = ngap*reclen;
		t2 = gap+reclen;
		jd = base+gap;
		for(i = t2; i <= t1; i += reclen)
		for(j = i-t2; j >= 0; j -= gap) {
			if ((*cmpfn)(base+j, jd+j) <=0)
				break;
			Xswp(base+j, jd+j, reclen);
		}
	}
}

static
Xswp(a, b, cnt)
 char *a, *b;
 int cnt;
{
	register char tmp;

	while(cnt--) {
		tmp = *a;
		*a++ = *b;
		*b++ = tmp;
	}
}

perror(s)
 char *s;
{
	if(*s) {
		puts(s);
		puts(": ");
	}

	switch(errno) {
	case 0:
		puts("No error");
		break;
	case BCE:
		puts("Byte count error");
		break;
	case NOFD:
		puts("No open files");
		break;
	case NOFILE:
		puts("File not found");
		break;
	case INVFD:
		puts("Invalid file (unopened file)");
		break;
	case INVMODE:
		puts("I-O type mismatch");
		break;
	case OPENERR:
		puts("Error on open");
		break;
	case CREATERR:
		puts("Error on creat");
		break;
	case FSPECERR:
		puts("Invalid filename");
		break;
	case BADDEV:
		puts("Device out of range");
		break;
	case CLOSEERR:
		puts("Error in close");
		break;
	case INVREC:
		puts("Invalid record in seek");
		break;
	case INVSEEK:
		puts("Invalid seek");
		break;
	case ENOEXEC:
		puts("Can't exec");
		break;
	case ENOSPC:
		puts("No space");
		break;
	case ERLINK:
		puts("Can't link");
		break;
	case NOMEM:
		puts("Memory allocation failure");
		break;
	case INVBUF:
		puts("Invalid buffer");
		break;
	case READERR:
		puts("Read error");
		break;
	case EOFERR:
		puts("Eof error");
		break;
	case NOGETC:
		puts("No getc");
		break;
	default:
		if(~0xff&errno) {
			puts("bdos error (");
			switch(0x1ff&errno)
			{
			case CC_READ:
				puts("read");
				break;
			case CC_WRITE:
				puts("write");
				break;
			case CC_RREAD:
				puts("random read");
				break;
			case CC_RWRITE:
				puts("random write");
				break;
			case CC_DELETE:
				puts("delete");
				break;
			case CC_OPEN:
				puts("open");
				break;
			case CC_CREAT:
				puts("create");
				break;
			case CC_RENAME:
				puts("rename");
				break;
			case CC_CLOSE:
				puts("close");
				break;
			default:
				putdec((~0x1ff)&errno);
			}
			puts(")");
		}
		break;
	}
	puts("\n");
}

assert(b)
 int b;
{
	if(!b) {
		puts("Assertion failed\n");
		exit(2);
	}
}

swab(src, dst, cnt)
 char *src, *dst;
 unsigned cnt;
{
	register char *s;

	for(s=src; cnt--!=0; ++dst)
	{
		dst[1] = *s++;
		*dst++ = *s++;
	}
}

char *
topofmem()
{
	return sbrk(0);
}
"Eof error");
		break;
	case NOGETC:
		puts("No getc");
		break;
	default:
		if(~0xff&errno) {
		