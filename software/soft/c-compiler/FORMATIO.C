/*
 * Printf et al	for C 1.2.0
 * Copyright SuperSoft, Inc. 1982
 * Fixed sugetc, sgetc 82 Dec 29 RB
 */

int getchar(), Xgetc(), sgetc();
int ugetchar(), Xungetc(), sugetc();
int (*gl_kind)(), (*gl_u_kind)();
char *gl_where;
char *index();

#define STD	getchar	/* standard input */
#define U_STD	ugetchar/* standard input */
#define NSTD	Xgetc	/* bufferred stream */
#define U_NSTD	Xungetc	/* bufferred stream */
#define STR	sgetc	/* string is the argument */
#define U_STR	sugetc	/* string is the argument */

#define NDELIMS 97	/* number of delimiters in %[ */
#define F_EOF	(-1)

#include "customiz.h"
#include "stdio.h"

/*
 * Xrscanf is the formatted input scanner. It takes an input
 * kind, a pointer to the input medium (either a string pointer or
 * a FILE pointer, a format string and a list of pointer
 * arguments, appropriate data is picked up from the
 * text string and stored where the pointer arguments
 * point according to the format string. See the Unix Programmer's Manual
 * Seventh Edition.  Note that the arguments to this routine are in the
 * reverse order of the standard SSC calling sequence.
 */

Xrscanf(kind, u_kind, where, args)
 int (*kind)(), (*u_kind)(), where;
 int *args;
{
	register int width;
	char suppress, c, base, nconv, *sptr;
	int sign, val, xc, *target;
	char delim[NDELIMS], ndelim, gotit;
	char *format;

	gl_kind = kind;
	gl_u_kind = u_kind;
	gl_where = where;

	if(Xnextfield() == F_EOF)
		return F_EOF;

	format = *args++;
	for(nconv = 0; c = *format++; ) {
		if(iswhite(c)) {
			if(Xnextfield() == F_EOF)
				return nconv;
			else
				continue;/* check and see if a match should be don first */
		}

		if(c!='%' && c==(xc=Xnextch()) && xc!=F_EOF) {
			continue;
		} else {
			if(*format=='-')
				++format;

			width = Xgv2(&format);	/* get field width */

			base = 10;
			sign = suppress = gotit = 0;

			if((c = *format++) == '*') {
				suppress = 1;
				c = *format++;
			}

			switch(c) {
			case 'l':
			case 'h':
				/* ignore short and long modifiers */
				if(index("xodu", c = *format++)==NULL)
						return nconv;
				break;
			}
		}

		switch(c=toupper(c)) {
		case 'X':
			base = 16;
			goto doval;
		case 'O':
			base = 8;
		case 'D':
		case 'U':
	doval:
			if(Xnextfield()==F_EOF)
				return nconv;

			if(c!='U')
			{
				if((xc=Xnextch()) == '-') {
					sign = -1;
					--width;
				}
				else
					Xpushback(xc);
			}

			if(width == 0)	/* %d is arbitrary length integer */
				width = 32767;

			for(val = 0; width--; ) { /* go until end of field */
				if((xc = Xnextch()) == F_EOF) {
					if(gotit)
						break;
					else
						return nconv;
				}
				if(Xconv(xc)>=base) {
					Xpushback(xc);
					break;
				}
				val = val * base + Xconv(xc);
				gotit = 1;
			}
			if(sign)
				val = -val;

			if(!suppress) {
				target = *args++;
				*target = val;
				++nconv;
			}
			break;

		case 'S':
			if(Xnextfield()==F_EOF)
				return nconv;

			if(!suppress)
				sptr = *args;

			if(width == 0)	/* %s is arbitrary length string */
				width = 32767;

			while(width--) {	/* go until end of field */
				if((xc = Xnextch()) == F_EOF)
					if(gotit)
						break;
					else
						return nconv;

				if(iswhite(xc)) {
					Xpushback(xc);
					break;
				}
				if(!suppress)
					*sptr++ = xc;
				gotit = 1;
			}
			if(!suppress) {
				++nconv;
				*sptr = '\0';
				++args;
			}
			break;

		case '[':		/* special string format */
			if(*format == '^') {
				ndelim = 1;
				++format;
			}
			else
				ndelim = 0;

			for(sptr = delim; *format != ']' && *format != '\0'; )
				*sptr++ = *format++;

			if(*format == ']')
				++format;

			*sptr = '\0';

			if(!suppress)
				sptr = *args;

			if(width == 0)	/* %[ is arbitrary length string */
				width = 32767;

			while(width--) {	/* go until end of field */
				if((xc = Xnextch()) == F_EOF) {
					if(gotit)
						break;
					else
						return nconv;
				}
				if((index(delim, xc)!=NULL) == ndelim) {
					Xpushback(xc);
					break;
				}
				if(!suppress)
					*sptr++ = xc;
				gotit = 1;
			}
			if(!suppress) {
				++nconv;
				*sptr = '\0';
				++args;
			}
			break;

		case 'C':
			if(!suppress)
				sptr = *args;

			if(width == 0)	/* %c is one character */
				width = 1;

			while(width--) {	/* go until end of field */
				if((xc = Xnextch()) == F_EOF) {
					if(gotit)
						break;
					else
						return nconv;
				}
				if(!suppress)
					*sptr++ = xc;
				gotit = 1;
			}
			if(!suppress) {
				++args;
				++nconv;
			}
			break;

/*		case 'F':
		case 'G':*/
		case '%':
			if(Xnextch()=='%')
				continue;

		default:  return nconv;
		}
	}
	return nconv;
}

