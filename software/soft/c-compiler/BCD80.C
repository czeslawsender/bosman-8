#ifdef REL
#asm
	PUBLIC	ADDF
	PUBLIC	SUBF
	PUBLIC	DIVF
	PUBLIC	MULF
	EXTRN	BERRFL

 	PUBLIC Bmaxneg
 	PUBLIC Bzero
 	PUBLIC Bhalf
 	PUBLIC Bone
 	PUBLIC Btwo
	PUBLIC Bthree
 	PUBLIC Bfour
 	PUBLIC Bten
 	PUBLIC Bilmt
 	PUBLIC Bmaxfact
 	PUBLIC Bmax$num
 	PUBLIC Bminus$max$num
 	PUBLIC Binf
 	PUBLIC Bpi
 	PUBLIC Bpi$by$2
 	PUBLIC Blog$2
 	PUBLIC Blog$10
 	PUBLIC Bexpcoef
 	PUBLIC Bsincoef
 	PUBLIC Blogcoef
 	PUBLIC Batncoef
#endasm
#endif

#asm
;BCD math routines for 8080.
; changed 7/82 by jll to correct 2 errors in division
;	check for termination condition in subtract loop.
;	corrected check for exponent overflow.
; changed 7/82 by jll to set a global BERRFL for error conditions.
;	-1	for exponent overflow.
;	-2	for division by zero.
;	-3	for exponent underflow.
; changed 20/7/82 by jll to make division by zero check faster.
; changed 30/7/82 by jll to check for exponent underflow.
; changed 2/8/82 by jll to check for allignment in add.
; changed 3/8/82 by jll to make a special of addition of zero.
;

NB	EQU	8		;NUMBER OF BYTES IN A BCD NUMBER.
NBITS	EQU	NB*8		;NUMBER OF BITS.
NDI	EQU	16		;NUMBER OF BCD DIGITS IN AN INTEGER.
NDF	EQU	13		;number of digits in a FP mantisa.
BCDRET:	ds	NB		;BCD return address.
;
;
TRUE	EQU	-1
FALSE	EQU	0

;========================================================================
;
;
;	COPYN	-	Copy the BCD number pointed to by HL to the	;
;			area pointed to by DE.				;
;									;
;	ZERON	-	Set the BCD number pointed to by HL to 0.	;
;									;
;	ADDEXP	-	Add E to the exponent field of the BCD FP 	;
;			number pointed at by HL and store it.		;
;			EXP(HL) := EXP(HL) + DE				;
;									;
;	ADDEX	-	ADD E TO L AND CHECK FOR OVERFLOW.		;
;									;
;	RSH	-	SHIFT THE UNSIGNED BCD INTEGER POINTED TO BY    ;
;			HL RIGHT E DIGITS.				;
;									;
;	LSH	-	SHIFT THE UNSIGNED BCD INTEGER POINTED TO BY    ;
;			HL LEFT E DIGITS.				;
;									;
;	NORMU	-	NORMALIZE THE UNSIGNED INTEGER POINTED TO BY	;
;			HL.						;
;									;
;	NORM	-	NORMALIZE THE SIGNED INTEGER POINTED TO BY HL.	;
;									;
;									;
;=======================================================================;
;
;	COPYN - REG A  IS ALTERED.
;
COPYN:	PUSH	H		;SAVE HL
	PUSH	D		;SAVE DE
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	MOV	A,M
	STAX	D
	INX	H
	INX	D
	POP	D		;RESTORE DE.
	POP	H		;RESTORE HL.
	RET			;RETURN
;
;	ZERON - REG A  IS ALTERED.
;
ZERON:	PUSH	H		;SAVE HL
	XRA	A		;A<-0.
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	MOV	M,A
	INX	H
	POP	H		;RESTORE HL.
	RET			;RETURN
;
;	ADDEXP - REGS A,BC ARE ALTERED.
;
ADDEXP:	MOV	A,M		;GET OLD EXPONENT.
	ADD	E
	MOV	C,M
	MOV	M,A		;STORE THE NEW EXP.
	XRA	C		;NOW CHECK FOR OVERFLOW.
	MOV	B,A
	MOV	A,E
	XRA	M
	ANA	B
	ANI	80H
	RZ			;RETURN NOW WITH A=0 IF OK.
	PUSH	H
	LHLD	BERRFL		; CHANGE IFF NOT ALREADY SET.
	MOV	A,H
	ORA	L
	JNZ	JJ6
	ORA	C
	JP	JJ1
	LXI	H,0-1		; SET OVERFLOW ERROR.
	JMP	JL1
