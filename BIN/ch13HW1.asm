TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
	Save db 4 dup(' ')
    num1 db 4 DUP('0')
    num2 db 4 DUP('0')
    answer db 5 DUP('0')
    row db 0
    column db 1
	counter db 0
    .386
    .code
    MAIN proc
	mov ax,@data
	mov ds,ax
	mov es,ax
    call Q10CLEAR
	mov cx,0004h
	LEA di,Save
a10: 
	call Q20CURSOR
	mov ax,1000h
	int 16H
	cmp al,30h
	jb a20
	cmp al,39h
	ja a20
	inc counter
	mov [di],al
	inc di
	call Q20display
	loop a10
a20:
	cmp row,0h
	jne a30
	movzx cx,counter
	lea di,num1+3
	movzx dx,counter
	DEC DX
	lea si,Save
	add si,dx
lop1:
	mov AL,[si]
	mov [di],AL
	dec di
	dec si
	loop lop1
	call clearSave
	mov counter,00H
a30:mov column,1h
	inc row
	mov cx,0004h
	LEA di,Save
	cmp row,02H
	jne a10
A50:
	movzx cx,counter
	lea di,num2+3
	movzx dx,counter
	DEC DX
	lea si,Save
	add si,dx
lop3:
	mov AL,[si]
	mov [di],AL
	dec di
	dec si
	loop lop3
A40:
	call adder
	call Q30display	
	mov ax,4C00H
	int 21H
    MAIN endp
Q10CLEAR PROC   NEAR
	MOV   AX,0600H         	;Request scroll
    MOV   BH,61H           	;Blue on brown
	MOV   CX,0000          	;Full screen
	MOV   DX,184FH
	INT   10H
	RET
Q10CLEAR ENDP
Q20CURSOR PROC   NEAR
	           PUSHA
	           MOV   AH,02H           	;Request set cursor
	           MOV   BH,00            	;Page 0
	           MOV   DH,row          	;Row
	           MOV   DL,column           ;Column
	           INT   10H
	           POPA
	           RET
Q20CURSOR ENDP
Q20display proc
	PUSH cx
	MOV  AX,1301H			;Request display
	MOV  BX,0061H			;Page and attribute
	MOV  CX,04h			;Length of string
	; movzx dx,column
	lea bp,Save
	MOV  DH,ROW
	MOV  DL,01			;Row and column
	inc column
	INT  10H
	POP cx
	RET
Q20display endp
Q30display proc
	PUSHA
	MOV  AX,1301H			;Request display
	MOV  BX,0061H			;Page and attribute
	MOV  CX,05h			;Length of string
	lea bp,answer
	MOV  DH,ROW
	MOV DL,column
	INT  10H
	POPA
	RET
Q30display endp
clearSave proc
PUSHA
	lea di,Save
	mov cx,0004h
lop2:	
	mov [di],20H
	inc di
	loop lop2
	POPA
	RET
clearSave endp

adder proc
		CLC				;Add ASCII values:
		LEA	  SI,NUM1+3	;Initialize addresses
		LEA	  DI,NUM2+3	;  of ASCII numbers
		LEA	  BX,answer+4
		MOV	  CX,04			;Initialize 3 loops
AA20:		MOVZX  AX,[SI]		;Load ASCII byte in AX
		ADC	  AL,[DI]		;Add (with carry)
		AAA				;Adjust for ASCII
		MOV	  [BX],AL		;Store sum
		DEC	  SI
		DEC	  DI
		DEC	  BX
		LOOP   AA20			;Loop 3 times
		MOV	  	[BX],	  AH
		LEA	  BX,answer+4	;Convert ASCTOTAL
		MOV	  CX,05			;  to ASCII format
AA30:		
		OR	  BYTE PTR[BX],30H
		DEC	  BX
		LOOP   AA30
		RET
adder endp
    END MAIN