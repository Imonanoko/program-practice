TITLE  A04ASM2
	.MODEL  SMALL
	.STACK   64
	.DATA
    LEN_STKNO EQU	  02			;Length stock no.
LEN_DESCR EQU	  10			;  and description
STOCKN_IN	DB	  '12'			;Input stock no.
STOCK_TBL	DB	  '05','Excavators'	;Start of table
		DB	  '10','Lifters   '		;
		DB	  '12','Presses   '		;
		DB	  '15','Valves    '		;
		DB	  '23','Processors'	;
		DB	  '27','Pumps     '	;End of table

.386
.code
MAIN proc
	MOV AX,@data
        MOV DS,AX
        MOV ES,AX
        MOV	  CX,06			;Initialize compares
		LEA	  SI,STOCK_TBL
A20:
		MOV	  AL,STOCKN_IN
		CMP	  AL,[SI]			;Stock#(1) : table
		JNE	  A30
        MOV	  AL,STOCKN_IN+1	;Equal:
		CMP	  AL,[SI+1]		;  stock#(2) : table+1
		JE	  A50			;  equal, found
A30:		JB	  A40			;Low, not in table
		ADD	  SI,LEN_STKNO	;High, get 
		ADD	  SI,LEN_DESCR	;  next entry
		LOOP   A20
A40:						;Not in table, display 
;		...				;  error message
		JMP	  A90			;  and exit
A50:
		INC	  SI
		INC	  SI			;Extract description
		MOV	  AX,1301H		;Request display
		MOV	  BP,SI			;Stock description
		MOV	  BX,0061H		;Page: attribute
		MOV	  CX,LEN_DESCR	;10 characters
		MOV	  DX,0812H		;Row: column
		INT	  10H
A90:					; <Display error message>
MAIN ENDP
	end MAIN