JJ1:	LXI	H,0-3		; SET UNDERFLOW ERROR.
JL1:	SHLD	BERRFL
JJ6:	POP	H
	RET
;
;	ADDEX - REGS A,BC ARE ALTERED.
;
ADDEX:	MOV	A,L
	ADD	E
	MOV	C,L
	MOV	L,A		;STORE THE NEW EXP.
	XRA	C		;NOW CHECK FOR OVERFLOW.
	MOV	B,A
	MOV	A,E
	XRA	L
	ANA	B
	ANI	80H
	RZ			;RETURN NOW WITH A=0 IF OK.
	PUSH	H
	LHLD	BERRFL		; CHANGE IFF NOT ALREADY SET.
	MOV	A,H
	ORA	L
	JNZ	JJ7
	ORA	C
	Jp	JJ2
	LXI	H,0-3		; Underflow.
	JMP	JJ3
JJ2:	LXI	H,0-1		; Overflow.
JJ3:	SHLD	BERRFL
JJ7:	POP	H
	MVI	A,1
	ANA	A		;OVERFLOW, A=1.
	RET
;
;	MULT8 -  HL:=D*E.
;
MULT8:	LXI	H,0
	INR	E
M81:	DCR	E
	RZ			;DONE
	MOV	A,D
	ADD	L
	MOV	L,A
	MOV	A,H
	ADI	0
	MOV	H,A
	JMP	M81
;
;	DIV8 -    HL := D/E	H = REMAINDER, L=QUOTIENT.
;
DIV8:	MVI	L,0
	MOV	A,D
DIV8A:	INR	L
	SUB	E
	JNC	DIV8A
	ADD	E
	DCR	L
	MOV	H,A
	RET
;
;	RSH - REGISTERS A,BC ARE ALTERED.
;
RSH:	MOV	A,E
	ADD	A
	ADD	A
	MOV	C,A		;C=NUMBER OF BITS TO BE SHITFED.
	PUSH	H
RSH1:	POP	H
	PUSH	H
	XRA	A
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	MOV	A,M
	RAR
	MOV	M,A
	INX	H
	DCR	C
	JNZ	RSH1
	POP	H
	RET
;
;	LSH - REGISTERS A,BC ARE ALTERED.
;
LSH:	LXI	B,NB
	DAD	B
	MOV	A,E
	ADD	A
	ADD	A
	MOV	C,A		;C=NUMBER OF BITS TO BE SHITFED.
	PUSH	H
LSH1:	POP	H
	PUSH	H
	XRA	A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCX	H
	MOV	A,M
	RAL
	MOV	M,A
	DCR	C
	JNZ	LSH1
	POP	B
	RET
;
;	NORMU - REGS A,BC,DE ARE ALTERED.
;
NORMU:	PUSH	H
	XRA	A
	ORA	M
	INX	H
	ORA	M
	INX	H
	ORA	M
	INX	H
	ORA	M
	INX	H
	ORA	M
	INX	H
	ORA	M
	INX	H
	ORA	M
	INX	H
	ORA	M
	INX	H
	POP	H
	JZ	NORE		;NUMBER IS ZERO, QUIT.
	MVI	D,0		;D=EXPONENT.
NU2:	INX	H
	MOV	A,M
	ANI	0F0H
	DCX	H
	ORA	M
	JZ	NU3		;BRANCH IF SIGN & EXPONENT ARE ZERO.
	MVI	E,1
	CALL	RSH		;SHIFT RIGHT ONE DIGIT.
	INR	D
	JMP	NU2		;TEST EXP & SIGN FOR ZERO.
NU3:	INX	H
	MOV	A,M
	DCX	H
	ANI	0FH
	JNZ	NU4		;DONE IF FIRST DIGIT NON-ZERO.
	MVI	E,1
	CALL	LSH		;LEFT SHIFT ONE DIGIT.
	DCR	D
	JMP	NU3		;CHECK FIRST DIGIT AGAIN.
