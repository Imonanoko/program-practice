TITLE	A14ASCHX (EXE)  Display ASCII and hex characters
		.MODEL SMALL
		.STACK 64
		.DATA
ROW		DB	  02
DISPROW	DB	  16 DUP(5 DUP(' '))
HEXCTR		DB	  00
XLATAB		DB	  30H,31H,32H,33H,34H,35H,36H,37H,38H,39H
		DB	  41H,42H,43H,44H,45H,46H
.386  ; --------------------------------------------------
		.CODE
A10MAIN	PROC	  NEAR				;Main procedure
		MOV	  AX, @data		;Initialize
		MOV	  DS,AX			;  addressing
		MOV	  ES,AX
		CALL	  Q10CLEAR		;Clear screen
		LEA	  SI,DISPROW		;Init'ze display row
A20:
		CALL   	  B10HEX			;Translate
		CALL   	  C10DISPLY 		;  and display
		CMP	  HEXCTR,0FFH		;Last hex value (FF)?
		JE	  A90			;  yes, exit
		INC	  HEXCTR		;  no,  incr next hex
		JMP	  A20
A90:		MOV	  AX,4C00H		;End processing
		INT	  21H
A10MAIN	ENDP
;			  Convert ASCII to hex:
B10HEX	PROC   NEAR
		MOVZX 	  AX,HEXCTR		;Get hex pair in AX
		SHR	  AX,04			;Shift off right hex digit
		LEA	  BX,XLATAB		;Set table address
		XLAT				;Translate hex
		MOV	  [SI],AL			;Store left character
						;  in display row
		MOV	  AL,HEXCTR
		AND	  AL,0FH			;Clear left hex digit
		XLAT					;Translate hex
		MOV	  [SI]+1,AL		;Store right character
		RET
B10HEX	ENDP
;			  Display as hex characters:
C10DISPLY	PROC   NEAR
		MOV	  AL,HEXCTR		;Get character
		MOV	  [SI]+3,AL
		CMP	  AL,07H			;Lower than 7?
		JB	  C20			;  yes, ok
		CMP	  AL,10H			;Higher/equal 16?
		JAE	  C20			;  yes, ok
		MOV	  BYTE PTR [SI]+3,20H  	;Else force blank
C20:
		ADD	  SI,05			;Next location in row
		LEA	  DI,DISPROW+80
		CMP	  DI,SI			;Filled up row?
		JNE	  C90			;  no, exit
		MOV	  AX,1300H		;Request display
		MOV	  BX,0031H		;Page and attribute
		LEA	  BP,DISPROW		;Data
		MOV	  CX,80			;Length of line
		MOV	  DH,ROW		;Row
		MOV	  DL,00			;Column
		INT	  10H
		INC	  ROW			;Next row
		LEA	  SI,DISPROW		;Reinitialize
C90:		RET
C10DISPLY	ENDP
;			  Clear screen:
Q10CLEAR	PROC   NEAR
		MOV	  AX,0600H		;Request scroll
		MOV	  BH,61H			;Attribute
		MOV	  CX,0000
		MOV	  DX,184FH
		INT	  10H
		RET
Q10CLEAR	ENDP
		END	  A10MAIN
