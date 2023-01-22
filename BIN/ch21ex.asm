TITLE	A21MACR1 (EXE)  Simple macro to initialize
INITZ	MACRO				;Define macro
		MOV	  AX, @data	;Initialize segment
		MOV	  DS,AX		;  registers
		MOV	  ES,AX
		ENDM			;End macro
FINISH	MACRO				;Define macro
		MOV	  AX,4C00H	;End processing
		INT	  21H
		ENDM			;End macro
		.MODEL SMALL
		.STACK 64
		.DATA
MESSGE	DB	  		'Test of macro instruction', 13, 10, '$'
		.CODE
BEGIN	PROC   FAR
		INITZ			;Macro instruction
		MOV	  AH,09H	;Request display
		LEA	  DX,MESSGE	;Message
		INT	  21H
		FINISH
BEGIN	ENDP
		END	  BEGIN