NU4:	MOV	M,D		;STORE THE EXPONENT.
NORE:	RET
;
;	NORM - REGS A,BC,DE ARE ALTERED.
;
NORM:	INX	H
	MOV	A,M
	ANI	0F0H
	PUSH	PSW		;SAVE THE SIGN.
	MOV	A,M
	ANI	0FH
	MOV	M,A		;STRIP THE SIGN.
	DCX	H
	MVI	M,0		;ZERO THE EXPONENT.
	CALL	NORMU
	POP	B
	INX	H
	MOV	A,M
	ANA	A
	JZ	NORME		;BRANCH IF NUMBER IS ZERO.
	ORA	B
	MOV	M,A		;SET THE SIGN.
NORME:	DCX	H
	RET
;
;=======================================================================;
;									;
;                        BCD INTEGER SUPPORT ROUTINES			;
;									;
;	NEGI	-	Negate the BCD integer pointed to by HL.	;
;			(HL) := -(HL)					;
;									;
;	ADDI	-	Add the two BCD numbers pointed to by DE and HL ;
;			and leave the sum in HL.			;
;			(HL) := (HL)+(DE)				;
;									;
;	SUBI	-	Subtract the BCD number pointed to by HL from	;
;			the BCD number pointed at by DE and place the	;
;			result in (HL).					;
;			(HL) := (HL)-(DE)				;
;									;
;=======================================================================;
;
;	ADDI - REGISTERS BC & A ARE ALTERED.
;
ADDI:	LXI	B,NB-1
	XCHG
	DAD	B
	XCHG			;SET DE TO LAST BYTE.
	DAD	B		;SET HL TO LAST BYTE.
	LDAX	D
	ADD	M
	DAA
	MOV	M,A
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	LDAX	D
	ADC	M		;A := (DE)+(HL)+CARRY
	DAA
	MOV	M,A		;STORE IN (HL).
	RET
;
;	NEGI - REGISTERS BC & A ARE ALTERED.
;
NEGI:	MVI	B,099H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M		;A := 099H-(HL)
	MOV	M,A		;STORE IN (HL).
	INX	H
	MOV	A,B
	SUB	M
	ADI	1
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	DCX	H
	MOV	A,M
	ACI	0
	DAA
	MOV	M,A
	RET
;
;	SUBI - REGISTERS BC & A ARE ALTERED.
;
SUBI:	LXI	B,NB-1
	XCHG
	DAD	B
	XCHG			;SET DE TO LAST BYTE.
	DAD	B		;SET HL TO LAST BYTE.
	XCHG
	MVI	A,9AH
	SUB	M
	XCHG
	ADD	M
	DAA
	MOV	M,A
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	DCX	D
	DCX	H
	XCHG
	MVI	A,99H
	ACI	0
	SUB	M
	XCHG
	ADD	M		;A := (HL)-(DE).
	DAA
	MOV	M,A		;STORE IN (HL).
	RET
;
;
;=======================================================================;
;									;
;                    BCD FLOATING POINT SUPPORT ROUTINES		;
;									;
;	NEGF	-	Negate the BCD FP number pointed to by HL.	;
;			(HL) := -(HL)					;
;									;
;	ADDF	-	Add the two BCD numbers pointed to by DE and HL ;
;			and leave the sum in HL.			;
;			(HL) := (HL)+(DE)				;
;									;
;	SUBF	-	Subtract the BCD number pointed to by HL from	;
;			the BCD number pointed at by DE and place the	;
;			result in (HL).					;
;			(HL) := (HL)-(DE)				;
;									;
;	MULF	-	Multiply the two BCD FP numbers pointed at by	;
;			DE & HL.HL).	HL points to the product on 	;
;			return if no errors occured.			;
;									;
;	DIVF	-	Divide the BCD FP number pointed at by HL by	;
;			the BCD FP number pointed at by DE.  HL points	;
;			to the quotient on return if no errors occured. ;
;									;
;	NORMF	-	Normalize the floating point number pointed to  ;
;			by HL.						;
;			(HL) := NORMALIZE (HL)				;
;									;
;=======================================================================;
;
;	NEGF - reg A IS altered.
;
NEGF:	INX	H
	MOV	A,M
	XRI	90H		;FLIP THE SIGN DIGIT.
	MOV	M,A		;STORE IT.
	DCX	H
	XRA	A		;RETURN NO ERROR.
	RET
