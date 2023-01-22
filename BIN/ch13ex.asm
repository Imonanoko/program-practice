TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
ASCVALUE1	DB	  '154032'		;ASCII data items
ASCVALUE2	DB	  '172633'
BCDVALUE1	DB	  '000'			;BCD data items
BCDVALUE2	DB	  '000'
BCDSUM	DB	  4 DUP(0)
.386
.code
main PROC
    mov ax,@data
    mov ds,ax
    mov es,ax
    LEA	  SI,ASCVALUE1+4	;Initialize for ASCVALUE1
	LEA	  DI,BCDVALUE1+2
	CALL   B10CONVRT		;Call convert routin
    LEA	  SI,ASCVALUE2+4	;Initialize for ASCVALUE2
	LEA	  DI,BCDVALUE2+2
	CALL   B10CONVRT		;Call convert routine
						;Add BCD numbers:
	XOR	  AH,AH		;Clear AH
	LEA	  SI,BCDVALUE1+2	;Initialize
	LEA	  DI,BCDVALUE2+2	;  BCD
	LEA	  BX,BCDSUM+3	;  addresses
	MOV	  CX,03			;3-byte fields
	CLC
    A20:		MOV	  AL,[SI]		;Get BCDVALUE1 (or LODSB) 
		ADC	  AL,[DI]		;Add BCDVALUE2
		DAA			;Decimal adjust
		MOV	  [BX],AL	;Store in BCDSUM
		DEC	  SI
		DEC	  DI
		DEC	  BX
		LOOP  A20		;Loop 3 times
        call maindisplay
        mov ax,4C00H
        int 21H
main ENDP
;			  Convert ASCII to BCD:
B10CONVRT	PROC
		MOV	  CX,03		;No. of words to convert
B20:		MOV	  AX,[SI]	              ;Get ASCII pair in reversed bytes
		XCHG      AH,AL
		SHL	  AL,04		;Shift off 
		SHL	  AX,04		;  ASCII 3s
		MOV	  [DI],AH		;Store BCD digits
		DEC	  SI
		DEC	  SI
		DEC	  DI
		LOOP	  B20		;Loop 3 times
		RET
B10CONVRT	ENDP
maindisplay PROC
    MOV	  AX,1300H		;Request display
		MOV	  BX,0031H		;Page and attribute
		LEA	  BP,BCDSUM	;ASCII line
		MOV	  CX,04			;Length of line
		MOV	  DX,1800H		;Row and column
		INT	  10H
        RET
maindisplay ENDP

    END main


