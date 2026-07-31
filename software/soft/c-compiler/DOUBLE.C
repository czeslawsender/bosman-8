/*
 * double.c
 *
 *	'B' prepended to symbols to avoid collisions mqh 9 July '82
 *	  for C 1.2.3
 *
 *		Copyright (c) 1983  by  SuperSoft, Inc.
 *
 */

double *doOp(), *Bround(), *int2bcd();
double *Bsub(), *Badd(), *Bmul(), *Bdiv();
double *Bcos(), *Bsin(), *Btan(), *Bsqr(), *Bint(), *Babs();
double *Blog(), *Bexp(), *Bfac(), *Barctan();
double *Bmant(), *Bmodulo(), *Bneg(), *BUneg(), *BUabs(), *Bentier();
double *Bten2n(), *Bcheby(), *Bxtoy(), *Bxtoiy(), *Bxtofy();
double *addf(), *subf(), *mulf(), *divf();

#define	 BCDS	8

#define	MAXMANT	13	/* # max exponent of integer */
#define MAXNEGEXP	(-128)
#define	MAXPOSEXP	127
#define BCDNORM		(-1)
#define	LOW_SIN_EXP	-20
#define	NTNM		10	/* # of iterations of Newton's method for
					square root	*/
#define	OFFS		2
#define BIGFACT		84	/* biggest n for which n! works */

#ifndef CINIT
#define	EX extern
#else
#define	EX	/**/
#endif

/*
 * Global BCD constants
 */
EX double	Bzero[1], Bhalf[1], Bone[1], Btwo[1];
EX double	Bthree[1], Bfour[1], Bten[1], Bmaxfact[1];
EX double	Bilmt[1];

EX double	Bpi[1], Bpi_by_2[1];

EX double	Blog_10[1];
EX double	Blog_2[1];		/*	Rig factor for log	*/

EX
double	Bmaxneg[1],		/* most negative integer */
	Binf[1],		/* largest bcd number */
	Bminus_max_num[1],	/* most negative number to take e(x) of. */
	Bmax_num[1];		/* largest number to take e(x) of, empirical */

/* Chebysheff	coefficient matrices
 */
EX
double	Bexpcoef[9][1];		/* coeffs for exp function */
EX
double	Bsincoef[7][1];		/* coeffs for sine function */
EX
double	Blogcoef[15][1];	/* coeffs for log function */
EX
double	Batncoef[16][1];	/* coeffs fof arc tangent function */

/* Global error Flag  & values: */
#define	BOK		0    /* No problem */
#define	BOVFERR		(-1) /* overflow */
#define BDVZERO		(-2) /* div by zero */
#define	BUNDFERR	(-3) /* underflow */
#define	BPWRERR		(-4) /* Slight problem, power of negative number */
#define	BLOGERR		(-5) /* Slight problem, log of non-positive number */
#define BFACTERR	(-6) /* Slight problem, ! undefined. */

extern int	BERRFL;

double *
Bmov(dst, src)
 double *dst, *src;
{
	movmem(src, dst, BCDS);
	return dst;
}

/*
 *	The functions Bmant and Bexpo return values a and b resp
 *	where the argument x is of the form x = a * 10**b for
 *	.1 <= |a| < 1. (except when x == 0).
 */

double *
Bmant(dst, n)
 double n[];
 char dst[];
/*
 *	Stick the mantissa of n into dst.
 */
{
	movmem(n, dst, BCDS);
	*dst = 0XFF;
	return dst;
}

Bexpo(x)
 char x[];
/*
 *	return the integer exponent of x.
 */
{
	register int a;

	a = *x;
	return (((a&0X80)? ~0XFF: 0)|a) + 1;	/* +1 for 8080/8086 */
}

Bsign(x)
 char x[];
{
	return (*++x & 0x0f)? ((*x & 0x90)? -1: 1): 0;

/*	In mundane code:
	if (!(x[1] & 0X0F))
		return 0;

	return (x[1] & 0X90)? -1: 1;
*/
}

double *
Bmodulo(y, z, m)
 double y[], z[], m[];