;
;	ADDF - regs A & BC,DE are altered.  (DE), (HL) ARE ALSO ALTERED.
;
ADDF:	PUSH	D
	INX	H
	MOV	B,M
	MOV	A,M
; check if number is zero.
	ANI	0FH
	jnz	notzero
	dcx	h
	pop	d
	xchg
	call	copyn
	xchg
	ret
notzero:
	MOV	M,A		;REMOVE THE SIGN.
	dcx	h
	MOV	E,M
	MVI	M,0		;SET EXP TO 0.
	XTHL
	push	d
	INX	H
	MOV	C,M
	MOV	A,M
	ANI	0FH
	jnz	notz2
	pop	d
	pop	h
	mov	m,e		;wheel exponent back in.
	inx	h
	mov	m,b		;and the sign.
	dcx	h
	ret
notz2:
	MOV	M,A		;REMOVE THE SIGN.
	DCX	H
	MOV	E,M
	MVI	M,0		;SET EXP TO 0.
	XTHL
;	changed by jll to test for lost significance.
	mov	a,e
	sub	l
	jp	pos
	cpi	80h
	jz	lost
	cma
	inr	a
pos:	cpi	0dh
	jm	aok
lost:
	mov	a,l
	cmp	e	; an 8080 signed >=
	jm	jlt	
	jpo	hlbig
	jmp	debig
jlt:	jpe	hlbig
debig:	mov	b,e
	pop	d
	pop	h
	xchg
	call	copyn
	xchg
	mov	m,b
	inx	h
	mov	m,c
	dcx	h
	ret
hlbig:
	pop	d
	pop	h
	mov	m,a
	inx	h
	mov	m,b
	dcx	h
	ret
aok:
	MOV	A,L
	SUB	E
	JZ	ADDF3
	MOV	A,L
	XRA	E
	JP	ADDFA		;BOTH SIGNS ARE ALIKE.
	MOV	A,L
	ANA	A
	JM	ADDF1		;EXP(X) < EXP(Y).
	JMP	ADDF0
ADDFA:	MOV	A,L
	CMP	E
	JM	ADDF1		;EXP(X) < EXP(Y).
ADDF0:	MOV	A,L
	SUB	E
	MOV	E,L
	POP	H
	JMP	ADDF2
ADDF1:	MOV	A,E
	SUB	L
	MOV	H,C
	MOV	C,B
	MOV	B,H
	POP	H
	XTHL
ADDF2:	PUSH	D
	PUSH	B
	MOV	E,A
	CALL	RSH
	POP	B
	POP	D
	PUSH	H
ADDF3:	POP	H
	MOV	A,C
	ANI	0F0H
	JZ	ADDF4
	PUSH	D
	PUSH	B
	CALL	NEGI
	POP	B
	POP	D
ADDF4:	XTHL
	MOV	A,B
	ANI	0F0H
	JZ	ADDF5
	PUSH	D
	CALL	NEGI
	POP	D
ADDF5:	XCHG
	XTHL
	CALL	ADDI
	MOV	A,M	
	ANI	0F0H
	JZ	ADDF6
	CALL	NEGI
	MVI	A,90H
ADDF6:	PUSH	PSW
	CALL	NORMU
	POP	PSW
	POP	D
	MOV	B,A
	INX	H
	MOV	A,M
	ANI	0FH
	DCX	H
	JZ	ADDFE
	INX	H
	ORA	B
	MOV	M,A
	DCX	H
	CALL	ADDEXP
ADDFE:	RET
;
;	SUBF - regs A & BC are altered.
;
SUBF:	XCHG			;X := X-Y
	CALL	NEGF		;Y := -Y
	CALL	ADDF		;X := X+(-Y)
	RET
;
;	MULF - REGS A,BC ARE ALTERED.
;
MULF:	PUSH	D
	MOV	E,M
	MVI	M,0		;SET EXP TO 0.
	INX	H
	MOV	A,M
	MOV	B,M
	ANI	0FH
	MOV	M,A		;ZERO THE SIGN.
	DCX	H
	XTHL
	PUSH	D
