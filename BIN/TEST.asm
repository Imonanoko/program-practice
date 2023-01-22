
.MODEL SMALL
.STACK 64
.DATA
    s db 41h,'$'
    Column db 0
    row db 0
    time db 0
.386                                       ; -------------------------------------------------
.CODE
A10MAIN PROC   FAR    
    mov ax,@data
    mov ds,ax 
    mov es,ax
    MOV   AX,0600H        
	MOV   BH,61H         
	MOV   CX,0000          
	MOV   DX,184FH
	INT   10H
    
    lea di,s
    mov cx,255
    mov bx,0000h
; lop:
    call display1
    inc bx
    mov [di],bx
    ; loop lop

    mov ax,4c00h
    int 21h
A10MAIN ENDP
display1 PROC
    PUSHA
    lea bp,s
    mov ax,1301H
    mov bx,0024H
    mov cx,1
    mov ah,row
    mov al,Column
    int 10h
    inc time
    cmp time ,0010h
    JnE out1
    inc row
    mov time,00h
out1:
    POPA
    RET
display1 ENDP
		END	  A10MAIN