/*	stick x modulus m into y with the assumption that m is positive */
{
	double	tmp[1], tmp1[1];

	return Bsub(y, z, Bmul(tmp1, Bentier(tmp1, Bdiv(tmp, z, m)), m));
}

double *
Bneg(y, x)	/* y = -x */
 double *x, *y;
{
	movmem(x,y,BCDS);
	return BUneg(y);
}

double *
BUneg(x)	/* unary neg operator x = - x */
 char x[];
{
	x[1] ^= 0X90;
	return x;
}

double *
Babs(y,x)	/* y = abs(x)	*/
 double *x, *y;
{
	movmem(x,y,BCDS);
	return BUabs(y);
}

double *
BUabs(x)	/* unary abs operator x = abs(x) */
 char x[];
/*	change the BCD number x so that it is positive.
 */
{
	x[1] &= 0X6F;
	return x;
}

double *
Bint(y, x)
 char y[];
 double x[];
/*	Return the integer part of x in y.
 */
{
	register int	i;
	int	exp;

	if((exp=Bexpo(x)) <= 0)
		movmem(Bzero, y, BCDS);
	else {
		movmem(x, y, BCDS);
		if(exp<MAXMANT) {
			if (!(exp % 2))
				y[OFFS + exp/2 - 1] &= 0XF0;
			for (i = OFFS + exp/2; i<BCDS; ++i)
				y[i] = 0;
		}
	}
	return y;
}

double *
Bentier(y, x)
 double y[], x[];
/*	put the floor of x into y (towards -infinity)
 */
{
	if(Bne(x, Bint(y, x)))
		if(Blt(x, Bzero))
			Bsub(y, y, Bone);
	return y;
}

double *
Bten2n(y, x)
 double y[], x[];
/*	put 10**x into y where x is assumed to be an integer (BCD).
 */
{
	double	tmp[1];

	movmem(x, tmp, BCDS);
	movmem(Bone, y, BCDS);
	if(Bge(tmp, Bzero))
		while(Bgt(tmp, Bzero)) {
			Badd(y, y, y);
			Bsub(tmp, tmp, Bone);
		}
	else
		while(Blt(tmp, Bzero)) {
			Bmul(y, y, Bhalf);
			Badd(tmp, tmp, Bone);
		}
	return y;
}

Blt(x, y)
 double x[], y[];
{
	return Btest(x, y) == -1;
}

Bgt(x, y)
 double x[], y[];
{
	return Btest(x, y) == 1;
}

Beq(x, y)
 double x[], y[];
{
	return Btest(x, y) == 0;
}

Bne(x, y)
 double x[], y[];
{
	return Btest(x, y) != 0;
}

Ble(x, y)
 double x[], y[];
{
	return Btest(x, y) != 1;
}

Bge(x, y)
 double x[], y[];
{
	return Btest(x, y) != -1;
}

Btest(x, y)
 double x[], y[];
/* return:
 *	1 if x > y
 *	0 if x = y
 *	-1 if x < y
 */
{
	double temp[1];

	Bsub(temp,x,y);
	return Bsign(temp);
}

double *
Blog(y, x)
 double y[], x[];
{
	register int	ncoef;
	double	tmp[1], tmp1[1];
	double	rig[1];

	ncoef = 14;
	if(Ble(x, Bzero)) {
		Bseterr(BLOGERR);
		movmem(Bzero,y,BCDS);
		return y;
	}

/*	Adjust number so that 1/2 <= mantissa(x) < 1.
 *	Since the chebysheff function returns the log of 2x,
 *	the rig value is set to compensate for this.
 */
	movmem(Blog_2, rig, BCDS);
	Bmant(tmp1, x);
	while(Blt(tmp1, Bhalf)) {
		Badd(tmp1, tmp1, tmp1);
		Badd(rig, rig, Blog_2);
	}

	Bcheby(tmp1, Bsub(tmp,Bmul(tmp1,tmp1,Bfour),Bthree), Blogcoef, ncoef);
	return Bsub(y, Badd(tmp, tmp1, Bmul(tmp, int2bcd(tmp, Bexpo(x)),
		Blog_10)), rig);
}