;	GETEXP	MOV	E,M
	mov e,m			; change hs 6/12/81
	MVI	M,0		;SET EXP TO 0.
	INX	H
	MOV	A,M
	MOV	C,M
	ANI	0FH
	MOV	M,A		;ZERO THE SIGN.
	DCX	H
	MOV	A,C
	XRA	B
	ANI	0F0H		;COMPUTE THE SIGN OF THE PRODUCT.
	MOV	B,A
	XTHL
	PUSH	B
	CALL	ADDEX
	JNZ	MERR3		; EXPONENT TROUBLES.
	POP	B
	POP	D
	XTHL
	PUSH	B
; MULTIPLY THE MANTISAS NOW.
	PUSH	H
	LXI	H,bcdret
	CALL	ZERON		;INITIALIZE THE PRODUCT.
	POP	H
	INX	H
	PUSH	H
	MOV	A,M
	ANI	0FH
	JZ	MULT2
	LXI	H,bcdret
MULT1:	PUSH	PSW
	CALL	ADDI
	POP	PSW
	DCR	A
	JNZ	MULT1
MULT2:	LXI	H,1
	XCHG
	CALL	RSH
	XCHG
	POP	H
	MVI	C,NB-2
MULT3:	PUSH	B
	INX	H
	PUSH	H
	MOV	A,M
	RAR
	RAR
	RAR
	RAR
	ANI	0FH
	JZ	MULT5
	LXI	H,bcdret
MULT4:	PUSH	PSW
	CALL	ADDI
	POP	PSW
	DCR	A
	JNZ	MULT4
MULT5:	LXI	H,1
	XCHG
	CALL	RSH
	XCHG
	POP	H
	PUSH	H
	MOV	A,M
	ANI	0FH
	JZ	MULT7
	LXI	H,bcdret
MULT6:	PUSH	PSW
	CALL	ADDI
	POP	PSW
	DCR	A
	JNZ	MULT6
MULT7:	LXI	H,1
	XCHG
	CALL	RSH
	XCHG
	POP	H
	POP	B
	DCR	C
	JNZ	MULT3
	LXI	H,bcdret
	CALL	NORMU
	POP	B
	POP	D
	INX	H
	MOV	A,M
	ANA	A
	JZ	MDONE		;QUIT IF NUMBER IS ZERO.
	ORA	B
	MOV	M,A		;SET THE SIGN.
	DCX	H
	CALL	ADDEXP
	INX	H
MDONE:	DCX	H
	RET
MERR3:	POP	H
	POP	H
	POP	H
	RET
;
;	DIVF - ALL REGS, (DE), (HL) ARE ALTERED.
;
; DIVF:	XCHG
DIVF:	INX	H
	MVI	A,0FH		; TAKE CARE OF -0.
	ANA	M
	DCX	H
	xchg
	JZ	DERR1		;DIVISION BY 0.
;INITIALIZE THE NUMBERS.
	PUSH	H
	LXI	H,bcdret
	CALL	ZERON
	XTHL
	XCHG
	INX	H
	MOV	A,M
	MOV	C,M
	ANI	0FH
	MOV	M,A
	DCX	H
	MOV	B,M
	MVI	M,0
	XCHG
	INX	H
	MOV	A,M
	XRA	C		;COMPUTE THE SIGN OF THE QUOTIENT.
	ANI	0F0H
	MOV	C,A
	MOV	A,M
	ANI	0FH
	MOV	M,A
	DCX	H
	MOV	A,M
	MVI	M,0
	XTHL
	INX	H
	MOV	M,C
	DCX	H
	MOV	C,A		;CALCULATE THE EXPONENT OF THE QUOTIENT.
	SUB	B
	MOV	M,A	; move exponent into answer.
	MOV	A,C		;CHECK FOR ARITHMETIC OVERFLOW.
	XRA	B
	ANI	080H
	JZ	EOK
	MOV	A,M
	XRA	C
	ANI	080H
	JZ	EOK
; EXPONENTS ARE SAME SIGN, QUOTIENT SIGN NOT SAME AS
; DIVIDEND SIGN.
	push	h
	LHLD	BERRFL		; CHANGE IFF NOT ALREADY SET.
	MOV	A,H
	ORA	L
	JNZ	JL4
	ORA	C
	JP	JJ4
	LXI	H,0-3			; UNDERFLOW.
	JMP	JJ5
