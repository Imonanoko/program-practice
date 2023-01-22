TITLE	A14SPRED (EXE)  Spreadsheet arithmetic	
INITZ	MACRO				;Define macro
		MOV	  AX, @data	;Initialize segment
		MOV	  DS,AX		;  registers
		MOV	  ES,AX
		ENDM			;End macro
FINISH	MACRO				;Define macro
		MOV	  AX,4C00H	;End processing
		INT	  21H
		ENDM	
		.MODEL SMALL
		.STACK 64
; -----------------------------------------------
		.DATA
SPRD_TBL	DW	  05, 03, 06, 04, 10, 00  		;Data rows
		    DW	  04, 05, 01, 09, 06, 00
		    DW	  06, 02, 00, 10, 11, 00
		    DW	  10, 07, 03, 05, 02, 00
		    DW	  00, 00, 00, 00, 00, 00  		;Total row
COUNT	DB	  ?
COLS		EQU	  12				;6 cols X 2 bytes
ROWS		EQU	  10				;5 rows X 2 bytes
NOCOLS	EQU	  06				;No. of columns
NOROWS	EQU	  05				;No. of rows
COLTOT	EQU	  NOCOLS*(NOROWS-1)*2	;6 cols X 4 rows X 2
row db 0ah
.386  ; ------------------------------------------------
.CODE
A10MAIN	PROC	  FAR
		; MOV	  AX ,@data		;Initialize
		; MOV	  DS,AX			;  segment
		; MOV	  ES,AX			;  registers
		INITZ
		CALL	  B10HORZL		;Call horizontal addition
		CALL	  C10VERTL		;Call vertical addition
        CALL DealWith
        call Q10CLEAR
        lea bp,SPRD_TBL
        mov cx,05
a40:
        call display1
        inc row
        add bp,12
        loop a40
		; MOV	  AX,4C00H		;End processing
		; INT	  21H
		FINISH
A10MAIN	ENDP
;			  Add horizontal totals (rows):
B10HORZL	PROC	  NEAR
		PUSHA				;Preserve registers
		MOV	  COUNT,NOROWS-1	;Count to add row cells
		LEA	  DI,SPRD_TBL		;Initialize table
		LEA	  SI,SPRD_TBL		;  addresses
		ADD	  SI,ROWS
B10:		MOV	  CX,NOCOLS-1		;Count for columns
B20:		MOV	  AX,[DI]			;Get amount from cell
		ADD	  [SI],AX			;Add it to row total
		ADD	  DI,02			;Next cell in row
		LOOP	  B20			;Repeat thru all cells in row 		ADD	  DI,02			;First cell in next row
		ADD	  SI,COLS		;Next row total	
        add di,02
		DEC	  COUNT			;Repeat thru all rows
		JNZ	  B10			
		POPA				;Restore registers
		RET
B10HORZL	ENDP
;			  Add vertical totals (columns):
C10VERTL	PROC	  NEAR
		PUSHA				;Preserve registers
		MOV	  COUNT,NOCOLS-1	;Count to add column cells
		MOV	  BX,00
		LEA	  SI,[SPRD_TBL+COLTOT] 	;Initialize column total
C10:		LEA	  DI,SPRD_TBL		;Initialize top cell
		ADD	  DI,BX
		MOV	  CX,NOROWS-1		;Count for rows
C20:		MOV	  AX,[DI]			;Get amount from cell
		ADD	  [SI],AX			;Add it to column total
		ADD	  DI,COLS		;Next cell in column
		LOOP	  C20			;Repeat thru all cells in column
		ADD	  BX,02			;Next cell in row
		ADD	  SI,02			;Next column total
		DEC	  COUNT			;Repeat thru all cols
		JNZ	  C10
		POPA				;Restore registers
		RET
C10VERTL	ENDP
DealWith proc
    lea di,SPRD_TBL
    mov cx,30
    mov bl,0aH
aa10:
    mov ax,[di]
    div bl
    or ax,3030h
    mov [di],ax
    add di,02H
    loop aa10
    RET
DealWith endp
display1 proc   
        PUSHA
		mov ax,1301H
		mov bx,0061H
		mov cx,12
		mov dh,row
        mov dl,23h
		int 10H
        POPA
        RET
display1 endp
Q10CLEAR PROC   NEAR
	           MOV   AX,0600H
	           MOV   BH,61H      	;Blue on brown
	           MOV   CX,0000     	;Full screen
	           MOV   DX,184FH
	           INT   10H
	           RET
Q10CLEAR ENDP
		END	  A10MAIN