double *
Bsin(y, x)
 double y[], x[];
/*	return the sine of x in y
 */
{
	register int ncoef;


	double tmp[1], tmp1[1], tmp2[1];

	if(Bexpo(x)<LOW_SIN_EXP || Beq(x, Bzero)) {
		movmem(Bzero, y, BCDS);
		return y;
	}

	ncoef = 6;
	Bdiv(tmp, x, Bpi_by_2);
	Bentier(tmp1, Bdiv(tmp2, Badd(tmp1, tmp, Bone), Bfour));
	Bsub(tmp, tmp, Bmul(tmp1, tmp1, Bfour));
	if (Bgt(tmp, Bone))
		Bsub(tmp, Btwo, tmp);

	Bmul(tmp1, tmp, tmp);
	Bsub(tmp1, Badd(tmp1, tmp1, tmp1), Bone);
	return Bmul(y, tmp, Bcheby(tmp2, tmp1, Bsincoef, ncoef));
}

double *
Bcos(y, x)
 double y[], x[];
/*	return the cosine of x in y
 */
{
	double tmp[1];

	return Bsin(y, Badd(tmp, x, Bpi_by_2));
}

double *
Btan(y, x)		/* tangent */
 double y[], x[];
{
	double	tmp[1];

	return Bdiv(y, Bsin(y, x), Bcos(tmp, x));
}

double *
Bsqr(y, x)		/* square root */
 char y[], x[];
{
	register int n;
	int	exp;
	double tmp[1], tmp1[1];

	switch(Bsign(x)) {
	case -1:
		Bseterr(BPWRERR);
	case 0:
		movmem(Bzero, y, BCDS);
		break;
	case 1:
		Bmant(tmp1, x);
		if((exp=Bexpo(x))%2)
			Bmul(tmp1, tmp1, Bten);

		movmem(tmp1, tmp, BCDS);
		Bmul(y, tmp, Bhalf);
		for(n=NTNM; --n;)
			Bmul(y, Badd(y, y, Bdiv(tmp, tmp1, y)), Bhalf);

/*		Kind of a kludge...
 */
		*y += exp>>1;
		break;
	}
	return y;

}

double *
Bexp(y, x)
 double	y[], x[];
/*	Return exp(x) in y.
 */
{
	register int	ncoef;
	double	n[1], tmp[1], tmp1[1], tmp2[1];

	if(Bge(x, Bmax_num)) {
		movmem(Binf, y, BCDS);
		return y;
	}

	if(Ble(x, Bminus_max_num)) {
		movmem(Bzero, y, BCDS);
		return y;
	}

	ncoef = 8;
	Bsub(tmp, Badd(n, Bentier(tmp1, Bdiv(tmp, x, Blog_2)), Bone), tmp);
	Bsub(tmp, Badd(tmp, tmp, tmp), Bone);
	return Bmul(y, Bten2n(tmp1,n), Bcheby(tmp2, tmp, Bexpcoef, ncoef));
}

double *
Bfac(y, x)
 double y[], x[];
/*	Return the factorial of the number x in y.
 *	Argument is assumed to be a positive integer.
 *	Arg is tested against being negative or "too big."
 */
{
	double	tmp[1];

	if(Bgt(x,Bmaxfact) || Blt(x,Bzero)) {
		Bseterr(BFACTERR);
		movmem(Bzero,y,BCDS);
		return y;
	}

	movmem(x, tmp, BCDS);
	movmem(Bone, y, BCDS);
	while(Bgt(tmp, Bone)) {
		Bmul(y, y, tmp);
		Bsub(tmp, tmp, Bone);
	}
	return y;
}

double *
Barctan(y, x)
 double	y[], x[];