JJ4:	LXI	H,0-1			; OVERFLOW.
JJ5:	SHLD	BERRFL
JL4:	POP	H		;CLEAR THE STACK.
	POP	H
	RET
EOK:	INX	H
	XTHL
	MVI	B,0
DIVF1:	MVI	C,255
DIVF2:	INR	C
; This loop is forced to terminate after 9 iterations.
	MOV	A,C
	CPI	09H
	JZ	DIVFF
	PUSH	B
	CALL	SUBI
	POP	B
	MOV	A,M
	ANI	0F0H
	JZ	DIVF2
	PUSH	B
	CALL	ADDI
	POP	B
DIVFF:	XTHL
	MOV	A,B
	ANI	1
	JNZ	DIVF3
	MOV	A,M
	ORA	C
	MOV	M,A		;STORE AS LOW ORDER DIGIT.
	INX	H
	JMP	DIVF4
DIVF3:	MOV	A,C
	RAL
	RAL
	RAL
	RAL
	ANI	0F0H
	MOV	M,A		;STORE AS HIGH ORDER DIGIT.
DIVF4:	XTHL
	INR	B
	MOV	A,B
	CPI	NDF
	JZ	DIVF5		;DONE.
	PUSH	B
	PUSH	H
	XCHG
	LXI	D,1
	CALL	RSH		;SHIFT Y RIGHT 1 DIGIT.
	XCHG
	POP	H
	POP	B
	JMP	DIVF1
DIVF5:	POP	H
	LXI	H,bcdret
	MOV	E,B
	CALL	NORMF
	RET
DERR1:	PUSH	H
	LHLD	BERRFL		; CHANGE IFF NOT ALREADY SET.
	MOV	A,H
	ORA	L
	JNZ	JJ8
	LXI	H,0-2		; DIVISION BY 0 ERROR.
	SHLD	BERRFL
JJ8:	POP	H
	RET
;
;	NORMF - regs A,BC & DE  are altered.
;
NORMF:	MOV	E,M
	PUSH	D
	MVI	M,0		;SET EXP TO 0.
	CALL	NORM
	POP	D
	INX	H
	MOV	A,M
	DCX	H
	ANI	0FH
	JZ	NORF1		;RESULT IS ZERO, EXIT.
	CALL	ADDEXP		;add the old exponent in.
NORF1:	RET
#endasm

#ifndef CINIT

#asm
;
;
; machine language initialized BCD constants
;
; Copyright (c) 1983  by SuperSoft, Inc.
;

;	DSEG

Bmaxneg:  db 04H,093H,027H,068H,00H,00H,00H,00H

Bzero:  db 00H,00H,00H,00H,00H,00H,00H,00H

Bhalf:  db 0FFH,05H,00H,00H,00H,00H,00H,00H

Bone:  db 00H,01H,00H,00H,00H,00H,00H,00H

Btwo:  db 00H,02H,00H,00H,00H,00H,00H,00H
 
Bthree:  db 00H,03H,00H,00H,00H,00H,00H,00H

Bfour:  db 00H,04H,00H,00H,00H,00H,00H,00H

Bten:  db 01H,01H,00H,00H,00H,00H,00H,00H

Bilmt:  db 01H,02H,00H,00H,00H,00H,00H,00H

Bmaxfact:  db 01H,08H,040H,00H,00H,00H,00H,00H

Bmax$num:  db 02H,02H,091H,081H,049H,063H,01H,056H

Bminus$max$num:  db 02H,092H,091H,081H,049H,063H,01H,056H

Binf:  db 07EH,09H,099H,099H,099H,099H,099H,099H

Bpi:  db 00H,03H,014H,015H,092H,065H,035H,089H

Bpi$by$2:  db 00H,01H,057H,07H,096H,032H,067H,094H

Blog$2:  db 0FFH,06H,093H,014H,071H,080H,055H,099H

Blog$10:  db 00H,02H,030H,025H,085H,09H,029H,094H

