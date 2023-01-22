.MODEL SMALL
		.STACK 64
.CODE
.386					;Directive for MOVZX
A10MAIN	PROC   FAR
	MOV	AH, 10H	;request keyboard input
	INT	16H		;call interrupt service
	MOV	DX,AX
	MOV	AH,09H
	INT 	21H
	MOV	AH,4CH
	INT 	21H
A10MAIN ENDP
END A10MAIN