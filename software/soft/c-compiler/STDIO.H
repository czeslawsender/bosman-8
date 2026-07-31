/* Copyrighted (c) by SuperSoft, Inc., 1982 */

/*	stdio.h for stdio.c edit 38 and C 1.2.0
 *
 *	This file should be included by all programs that use stdio.c
 *	This file generates no code.
 */

#define	BOOLEAN		char	/* typdef char BOOLEAN; */
#define TRUE		1
#define FALSE		0

#define	RESULT		int	/* typedef int RESULT; */
#define	SUCCESS		0
#define	ERROR		(-1)

#define	BDOSERR		255

#define	CON		0x80
#define	RDR		0x81
#define	PUN		0x82
#define	LST		0x83
#define NUL		0x84

#define	BCE		1	/* Byte count error */
#define	NOFD		2	/* No open FD's */
#define	NOFILE		3	/* File not found */
#define	INVFD		4	/* Invalid FD, unopened file */
#define	INVMODE		5	/* IO type mismatch */
#define	OPENERR		6	/* Error on CC_OPEN */
#define	CREATERR	7	/* Error on CC_CREAT */
#define	FSPECERR	8	/* Invalid filename */
#define	BADDEV		9	/* Device out of range */
#define	CLOSEERR	10	/* bdos error in close */
#define	INVREC		11	/* Invalid record in seek */
#define	INVSEEK		12
#define	ENOEXEC		13
#define	ENOSPC		14
#define	ERLINK		15
#define	NOMEM		20	/* Memory allocation failure */
#define	INVBUF		21
#define	READERR		22
#define	EOFERR		23
#define	NOGETC		24

#define	INIT_DMA	0x80	/* Each open sets dma here */
#define	REC_SIZE	128	/* Byte count of a CP/M record */
#define	EXT_SIZE	128	/* Records in a extent 1..EXT_SIZE */
#define	MAX_DRIVE	15
#define	MAX_USER	32
#define	DEF_USER	255	/* Default user code */

#define	FCB_READ	0
#define	FCB_WRITE	1
#define	FCB_R_W		2

#define	START		0	/* Seek from beginning */
#define	CURRENT		1	/* Seek from current record */
#define	LAST		2	/* Seek from end */

struct filedesc
{
	char	fd_dc;		/* Drive Code of this file	*/
	char	fd_name[8];	/* File's name			*/
	char	fd_ext[3];	/* File's extension		*/
	char	fd_ex;		/* Extent number		*/
	char	fd__fcbr1[2];	/* Reserved for CP/M		*/
	char	fd_rc;		/* Record count in extent	*/
	char	fd__fcbr2[16];	/* Reserved for CP/M		*/
	char	fd_nr;		/* Next record number in extent	*/
	int	fd_rrec;	/* Random record number		*/
	char	fd_rreco;	/* rrec overflow, not yet used	*/
				/* End of CP/M FCB.		*/
	char	fd_rbyt;	/* Random byte number		*/
	char	fd_st;		/* Status byte			*/
	char	fd_user;	/* User code of this file	*/
	char	fd_fm;		/* File mode			*/
	char	fd_me;		/* Maximum extent		*/
	char	*fd_ps;		/* Pointer to seq buffer	*/
	int	fd_brec;	/* Buffered record number	*/
	char	*fd_br;		/* Buffered record		*/
};

#define	FILE		struct filedesc
#define	SIZE_FD		sizeof(filedesc)

#define	FS_VALID	1	/* Buffered record is valid	*/
#define	FS_DIRTY	2	/* Buffered record is dirty	*/

struct seq_buf
{
	char *ap;		/* Active pointer	*/
	int  ac;		/* Active count		*/
	int  bs;		/* Buffer size		*/
	char bu;		/* First byte of buffer	*/
				/* Buffer follows	*/
};

#define	SIZE_SB		(sizeof(seq_buf)-1)

/* BDOS calling codes */

#define	CC_CONIN	1
#define	CC_CONOUT	2
#define	CC_RDR		3
#define	CC_PUN		4
#define	CC_LST		5
#define	CC_CPMVER	12	/* Return cpm version # */
#define	SET_DRIVE	14	/* Select disk drive */
#define	CC_OPEN		15
#define	CC_CLOSE	16
#define	CC_FIND		17	/* Find first occurence */
#define	CC_NEXT		18	/* Find next occurence */
#define	CC_DELETE	19
#define	CC_READ		20	/* Read next CP/M record */
#define	CC_WRITE	21	/* Write next CP/M record */
#define	CC_CREAT	22
#define	CC_RENAME	23
#define	GET_DRIVE	25	/* Interrogate drive number */
#define	SET_DMA		26
#define	CC_ATTRIBS	30
#define	CC_USER		32	/* Set/Get user code		*/
#define	CC_RREAD	33	/* random read */
#define	CC_RWRITE	34	/* random write */
#define	CC_CFS		35	/* Compute file size (CPM 2.0 only ) */
#define	CC_SRR		36	/* set random record */

extern	int	errno;
extern	FILE	*stdin;
extern	FILE	*stdout;
extern	FILE	*stderr;

#define	ungetchar	ugetchar
#define	NULL		0	/* standard C NULL pointer */
buf)-1)

/* BDOS calling codes */

#define	CC_CONIN	1
#define	CC_CONOUT	2
#defi