Bexpcoef:  db 00H,01H,045H,069H,099H,087H,050H,012H
 db 0FFH,092H,048H,076H,024H,033H,090H,052H
 db 0FEH,02H,014H,046H,055H,059H,094H,084H
 db 0FDH,091H,023H,057H,014H,08H,019H,098H
 db 0FBH,05H,034H,053H,05H,081H,079H,00H
 db 0FAH,091H,085H,06H,090H,071H,040H,00H
 db 0F8H,05H,034H,011H,087H,070H,00H,00H
 db 0F7H,091H,032H,015H,016H,00H,00H,00H
 db 0F5H,02H,086H,013H,00H,00H,00H,00H

Bsincoef:  db 00H,02H,055H,025H,057H,092H,048H,04H
 db 0FFH,092H,085H,026H,015H,069H,018H,010H
 db 0FDH,09H,011H,080H,016H,00H,066H,052H
 db 0FCH,091H,036H,058H,075H,013H,054H,020H
 db 0FAH,01H,018H,049H,061H,085H,080H,00H
 db 0F7H,096H,070H,027H,092H,00H,00H,00H
 db 0F5H,02H,066H,073H,00H,00H,00H,00H

Blogcoef:  db 0FFH,07H,052H,090H,056H,025H,083H,083H
 db 0FFH,03H,043H,014H,057H,050H,050H,076H
 db 0FEH,092H,094H,037H,025H,015H,022H,085H
 db 0FDH,03H,036H,070H,089H,025H,055H,064H
 db 0FCH,094H,033H,027H,058H,088H,061H,00H
 db 0FBH,05H,094H,070H,071H,019H,090H,00H
 db 0FAH,098H,050H,029H,067H,054H,010H,00H
 db 0FAH,01H,025H,04H,067H,036H,020H,00H
 db 0F9H,091H,087H,072H,079H,096H,00H,00H
 db 0F8H,02H,086H,030H,025H,010H,00H,00H
 db 0F7H,094H,042H,09H,057H,00H,00H,00H
 db 0F6H,06H,089H,056H,00H,00H,00H,00H
 db 0F6H,091H,08H,045H,010H,00H,00H,00H
 db 0F5H,01H,071H,076H,00H,00H,00H,00H
 db 0F4H,092H,073H,060H,00H,00H,00H,00H

Batncoef:  db 00H,01H,076H,027H,047H,017H,040H,039H
 db 0FFH,091H,05H,089H,029H,024H,054H,067H
 db 0FEH,01H,011H,035H,084H,020H,059H,040H
 db 0FDH,091H,038H,011H,095H,00H,036H,00H
 db 0FCH,01H,085H,074H,029H,073H,027H,090H
 db 0FBH,092H,062H,015H,019H,061H,013H,00H
 db 0FAH,03H,082H,010H,036H,059H,040H,00H
 db 0F9H,095H,069H,091H,086H,017H,00H,00H
 db 0F8H,08H,064H,088H,077H,090H,00H,00H
 db 0F8H,091H,033H,03H,038H,040H,00H,00H
 db 0F7H,02H,06H,085H,06H,00H,00H,00H
 db 0F6H,093H,024H,048H,060H,00H,00H,00H
 db 0F5H,05H,012H,080H,00H,00H,00H,00H
 db 0F4H,098H,015H,050H,00H,00H,00H,00H
 db 0F4H,01H,030H,040H,00H,00H,00H,00H
 db 0F3H,092H,09H,00H,00H,00H,00H,00H

;	CSEG

#endasm
#endif

double	*rval;

#define	BCDS	8

double *
doOp(dst, aa, bb, op)
/*	This routine does the call to the assembly language procs.
*/
 double	*dst;
 double	*aa;
 double	*bb;
 int	op;
{
#asm
bcdcal:	mov	h,b
	mov	l,c
	shld	jltmp1		; save register var
	pop	h		; return address
	shld	jltmp2
	pop	b		; opcode branch addr
	pop	d		; second operand
	lxi	h,adr
	xthl			; first oper <-> ret addr
	push	b		; branch address
	ret			; everything is relative

jltmp1:	ds	2
jltmp2:	ds	2

adr:	shld	rval		; save pointer to answer...
	push	h
	push	h
	push	h
	lhld	jltmp2		; restore ret addr
	push	h
	lhld	jltmp1		; restore register var
	mov	b,h
	mov	c,l
#endasm
	movmem(rval, dst, BCDS);
	return dst;
}
1H,033H,