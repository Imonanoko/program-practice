TITLE	A11EDIT (EXE)  Editing Features
		.MODEL SMALL
		.STACK 64
.DATA
TEN DB 10
displayPrime DB '< The prime number under 100:>'
prime DB 300 DUP(' ')
SAVESPACE DB 00
.386                                      		; -------------------------------------------------
.CODE
A10MAIN PROC   FAR
    mov ax,@data
    mov DS,ax
    mov es,ax
    MOV CX,99
    MOV BX,0002H
A20:
    CALL ISPRIME
    INC BX
    CMP BX,0100
    JE A50
    LOOP A20
A50:
    mov ax,1301H
    lea BP,prime
    mov cx,100
    mov bx,000fH
    mov dx,1800h
    int 10H
    MOV AX,4C00H
    INT 21H
A10MAIN ENDP
;--------------------------------
ISPRIME PROC NEAR
    PUSHA
    MOV DX,0002H
A10:
    CMP DX,BX
    JE A30
    MOV AX,BX
    DIV DL
    CMP AH,00H
    JE A40
    CMP AL,DL
    JBE A30
    INC DX
    JMP A10
A30:
    PUSH bx
    MOVZX bx,SAVESPACE
    LEA DI,[prime+bx]
    pop bx
    ADD SAVESPACE,4
    MOV AX,BX
    DIV TEN
    XOR AX,3030H
    cmp al,30H
    JE d10
    MOV [DI],AL
d10:
    MOV [DI+1],AH
    
A40:
    POPA
    RET
ISPRIME ENDP
END A10MAIN