/*	Return the arc tangent of x in y.
 */
{
	register int ncoef;
	double	u[1], yy[1];
	double	tmp[1], tmp1[1];

	ncoef = 15;
	movmem(x, tmp, BCDS);
	if (Bgt(BUabs(tmp), Bone))
		Bdiv(u, Bone, x);
	else
		movmem(x, u, BCDS);

	Bmul(tmp, u, u);
	Bmul(yy, u, Bcheby(tmp1, Bsub(tmp,Badd(tmp,tmp,tmp),Bone)
	 ,Batncoef, ncoef));

	movmem(x, tmp, BCDS);
	if (Bgt(BUabs(tmp), Bone)) {
		if (Bgt(x, Bzero))
			Bsub(y, Bpi_by_2, yy);
		else
			BUneg(Badd(y, yy, Bpi_by_2));
	}
	else
		movmem(yy, y, BCDS);

	return y;
}

double *
Bcheby(res, x, coef, n)
 char	res[], x[], coef[][BCDS];
 int n;
/* Put the nth approximation of the function whose Chebyshev coefficients are
 *	in coef evaluated at x in res.
 */
{
	register int r;
	double	a[1], b[1], d[1], x2[1];
	double	tmp[1];

	movmem(Bzero, b, BCDS);
	movmem(&coef[n][0], d, BCDS);
	Badd(x2, x, x);
	for (r=n-1; r>=0; --r) {
		movmem(b, a, BCDS);
		movmem(d, b, BCDS);
		Badd(d, Bsub(d, &coef[r][0], a), Bmul(tmp, x2, b));
	}
	return Bmul(res, Bsub(tmp, d, a), Bhalf);
}

double *
Bxtoy(z, x, y)	/* z == x**y */
 double *z, *x, *y;
{
	double inty[1], fracy[1];
	double tmp[1], tmp2[1];

	Bsub(fracy, y, Bint(inty,y));	/* inty = int(y);fracy = y-inty */
	/* z = x^inty*x^fracty */
	return Bmul(z, Bxtoiy(tmp,x,inty), Bxtofy(tmp2,x,fracy));
}

double *
Bxtoiy(z, x, y)	/* z = x ** y special case where y is an int */
 double *z, *x, *y;
{
	double cnt[1];

	if(Bsign(y)==0) {	/* z = (x ** 0) == 1 */
		movmem(Bone, z, BCDS);
		return z;
	}
	if(Blt(Babs(cnt,y),Bilmt)) {
		movmem(x, z, BCDS);	/* z = x */
		for(; Bsign(Bsub(cnt,cnt,Bone));)	/* z*z cnt-1 times */
			Bmul(z, z, x);
		if(Bsign(y) < 0)		/* 1/x^y == x^(-y) */
			Bdiv(z, Bone, z);
		return z;
	}
	else
		return Bxtofy(z,x,y);		/* x^y otherwise */
}

double *
Bxtofy(z,x,y)	/* z = x ** y general case */
 double *z, *x, *y; /* called with x<1 or x>10 */
{
	double tmp[1];

	if(Bsign(y)==0) {	/* z = (x ** 0) == 1 */
		movmem(Bone, z, BCDS);
		return z;
	}

	switch(Bsign(x)) {
	case  1:
		return Bexp(z, Bmul(tmp,Blog(z,x),y));
	case  0:
		break;
	case -1:
		/* integer powers have already been done */
		Bseterr(BPWRERR);	/* is this checked by Blog? %%*/
		break;
	}
	movmem(Bzero, y, BCDS);
	return z;
}

Bseterr(e)	/* set Berrflg to e if it is clear */
 int e;
{
	if(!BERRFL)
		BERRFL = e;
}

#define	TRUE	1
#define	FALSE	0

#define	ADD	(addf)
#define	SUB	(subf)
#define	MUL	(mulf)
#define	DIV	(divf)

