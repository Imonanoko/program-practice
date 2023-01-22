TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
T DW 3132h,3334h
TT db 31h,32h,33h,34h
.CODE
MAIN	PROC
		MOV AX,@data
        MOV DS,AX
        MOV ES,AX
		call Q10CLEAR
		lea di,T
		mov cx,02H
a10:		
		mov ax,[di]
		xchg ah,al
		mov [di],ax
		add di,02H
		loop a10
a20:
		lea bp,T
		mov ax,1301H
		mov bx,0061H
		mov cx,04
		mov dx,1823h
		int 10H
		mov ax,4C00H
		int 21h
MAIN	ENDP
Q10CLEAR PROC   NEAR
	           MOV   AX,0600H
	           MOV   BH,61H      	;Blue on brown
	           MOV   CX,0000     	;Full screen
	           MOV   DX,184FH
	           INT   10H
	           RET
Q10CLEAR ENDP
	END	MAIN
