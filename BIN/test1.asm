TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
    list db '221'
         dw 1675,07  
    Price db 0,0,0,0,'$'
.386
.code
MAIN proc
	MOV AX,@data
    MOV DS,AX
    MOV ES,AX
    lea di,list+2
    inc di
    lea si,Price
    mov bx,[di]
    mov ax,0
    mov al,bh
    mov cx,10
    div cx
    or ax,3030h
    mov [si],al
    mov [si+1],ah
    add si,0812H
    mov ax,0
    mov al,bl
    div cx
    or ax,3030h
    mov [si],al
    mov [si+1],ah
    mov ah,09h
    lea dx,Price
    int 21h
    mov ax,4c00h
    int 21h

MAIN ENDP
	end MAIN