char *
s2bcd(bcdno, s)
 char	bcdno[];
 char	*s;
{
	register char *str;
	char	nonzero,		/* true if <> 0 */
		negative,		/* true if < 0 */
		ch,			/* current character */
		expneg,			/* true if sign of exp is '-' */
		curbyte,		/* current byte in bcd # */
		curdigit;		/* current digit in bcd # */

	int	exp,			/* exponent of mantissa */
		exp1;			/* explicit exponent */


/* zero the bcd number */
	setmem(bcdno,BCDS,0);

	negative = FALSE;
	switch(*(str=s)) {
	case '-':
		negative = TRUE;
	case '+':
		++str;
	}

	curbyte = curdigit = 1;
	exp = 0;
	nonzero = FALSE;
	while(isdigit(ch = *str++)) {
		if(ch -= '0')
			nonzero = TRUE;
		if(nonzero) {
			++exp;
			if(curdigit <= MAXMANT)
				if(curdigit++ & 1)	/* ie. % 2 */
					bcdno[curbyte] |= ch;
				else
					bcdno[++curbyte] = ch<<4;
		}
	}
	if(ch=='.')
		while(isdigit(ch = *str++)) {
			if(ch -= '0')
				nonzero = TRUE;
			if(nonzero == FALSE)
				--exp;
			if(nonzero && (curdigit <= MAXMANT))
				if(curdigit++ & 1)	/* ie. % 2 */
					bcdno[curbyte] |= ch;
				else
					bcdno[++curbyte] |= ch <<4;
		}
	if(nonzero == FALSE)
		return str;

	if(negative)
		bcdno[1] |= 0X90;

	exp1 = 0;
	if(toupper(ch) == 'E') {
		expneg = FALSE;
		switch(*str) {
		case '-':
			expneg = TRUE;
		case '+':
			++str;
			break;
		}

		while(isdigit(ch = *str++))
			exp1 = exp1*10 + ch - '0';
		if(expneg)
			exp1 = -exp1;
	}

/* Check exponent size */
/* changed for 8080/86 */
	exp += exp1-1;
	if(MAXNEGEXP>exp || exp>MAXPOSEXP)
		exp = 1;  /* more or less an arbitrary choice */

	*bcdno = exp;
	return str;
}

Bcd2s(str, bcdno)
 char	*str;		/* assumed to be "big" enough */
 char	bcdno[BCDS];
{
	register char *ptr;
	int	exp;
	int	i;

	ptr = str;
	*ptr++ = (bcdno[1] & 0XF0)? '-': '+';
	*ptr++ = (bcdno[1] & 0X0F) + '0';
	*ptr++ = '.';

	for(i=2; i<BCDS;) {
		*ptr++ = ((bcdno[i]>>4) & 0X0F) + '0';
		*ptr++ = (bcdno[i++] & 0X0F) + '0';
	}

	*ptr++ = 'E';

	exp = Bexpo(bcdno);
	if(exp <= 0) {
		*ptr = '-';
		exp = 1 - exp;
	} else {
		*ptr = '+';
		--exp;
	}

	if(str[1] == '0') {
		*ptr = '+';
		exp = 0;
	}
/* eobon */

/* Assume that exponent is eight bits (<= 199 in magnitude */
	if (exp >= 100) {
		*++ptr = '1';
		exp -= 100;
	}
	else
		*++ptr = '0';

	*++ptr = exp/10 + '0';
	*++ptr = exp%10 + '0';
	*++ptr = 0;

	return str;
}

double *
Badd(dst, aa, bb)
 double	*dst;
 double	*aa;
 double	*bb;
{
	register int diff;
	double	tmp1[1], tmp2[1];

	if(Bsign(aa)==0)
		movmem(bb, dst, BCDS);
	else if(Bsign(bb)==0)
		movmem(aa, dst, BCDS);
	else if((diff = Bexpo(aa)-Bexpo(bb)) > 12) {
		movmem(aa, dst, BCDS);
	} else if (diff < -12) {
		movmem(bb, dst, BCDS);
	} else {
		movmem(aa, tmp1, BCDS);
		movmem(bb, tmp2, BCDS);
		doOp(dst, tmp1, tmp2, ADD);
	}
	return dst;
}

double *
Bsub(dst, aa, bb)
 double	*dst;
 double	*aa;
 double	*bb;
{
	register double *d0;
	double tmp[1];

	return Badd(dst, aa, Bneg(tmp,bb));
}

