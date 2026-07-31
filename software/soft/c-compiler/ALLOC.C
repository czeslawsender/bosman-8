/* Copyrighted (c) by SuperSoft, Inc., 1983 */
/* alloc.c -- C 1.2.1 */

#include "stdio.h"

char	**allocs;			/* for compatability		*/
char	**alloc0, **alloc1, **allocb;

#define	FAILURE		0
#define	ALLOCATED	1
#define	SZOF		(sizeof allocb)
#define	EPSILON		(8*SZOF)	/* a small non-negative number */


mallin(nbytes)
 unsigned nbytes;
{
	register char *p;

	if(*(p = "") == 0) {
		*p = 1;
		allocb = evnbrk(2*SZOF);
		allocb[0] = (&allocb[1]) | ALLOCATED;
		allocb[1] = (&allocb[0]) | ALLOCATED;
		alloc1 = alloc0 = &allocb[1];
	}

	return (nbytes+(2*SZOF-1))/SZOF;
}

char *
malloc(nbytes)
 unsigned nbytes;
{
	register char **pp;
	char **r2, **s;
	unsigned i;
	int nwords;

	nwords = mallin(nbytes);

	for(pp=alloc0;;) {
		do {
			if((*pp & ALLOCATED) == 0) {
				while((*(s = *pp) & ALLOCATED)==0)
					*pp = *s;
				if(s >= &pp[nwords]) {
					if(s > (alloc0 = &pp[nwords]))
						*alloc0 = *pp;
					*pp = alloc0 | ALLOCATED;
					return pp+1;
				}
			}
			s = pp;
			pp = *pp & ~ALLOCATED;
		} while(s>=alloc0 || pp<alloc0);

		for(i = (nwords+EPSILON)*SZOF;
			(r2=evnbrk(i))==-1; i = (i/SZOF)&~1)
				if(i<=EPSILON)
					return FAILURE;

		*alloc1 = r2 | ((r2!=alloc1+1)? ALLOCATED : 0);
		*r2 = alloc1 = &r2[i/SZOF-1];
		*alloc1 = allocb | ALLOCATED;
	}
}

char *
realloc(p, nbytes)
 char **p;
 unsigned nbytes;
{
	register char **pp;
	char **s;
	int nwords;

	nwords = mallin(nbytes);

	*(pp = p-1) &= ~ALLOCATED;

	while((*(s = *pp) & ALLOCATED) == 0)
		*pp = *s;

	if(s >= &pp[nwords]) {
		if(s > (alloc0 = &pp[nwords]))
			*alloc0 = *pp;
	} else if(s == alloc1 && sbrk(0) == alloc1+1
			      && evnbrk((nwords - (s - pp))*SZOF) != ERROR) {
		*(alloc0 = alloc1 = &pp[nwords]) = allocb | ALLOCATED;
	} else {
		*pp |= ALLOCATED;
		if(pp = malloc(nbytes))
			movmem(p, pp, nbytes);
		free(p);
		return pp;
	}

	*pp = alloc0 | ALLOCATED;
	return p;
}

RESULT
isheap(ptr)
 char **ptr;
{
	register char **p;

	mallin(0);
	for(ptr=ptr[-1],p=alloc0; ; ) {
		if(ptr==p)
			return p&ALLOCATED;
		p = *p&~ALLOCATED;
		if(p==(alloc0&~ALLOCATED))
			break;
	}
	return ERROR;
}

char *
calloc(nthings, sizeofthings)
 unsigned nthings, sizeofthings;
{
	register char *p;
	unsigned nbytes;

	if((p=malloc(nbytes=nthings*sizeofthings)) != NULL) {
		setmem(p, nbytes, 0);
	}
	return p;
}

free(r)
 int	*r;
{
	*(alloc0 = r-1) &= ~ALLOCATED;
}

char *
alloc(nbytes)
 unsigned nbytes;
{
	return malloc(nbytes);
}
ALLOCATE