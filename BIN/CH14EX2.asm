TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
    LEN_ENTRY EQU	  9				;Length of table entries
DAYOFMON	DW	  00			;
SAVEDAY	DB	  ?			;
SAVEMON	DB	  ?			;
TEN		DB	  10
ROW		DB	  10			;Screen row
COLUMN		DB	  30			;  and column
DAYS_TBL	DB	  'Sunday   ', 'Monday   '
		DB	  'Tuesday  ', 'Wednesday'
		DB	  'Thursday ', 'Friday   '
		DB	  'Saturday '
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
        MOV    AH,2AH			;Get today's date
		INT    21H
		MOV    SAVEMON,DH		;Save month
		MOV    SAVEDAY,DL		;Save day of month
;		Display day of week:
		MOV	  AH,0			;-------------------
		IMUL   AX,LEN_ENTRY		;Day x entry length
		LEA    BP,DAYS_TBL		;Address of table
		ADD    BP,AX			;  plus offset
		MOV    CX,LEN_ENTRY	;Length
		CALL   B10DISPLY		;
;		Display month:
		MOVZX  AX,SAVEMON		;-------------
		DEC    AX			;Decrement month by 1
		IMUL   AX,LEN_ENTRY		;Month x entry length
		LEA    BP,MONTH_TBL		;Address of table
		ADD    BP,AX			;  plus offset
		MOV    CX,LEN_ENTRY	;Length
		CALL   B10DISPLY
        MOVZX  AX,SAVEDAY		;--------------------
		DIV    TEN			;Convert day from
		OR     AX,3030H		;  binary to ASCII
		MOV    DAYOFMON,AX		;Save ASCII day
		LEA    BP,DAYOFMON		;
		MOV    CX,2			;No. of characters
		CALL   B10DISPLY		;
;			  Common display routine:
		mov ax,4c00h
		int 21h
MAIN ENDP
B10DISPLY       PROC   NEAR			;BP, CX set on entry
		PUSHA				;Preserve registers
		MOV    AX,1301H		;Request display
		MOV    BX,0016H		;Page: attribute
		MOV    DH,ROW		;Screen row
		MOV    DL,COLUMN		;  and column
		INT    10H
		INC    ROW			;Next row
		POPA				;Restore registers
		RET
B10DISPLY       ENDP

	end MAIN