double *
Bdiv(dst, aa, bb)
 double	*dst;
 double	*aa;
 double	*bb;
{
	register double *d0;
	double	tmp1[1], tmp2[1];

	movmem(aa, tmp1, BCDS);
	movmem(bb, tmp2, BCDS);
/* Note the reversed order:
*/
	doOp(d0=dst, tmp2, tmp1, DIV);
	if(BERRFL == BUNDFERR) {
		BERRFL = 0;
		setmem(d0, BCDS, 0);
	}
	return d0;
}

double *
Bmul(dst, aa, bb)
 double	*dst;
 double	*aa;
 double	*bb;
{
	register double *d0;
	double	tmp1[1], tmp2[1];

	movmem(aa, tmp1, BCDS);
	movmem(bb, tmp2, BCDS);
	doOp(d0=dst, tmp1, tmp2, MUL);
	if(BERRFL == BUNDFERR) {
		BERRFL = 0;
		setmem(d0, BCDS, 0);
	}
	return d0;
}

/*
 * Format a bcd number into a string.  This routine
 * and the ones following are based on the routines
 * Mike Hiller did for scratchpad in July 82.
 */

format(str, number)
 char *str, *number;
{
	register char *s;
	int x, dec;
	char n[BCDS];
	double *p;

	movmem(number, n, BCDS);

	s = str;
	*s++ = (Bsign(n) < 0) ? '-' : ' ';

	x = mag(n);
	if(x+2 >= 13 || x < -4) { /* 2 == sign + decimal point */
 expformat:
		Bround(n, 8);
		e_format(s, n, 1, 6);
	} else {
		if(x<0) {
			dec = 10;
			p = Bround(n, dec+x+2);
		} else {
			dec = 10-absval(x);
			p = Bround(n, 12);
		}

		if(mag(p)+2 >= 13)	/* field overflow */
			goto expformat;

		f_format(s, p, 1, dec);
		stripzeros(s);
	}
}

mag(n)	/* get the magnitude of the bcd number for output purposes */
 double *n;
{
	return Bexpo(n)-1;
}

/*
 * print E formatting
 */
e_format(s, n, width, after)
 char *s;
 char *n;
 int width, after;
{
	register char *p;
	int i;
	int before;

	before = width - after - 4;
	if(before<1)
		before = 1;

	for(p=s,i=0; i<before; ++i)
		*p++ = getdig(n,i) + '0';
	*p++ = '.';

	for(; i < before+after; ++i)
		*p++ = getdig(n,i) + '0';
	*p++ = 'E';
	*p++ = ((i = (Bexpo(n)-before)) < 0) ? '-' : '+';

	if((i = absval(i)) > 99) {
		*p++ = '1';
		i -= 100;
	}

	*p++ = i/10 + '0';
	*p++ = i%10 + '0';
	*p = 0;
	return p;
}

stripzeros(s0)	/* strip trailing zeros off of s0, space filling on left */
 char *s0;	/* to preserve string's length	*/
{
	register char *s;
	int c, l;

	for(c=0,s=s0+(l=strlen(s0))-1; s0<s; --s) {
		switch(*s) {
		case '0':
		case ' ':
			*s = 0;
			++c;
			continue;
		case '.':
			*s = 0;
			++c;
		default:
			break;
		}
		break;
	}
	if(!c)
		return;
	s = s0;
	movmem(s, s+c, l);
	setmem(s, c, ' ');
}

g_format(temp, s, width, after)
 char *temp;	/* start column (used to prevent labels from wrapping) */
 double *s;	/* cell to be displayed */
 int width;
 int after;
{
	register int x;
	int jive;

	x = mag(s);	/* magnitude of number */
	jive = Bsign(s) >= 0;	/* jive = 1 if we need not display sign */
	/* jive+1 if we need not display decimal point */
	if(Beq(s,Bint(temp,s)))
		++jive;
	
	if(absval(x) + 2 >= width + jive || width + x <= 4) {
		e_format(temp, s, width, after);
	} else {
		f_format(temp, s, width+jive, width-3-(x<0? 0: x) );
		stripzeros(temp);
		/* remove jive spaces */
		movmem(temp+jive, temp, strlen(temp+jive)+1);
	}
}

/*
 * print Fixed point formatting
 */
