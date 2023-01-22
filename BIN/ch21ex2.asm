TITLE	A21MACR2 (EXE)  Use of parameters
INITZ	MACRO			;Define macro
	MOV	  AX, @data	;Initialize segment
	MOV	  DS,AX		;  registers
	MOV	  ES,AX
	ENDM			;End macro
PROMPT	MACRO  MESSGE		;Define macro
	MOV	  AH,09H		;Request display
	LEA	  DX,MESSGE	;  prompt
	INT	  21H
	ENDM			;End macro
FINISH	MACRO	;RETCODE		;Define macro
	MOV	  ax,4C00H	;End processing
	; IFNB <RETCODE>
	; MOV AL,RETCODE
	; ELSE MOV AL,00H
	; ENDIF
	INT	  21H
	ENDM			;End macro
	.MODEL SMALL
	.STACK 64
	.DATA
MESSG1	DB	  'IYN?',0AH,0DH
MESSG2	DB	  'ASN', '$'
	.CODE
BEGIN	PROC	  FAR
	INITZ
	PROMPT MESSG1
	PROMPT MESSG2
	FINISH
BEGIN	ENDP
	END	  BEGIN
