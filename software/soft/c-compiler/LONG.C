/*
 * MATH.C - Math Routines...
 *
 * for C 1.2
 */

#define NOT	~	/* tilde */

struct {
	unsigned unsign;
};

union ulong {
	long lng[1];
	int word[2];
};

#define	hi	word[0]
#define	lo	word[1]

cc2mov(a,b)
 long *a, *b;
{
	a->hi = b->hi;
	a->lo = b->lo;
}

cc2add(a,b)
 long *a, *b;
{
	register unsigned sum;

	sum = a->lo + b->lo;
	a->hi += b->hi +
	(sum < a->lo.unsign && sum < b->lo.unsign);

	a->lo = sum;
}

cc3add(q,a,b)
 long *q, *a, *b;
{
	register unsigned sum;

	q->lo = sum = a->lo + b->lo;
	q->hi = a->hi + b->hi +
	(sum < a->lo.unsign && sum < b->lo.unsign);
}

cc1inc(a)
 long *a;
{
	if(++(a->lo) == 0)
		++(a->hi);
}

cc1dec(a)
 long *a;
{
	if((a->lo)-- == 0)
		--(a->hi);
}

cc1com(a)
 long *a;
{
	a->hi = NOT a->hi;
	a->lo = NOT a->lo;
}

cc2com(a,b)
 long *a, *b;
{
	a->hi = NOT b->hi;
	a->lo = NOT b->lo;
}

cc2or(a,b)
 long *a, *b;
{
	a->hi |= b->hi;
	a->lo |= b->lo;
}

cc3or(a,b,c)
 long *a, *b, *c;
{
	a->hi = b->hi | c->hi;
	a->lo = b->lo | c->lo;
}

cc2and(a,b)
 long *a, *b;
{
	a->hi &= b->hi;
	a->lo &= b->lo;
}

cc3and(a,b,c)
 long *a, *b, *c;
{
	a->hi = b->hi & c->hi;
	a->lo = b->lo & c->lo;
}

cc2xor(a,b)
 long *a, *b;
{
	a->hi ^= b->hi;
	a->lo ^= b->lo;
}

cc3xor(a,b,c)
 long *a, *b, *c;
{
	a->hi = b->hi ^ c->hi;
	a->lo = b->lo ^ c->lo;
}

#ifdef FIXME
cc2sh(a,b)
 long *a;
 int b;
{
	xdsh(&a->hi,b);
	a->hi |= xdsh(&a->lo,b);
}

cc3sh(a,b,c)
 long *a, *b;
 int c;
{
	cc2mov(a,b);
	ccsdsh(a,c);
}

static
cc2ish(a,i)
 int *a;
 int i;
{
	register int x;
	int j;

	if(i>0) {
		j = 16-i;
		x = a >> j;
		*a <<= i;
	} else if(i<0) {
		j = i-16;
		x = a << j;
		*a >>= -i;
	} else
		return 0;

	return x&((1<<j)-1);
}
#endif FIXME

cc2cmp(a,b)
 long *a, *b;
{
	if(a->hi>b->hi)
		return 1;

	if(a->hi==b->hi) {
		if(a->lo.unsign>b->lo.unsign)
			return 1;
		else if(a->lo.unsign<b->lo.unsign)
			return -1;
		else	return 0;
	}
	return -1;
}

cc2mul(pa,pb)
 long *pa, *pb;
{
	register char sign;
	long a, b;

	sign = (pa->hi>=0) ^ (pb->hi>=0);

	if(cc2cmp(pa,pb)<0)
	{
		cc2mov(&b,pa);
		cc2mov(pa,pb);
	} else {
		cc2mov(&b,pb);
	}

	if((pa->hi|pa->lo)==0)
		return;

	if((b.hi|b.lo)==0)
	{
		pa->hi = 0;
		pa->lo = 0;
		return;
	}
#ifdef EXPERIMENTAL
	/* really results in a 16 bit mul? */
	if(cc1bits(pa)+cc1bits(b)<=16)
		pa->lo = pa->lo*b.lo;
#endif

	/* sorry: */
	for(cc2mov(&a,pa);;){
		if(b.lo--==0)
			--b.hi;
		if((b.hi|b.lo)==0) {
			if(sign)
				cc1neg(pa);
			return;
		}
		cc2add(pa,&a);
	}
}

static
cc1bits(a)
 long *a;
{
	if(a->hi==0)
		return cc1ibits(a->lo);
	return cc1ibits(a->hi)+16;
}

static
cc1ibits(i)
 int i;
{
	register int j;

	for(j=16;j>=0;--j)
		if(i&(1<<j))
			return j;
	return 0;
}

cc2imul(x,b0,b1)
 long *x;
 int b0, b1;
{
	long b;

	b.hi = b0;
	b.lo = b1;
	cc2mul(x,&b);
}

cc2iadd(x,b0,b1)
 long *x;
 int b0, b1;
{
	long b;

	b.hi = b0;
	b.lo = b1;
	cc2add(x,&b);
}

cc1prt(a)	/* move me to formatio */
 long *a;
{
	printf("%x%4x",a->hi,a->lo);
}

cc3sub(a,b,c)
 long *a, *b, *c;
{
	cc2mov(a,b);
	cc2sub(a,c);
}

cc2sub(a,b)
 long *a, *b;
{
	long bb;

	cc2neg(&bb,b);
	cc2add(a,&bb);
}

cc1neg(d)
 long *d;
{
	cc1com(d);
	cc2iadd(d,0,1);
}

cc2neg(a,b)
 long *a, *b;
{
	cc2com(a,b);
	cc2iadd(a,0,1);
}

/*
 * Xdiv - Do a 32 Bit Signed Division...
 */
cc3div(d,s,ccxdrem)	/* should be cc4div... */
 long *d, *s, *ccxdrem;
{
	long q,v,n;

	cc2mov(&v,d);
	cc2mov(&n,s);
	if(v.hi<0)
		cc1neg(&v);

	if(n.hi<0)
		cc1neg(&n);

	/* 16 bit operation? */
	if((v.hi|n.hi)==0) {
		q.hi = 0;
		q.lo = v.hi/n.lo;
	} else {
	/*
	 * Start Quotient Counter at Negative One,
	 * and subtract the divisor until it goes negative...
	 */
		q.hi = -1;
		q.lo = -1;
		while(v.hi>=0)
		{
			cc2sub(&v,&n);
			cc1inc(&q);
		}
		cc2mov(ccxdrem,&v);
		cc2add(ccxdrem,&n);	/* form remainder */
	/*
	 * Now, negate the Quotient if the signs of the dividend
	 * and divisor were not the same...
	 */
		if((d->hi<0) ^ (s->hi<0))
			cc1neg(&q);

	}
	cc2mov(d,&q);
}
cc2mov(a,b);
	cc2sub(a,c);
}

cc2sub(a,b)
 long *a, *b;
{
	long bb;

	cc2neg(&bb,b);
	cc2add(a