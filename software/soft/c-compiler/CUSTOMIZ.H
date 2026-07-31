
/*
 *	Conditional compilation controls for C 1.2
 *
 *
 *	Copyrighted (c) 1983  by SuperSoft, Inc.
 *
 *
 */

#define SEEK		1	/* random access code		*/
#define SERIAL		1	/* serial device code		*/
#define APPENDMODE	1	/* fopen(,"a",) code		*/
/*#define EXEC		1	/* exec() and execl()		*/
#define CPM1p4		1	/* CPM1.4 code			*/
#define BYTEWISE	1	/* 1 byte vs. 128 byte reclen	*/
/*#define REDIRECT	1	/* command line '<', '>', '@'	*/
/*#define CPM86		1	/* CP/M-86			*/

				/* remove this definition if no	*/
				/* eof char is desired:		*/
#define _EOF		26	/* the random access eof char	*/

#define	STREQ		1	/* in ass. language on 8080	*/