/*
 * Xconv is a local routine to convert a character to a number.
 */
Xconv(c)
 char c;
{
	register int i;

	if(isdigit(i=c))
		return i - '0';
	else if(isalpha(i))
		return toupper(i) - 'A' + 10;

	return 0xff;	/* large number */
}

/*
 * Xnextfield is an internal routine for advancing to the next
 * field in whichever input medium is being used by Xrscanf.
 */
Xnextfield()
{
	register int xc;

	for(;;) {	/* skip white space */
		if((xc = Xnextch()) == F_EOF)
			return F_EOF;

		if(iswhite(xc))
			continue;

		Xpushback(xc);	/* at next field */
		return 0;			/* SUCCESS */
	}
}

/*
 * index is a routine for determining whether a
 * character is in a list of terminators or not.
 */
char *
index(s,c)
 char *s, c;
{
	register char *ss;

	for(ss = s; *ss; )
		if(*ss++ == c)
			return ss-1;
	return NULL;
}

/*
 * Xnextch fetches the next character from whichever input
 * medium is specified by kind.  Where is a pointer to
 * that medium.
 */
int
Xnextch()
{
	register int c;

	c = (*gl_kind)();

	if(c == _EOF) {	/* control - z */
		Xpushback(c);
		return F_EOF;
	}
	return c;
}

sgetc()
{
	register char c;

	if((c = *gl_where++) != '\0')/* end of string? */
		return c;

	--gl_where;		/* unupdate the string pointer */
	return F_EOF;
}

Xgetc()
{
	return getc(gl_where);
}

/*
 * Xpushback is an internal routine for pushing a character
 * back onto the input stream.
 */
Xpushback(c)
 char c;
{
	(*gl_u_kind)(c);
/*
	switch(gl_kind) {
	case STD:
		Xugetchar(c);
		break;
	case NSTD:
		Xungetc(c);
		break;
	default:
		sugetc(c);
		break;
	}
*/
}

Xungetc(c)
 char c;
{
	return ungetc(c,gl_where);
}

sugetc(c)
 char c;
{
	*--gl_where = c;
}

/*
 * scanf - just reverse the argument string and call
 * Xrscanf with the correct argument list.
 */
int Xstdin;

scanf(nargs)
 int nargs;
{
	if(nargs < 1)
		return F_EOF;

	return Xrscanf(STD, U_STD, Xstdin, Xrev(&nargs));
}

/* reverse a set of list function arguments */
int *
Xrev(nargs)
 int *nargs;
{
	register int *p;
	register int *q;
	int *temp;

	q = p = nargs;	/* p and q point to start of argument list */
	 /* for p from end of argument list up to beginning... */
	for (p += *p; p >= q; --p) {
		temp = *p;
		*p = *q;
		*q++ = temp;
	}
	return nargs;
}

/*
 * sscanf - just reverse the argument list and call Xrscanf
 */
sscanf(nargs)
 int nargs;
{
	register int *p;

	if(nargs < 2)
		return F_EOF;

	p = Xrev(&nargs);
	return Xrscanf(STR, U_STR, *p, p+1);
}

/*
 * fscanf - just call Xrscanf after reversing the argument list.
 */
fscanf(nargs)
 int nargs;
{
	register int *p;

	if(nargs < 2)
		return F_EOF;

	p = Xrev(&nargs);
	return Xrscanf(NSTD, U_NSTD, *p, p+1);
}

#define MAXLINE 132	/* maximum length of text line */

/*
 *	Xrprintf -- does the formating work given the buffer
 *		AND the arguments in the proper order (reverse of SCC
 *		normal order).
 */

