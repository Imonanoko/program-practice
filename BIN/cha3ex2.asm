TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
    ASCVALUE	DB	  '3569'			;ASCII value
BINVALUE	DW	  0			;Binary sum
ASCLENTH	DW	  4			;ASCII length
MULTFACT	DW	  1			;1, 10, 100, ...

    .386
.code
A10MAIN	PROC   NEAR			;Main procedure
        mov ax,@data
        mov ds,ax
		MOV	  CX,04			;Count for loop
		LEA	  SI,ASCVALUE+3	;Address of ASCVALUE
A20:
		MOV	  AL,[SI]			;Select ASCII character
		AND	  AX,000FH		;Remove 3-zone
		MUL	  MULTFACT		;Multiply by 10 factor
		ADD	  BINVALUE,AX		;Add to binary
		MOV	  AX,MULTFACT		;Calculate next
		IMUL	  AX,10			;  10 factor
		MOV	  MULTFACT,AX
		DEC	  SI			;Last ASCII character?
		LOOP	  A20
A10MAIN ENDP
END A10MAIN