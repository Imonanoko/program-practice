.MODEL SMALL
		.STACK 64
		.DATA
PARLIST	LABEL  BYTE		;Name parameter list:
MAXNLEN	DB	  30		;  maximum length of name
ACTULEN	DB	  ?		;  no. of characters entered
KBNAME	DB	  21 DUP(' ')	;  entered name 
PROMPT	DB	  'Name? ', '$'
studentid DB 'Student ID?','$'
askend DB 'To continue,press Y or y, then <Enter>','$'
;------------------------------------------------------- 
		.CODE
.386					;Directive for MOVZX
A10MAIN	PROC   FAR
		MOV	  AX, @data	;Initialize segment
		MOV	  DS,AX		;  registers
		MOV	  ES,AX
		CALL   	  Q10CLEAR	;Clear screen
A20:
		
		MOV	  DX,0000		;Set cursor to 00,00
		CALL   	  Q20CURSOR
		CALL      B10INPUT			;Provide for input of name
		CALL      Q20CLEAR			;Clear screen
		CMP	  ACTULEN,00		;Name entered? 
		JE	  A30			;  no, exit
		CALL      C10CENTER	;Set bell and '$' and center
		CALL      D10DISPLY		;Display name
		MOV	  DX,0000		;Set cursor to 00,00
		CALL      Q20CURSOR
		CALL      B20INPUT			;Provide for input of name
		CALL      Q20CLEAR			;Clear screen
		CMP	  ACTULEN,00		;Name entered? 
		JE	  A30			;  no, exit
		CALL      C20CENTER	;Set bell and '$' and center
		CALL      D10DISPLY		;Display name

		MOV	  DX,0000		;Set cursor to 00,00
		CALL   	  Q20CURSOR
		MOV	  AH,09H		;Request display
		LEA	  DX,askend
		INT	  21H
		MOV       AH,10H
		INT	  16H
		.IF 	  (AL==59H)||(AL==79H)
		CALL   	  Q20CLEAR
		JMP	  A20			;Repeat
		.ENDIF
A30:
		CALL   	  Q30CLEAR
		CALL   	  Q20CURSOR
		MOV	  AX,4C00H		;End processing
		INT	  21H
A10MAIN	ENDP
;			  Display prompt and accept input of name:
;			   --------------------------------------
B10INPUT	PROC   NEAR
		PUSH	  AX			;Preserve used
		PUSH	  DX			;  registers
		MOV	  AH,09H		;Request display
		LEA	  DX,studentid
		INT	  21H
		MOV	  AH,0AH		;Request keyboard
		LEA	  DX,PARLIST		;  input
		INT 	  21H	
		POP	  DX			;Restore
		POP	  AX			;  registers
		RET
B10INPUT	ENDP
B20INPUT	PROC   NEAR
		PUSH	  AX			;Preserve used
		PUSH	  DX			;  registers
		MOV	  AH,09H		;Request display
		LEA	  DX,PROMPT
		INT	  21H
		MOV	  AH,0AH		;Request keyboard
		LEA	  DX,PARLIST		;  input
		INT 	  21H	
		POP	  DX			;Restore
		POP	  AX			;  registers
		RET
B20INPUT	ENDP
;			   Set bell and '$' delimiter and 
;			     set cursor at center of screen:
;			   --------------------------------
C10CENTER	PROC   NEAR			;Uses BX and DX
		MOVZX  BX,ACTULEN		;Replace 0DH (<Enter>)
		MOV	  KBNAME[BX],07	;with 07H (bell)
		MOV	  KBNAME[BX+1],'$'	;Set display delimiter
		MOV	  DL,ACTULEN		;Locate center column:
		SHR	  DL,1			;  divide length by 2,
		NEG	  DL				;  reverse sign,
		ADD	  DL,40			;  add 40
		MOV	  DH,07			;Center row
		CALL   Q20CURSOR		;Set cursor
		RET
C10CENTER	ENDP
C20CENTER	PROC   NEAR			;Uses BX and DX
		MOVZX  BX,ACTULEN		;Replace 0DH (<Enter>)
		MOV	  KBNAME[BX],07	;with 07H (bell)
		MOV	  KBNAME[BX+1],'$'	;Set display delimiter
		MOV	  DL,ACTULEN		;Locate center column:
		SHR	  DL,1			;  divide length by 2,
		NEG	  DL				;  reverse sign,
		ADD	  DL,40			;  add 40
		MOV	  DH,08		;Center row
		CALL   Q20CURSOR		;Set cursor
		RET
C20CENTER	ENDP
;			  Display centered name:
;			  ---------------------
D10DISPLY	PROC   NEAR			;Uses AH and DX
		MOV	  AH,09H
		LEA	  DX,KBNAME		;Display name
		INT	  21H
		RET
D10DISPLY	ENDP
;			  Clear screen and set attribute:
;			   -----------------------------
Q10CLEAR	PROC   NEAR
		PUSHA			;Preserve general registers
		MOV	  AX,0600H		;Request scroll screen
		MOV	  BH,30			;Color attribute
		MOV	  CX,0000H		;From 00,00
		MOV	  DX,0C4FH		;  to 24,79
		INT	  10H 
		MOV	  AX,0600H		;Request scroll screen
		MOV	  BH,00H		;Color attribute
		MOV	  CX,0C00H		;From 12,00
		MOV	  DX,184FH
		INT	  10H
		POPA			;Restore general registers
		
		RET
Q10CLEAR	ENDP
Q20CLEAR	PROC   NEAR
		PUSHA			;Preserve general registers
		MOV	  AX,0600H		;Request scroll screen
		MOV	  BH,30			;Color attribute
		MOV	  CX,0000H		;From 00,00
		MOV	  DX,024FH		;  to 24,79
		INT	  10H 
		POPA			;Restore general registers
		
		RET
Q20CLEAR	ENDP
Q30CLEAR	PROC   NEAR
		PUSHA			;Preserve general registers
		MOV	  AX,0600H		;Request scroll screen
		MOV	  BH,07H			;Color attribute
		MOV	  CX,0000H		;From 00,00
		MOV	  DX,184FH		;  to 24,79
		INT	  10H 
		POPA			;Restore general registers
		
		RET
Q30CLEAR	ENDP
;			  Set cursor row, column:
;			   ---------------------
						;DX set on entry
Q20CURSOR	PROC   NEAR			;Uses AH and BH
		MOV	  AH,02H		;Request set cursor
		MOV	  BH,00			;Page #0
		INT	  10H
		RET
Q20CURSOR	ENDP
		END	  A10MAIN