Xrprintf(line,args)
 char *line;
 int *args;
{
	register char *wptr;
	char Xuspr();
	char c, base, *sptr;
	char wbuf[MAXLINE], pf, ljflag;
	int width, precision;
	char negdec, leadch;
	char *format, *backup;
	char *wptr1;

	for(format = *args++; c = *format++; ) /* step through the format */
		if(c!='%')
			*line++ = c; /* just print normal characters */
		else {
			backup = format;
			wptr = wbuf;
			precision = 6;
			negdec = pf = 0;

			 /* left justify this field? */
			if(ljflag = (*format == '-'))
				++format;

			/* normally blank-padding */
			leadch = (*format=='0')? '0': ' '; 

			width = Xgv2(&format);
			if((c = *format++) == '.') {
				precision = Xgv2(&format);
				++pf;
				c = *format++;
			}

			switch(c) {
			case 'l':
			case 'h':
				/* ignore short and long modifiers */
				if(index("xodu", c = *format++)==NULL)
					return;
			}

			if((c = toupper(c)) != 'S' && width == 0)
				width = 1;

			switch(c) { /* format type */

			case 'D':
				if(*args < 0) { /* signed decimal */
					negdec = 1;
					*args = -*args;
				}

			case 'U':  base = 10; goto val; /* unsigned decimal */

			case 'X':  base = 16; goto val;

			case 'O':  base = 8;
				/*
				 * note that arbitrary bases can
				 * be added easily before this line
				 */
				 val:
					wptr1 = wptr;
					width -= Xuspr(&wptr1, *args++, base);
					wptr = wptr1;
					goto pad;

			case 'C':  *wptr++ = *args++; /* character */
				--width;
				goto pad;

			case 'S':
				if(!pf || precision>=MAXLINE)
					precision = MAXLINE-1;

				for(sptr = *args++;;) {
					if(*sptr==0)
						break;

					if(precision==0)
						break;

					if(wptr < wbuf+MAXLINE)
						*wptr++ = *sptr;

					++sptr;
					--width;
					--precision;
				}

			     pad:
					
				if(!ljflag) { /* setmem */
					if(negdec && leadch == '0') {
						*line++ = '-';
						negdec = 0;
						--width;
					}
					while(--width >= 0)
						*line++ = leadch;
				}

				if(negdec) {
					*line++ = '-';
					--width;
				}

				
				for(*wptr='\0', wptr=wbuf; *line++ = *wptr++;)
					;

				--line;		/* forget the '\0' */

				if(ljflag)	/* setmem */
					while(--width >= 0)
						*line++ = ' ';
				break;

/*			case 'F':
			case 'G':*/
			 case '%':
				++backup;	/* then do default: */

			 default: *line++ = '%';
		 		format = backup;

		}
	}
	*line = '\0';
}

/*
	Internal routine used by "sprintf" to perform ascii-
	to-decimal conversion and update an associated pointer:
*/
int
Xgv2(sptr)
 int *sptr;
{
	register int n;
	char *ptr;

	for(n = 0, ptr = *sptr; isdigit(*ptr); )
		n = 10 * n + *ptr++ - '0';

	*sptr = ptr;
	return n;
}

/*
	Internal function which converts n into an ASCII
	base `base' representation and places the text
	at the location pointed to by the pointer pointed
	to by `string.' Yes, you read that correctly.
*/

char
Xuspr(string, n, base)
 char **string;
 unsigned n;
 unsigned base;
{
	register unsigned b;

	if(n < (b=base)) {
		*(*string)++ = n + ((n < 10) ? '0' : 'A'-10);
		return 1;
	}

	return
		Xuspr(string, n/b, b)
			+
		Xuspr(string, n%b, b);
}

printf(nargs)
 int nargs;
{
	char line[MAXLINE];

	if(nargs < 1)
		return NULL;

	Xrprintf(line,Xrev(&nargs));
	return puts(line);
}

/*
 * standard sprintf, reverse the arguments on the stack and call rprintf
 */
sprintf(nargs)
 int nargs;
{
	register int *p;

	if(nargs < 2)
		return;

	p = Xrev(&nargs);
	Xrprintf(*p, p+1);
}

/*
 * fprintf -- formatted print on output stream
 * just reverse the arguments and let rprintf do the work
 */

fprintf(nargs)
 int nargs;
{
	register int *p;
	char line[MAXLINE];

	if(nargs < 2)
		return F_EOF;

	p = Xrev(&nargs);
	Xrprintf(line, p+1);
	return fputs(line, *p);
}
e location pointed to by the pointer pointed
	to by `string.' Yes, you read that correctly.
*/

char
Xuspr(string, n