f_format(s, n, width, after)
 char *s;
 char *n;
 int width, after;
{
	register char *p;
	int i, m;
	int before;

	p = s;
	m = mag(n);
	i = 0;
	before = width - after - 1;
	if(m<0) {
		if(before>0)
			*p++ = '0';
		*p++ = '.';
		for(; m++ < -1 && after-- > 0;)
			*p++ = '0';
	} else {
		for(; m-- >= 0 ;)
			*p++ = getdig(n,i++) + '0';
		if(after>0)
			*p++ = '.';
	}

	while(after-- > 0)
		*p++ = getdig(n, i++) + '0';
	*p = 0;
	return p;
}


getdig(n,ii)	/* get ii'th bcd digit of n (ii goes from 0 to 12) */
 char *n;
 unsigned ii;
{
	register int i;

	if((i=ii) >= 13)
		return 0;
	i += 3;		/* blow off exponent and sign */

	return !(i & 1) ? (n[i>>1] >> 4) & 0x0f : (n[i>>1] &0x0f);
}


/*
 * round a bcd number by adding 5  with exponent m.
 * this routine trashes the number.
 */

double *
Bround(n, m)
 double *n;
 int m;
{
	char temp[BCDS];

	if(Bsign(n) == 0)
		return n;

			/***** OP/SYS DEPENDENT *****/
#define	FUDGE	0	/* adjusted for 8080 & 8086	*/
/*#define FUDGE	1	/* adjusted for Z8000		*/

	m = Bexpo(n) - m - FUDGE;
	if(m<-128-FUDGE || m>127-FUDGE)		/* can't round n */
		return n;

	int2bcd(temp, 5);
	temp[0] = m;

	if(Bsign(n)<0)		/* round towards +/- infinity */
		BUneg(temp);
	Badd(n, temp, n);

	return n;
}


/*
 * convert a bcd number to an integer rounding the bcd number as necessary
 */

Bcd2int(bcdsrc)
 double *bcdsrc;
{
	register int val;
	int exp;
	int i;

	if((exp=Bexpo(bcdsrc)) < 0) {		/* -0.1 < bcdsrc < 0.1 */
		Bseterr(BUNDFERR);
		return 0;
	}

	for(val=0,i=0; ; ++i, --exp) {
		if(exp<=0) {
			if(getdig(bcdsrc, i) >= 5)
				++val;	/* round up */
			break;
		} else {
			if((val = val*10+getdig(bcdsrc, i))<0) {
				Bseterr(BOVFERR);
				val = 32767;
				break;
			}
		}
	}
	return Bsign(bcdsrc)==-1? -val: val;
}

double *
int2bcd(bcddst, value)
 char bcddst[];
 int value;
{
	register int exp;
	char digits[20];
	char sign;
	int c, i, j, r;
	int curdigit, curbyte;

	movmem(Bzero, bcddst, BCDS);
	if(!value)
		return bcddst;

	if( sign = (value<0)) {
		value = -value;
		if(value<0) {
			movmem(Bmaxneg, bcddst, BCDS);
			return bcddst;
		}
	}
	exp = 0;
	do {	/* convert the integer to unpacked bcd in reverse order */
		r = value % 10;
		digits[exp++] = r;
	} while ((value /= 10) > 0);

	for(r=0, j=exp-1; r<j; ) {	/* reverse the order */
		c = digits[r];
		digits[r++] = digits[j];
		digits[j--] = c;
	}

	curdigit = 1;
	curbyte = 1;
	i = exp<MAXMANT ? exp : MAXMANT;

	/* pack the number and calculate the exponent */
	for(r=0; r<i; ++r) {
		if(curdigit<=MAXMANT) {
			if(curdigit & 1)
				bcddst[curbyte] |= digits[r];
			else
				bcddst[++curbyte] = (digits[r] << 4);
		}
		++curdigit;
	}

	if(sign)
		bcddst[1] |= 0x90;

	*bcddst = exp+BCDNORM;
	return bcddst;
}
val;
}

double *
int2bcd(bcddst, value)
 char bcddst[];
 int value;
{
	register int exp;
	char digits[20