TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
LEN_ENTRY EQU	  9				;Length of table entries
MONTH_IN	DB	  '12'			;ASCII '3132'
MONTH_TBL	DB	  'January  ', 'February ', 'March    '
		DB	  'April    ', 'May      ', 'June     '
		DB	  'July     ', 'August   ', 'September'
		DB	  'October  ', 'November ', 'December '
.386
.code
MAIN proc
        MOV AX,@data
        MOV DS,AX
        MOV ES,AX
        XOR	  WORD PTR MONTH_IN,3030H ;Clear ASCII 3s
		MOVZX  	  AX,MONTH_IN		;Multiply left digit
		IMUL	  AX,10			;  by 10 and add
		ADD	  AL,MONTH_IN+1		;  right digit
		; mov ax,01                                數字就是月份
;			  Locate month in table
		DEC	  AL			;Correct for table
		IMUL	  AX,LEN_ENTRY		;Multiply AL by 9
		LEA	  BP,MONTH_TBL		;Add offset to
		ADD	  BP,AX			;  address of table
;			  Display alpha month: 	;ES:BP already loaded
		MOV	  AX,1301H		;Request display
		MOV	  BX,0016H		;Page: attribute
		MOV	  CX,LEN_ENTRY		;9 characters
		MOV	  DX,0812H		;Row: column
		INT	  10H
MAIN ENDP
	end MAIN