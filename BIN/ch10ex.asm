TITLE	A10KBSTA (EXE)  Testing Alt, Shift, & Ctrl Status
		.MODEL SMALL
		.STACK 64
		.DATA
BIODATA	SEGMENT AT 40H		;Locate BIOS data area
		ORG  17H			;  and
KBSTATE	DB  ?				;  status byte
BIODATA	ENDS

CR		EQU  0DH			;Carriage return
LF		EQU  0AH			;Line feed
ROW     DB   ?
COLOR1   DB   ?
ALTKEY	DB	'       Alt key pressed ', CR, LF
CTRLKEY	DB	'    Ctrl key pressed   ', CR, LF
SHIFTKEY	DB	' Shift key pressed     ', CR, LF
remind	DB	  0C9H, 78 DUP(0CDH), 0BBH
		DB 0BAH,'  Press SHIFT or ALT or CTRL KEY, then press any key to show keyboard status. ', 0BAH
		DB	  0C8H, 78 DUP(0CDH), 0BCH,'$'
.286  ; ------------------------------------------------------
		.CODE
A10MAIN	PROC FAR
        CALL Q10CLEAR
		LEA BP,remind
		CALL D20DISPLAY
		MOV  AX,BIODATA		;Initialize segment address
		MOV  ES,AX			;  of BIODATA in ES
A20:	
		MOV  AH,10H			;Request keyboard entry
		INT  16H
		CMP  AL,0DH			;User requests end?
		JE   A90				;  yes, exit
		MOV  BL,ES:KBSTATE		;Get keyboard status byte
		TEST BL,00000011B		;Shift + char pressed?
		JZ   A30				;  no, bypass
		MOV  ROW,10H
		MOV  COLOR1,16H
		LEA  BP,SHIFTKEY		;Request display
		CALL D10DISPLY		;  shift message
A30:		TEST BL,00000100B		;Ctrl + char pressed?
		JZ   A40				;  no, bypass
		MOV  ROW,11H
		MOV  COLOR1,42H
		LEA  BP,CTRLKEY		;Request display
		CALL D10DISPLY		;  ctrl message
A40:		TEST BL,00001000B		;Alt + char pressed?
		JZ   A20				;  no, bypass
		LEA  BP,ALTKEY			;Request display
		MOV  ROW,12H
		MOV  COLOR1,25H
		CALL D10DISPLY		;  alt message
		JMP  A20			;Repeat
A90:		MOV  AX,4C00H			;End processing
		INT  21H
A10MAIN	ENDP
;			Display message for Alt, Ctrl, and 
;				Shift if key is pressed.
D10DISPLY	PROC NEAR			;BP set on entry
		PUSHA				;Preserve registers
		PUSH ES
		MOV  AX, @data			;Set up for ES:BP
		MOV  ES,AX			;  for address of data
		MOV  AX,1301H			;Request display
		MOV  BH,00H			;Page and attribute
		MOV  BL,COLOR1
		MOV  CX,25			;Length of string
		MOV  DH,ROW
		MOV  DL,08H			;Row and column
		INT  10H
		POP  ES
		POPA				;Restore registers
		RET
D10DISPLY	ENDP
D20DISPLAY PROC NEAR
		PUSHA				;Preserve registers
		PUSH ES
		MOV  AX, @data			;Set up for ES:BP
		MOV  ES,AX			;  for address of data
		MOV  AX,1301H			;Request display
		MOV  BX,0007H			;Page and attribute
		MOV  CX,240				;Length of string
		MOV  DX,0000H			;Row and column
		INT  10H
		POP  ES
		POPA				;Restore registers
		RET
D20DISPLAY ENDP
Q10CLEAR	PROC   NEAR
		PUSHA			;Preserve general registers
		MOV	  AX,0600H		;Request scroll screen
		MOV	  Bh,01100000b		;Color attribute
		MOV	  CX,0000H		;From 12,00
		MOV	  DX,184FH
		INT	  10H
		POPA			;Restore general registers
		
		RET
Q10CLEAR	ENDP
		END  A10MAIN