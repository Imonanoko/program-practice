TITLE	A11EDIT (EXE)  Editing Features
		.MODEL SMALL
		.STACK 64
.DATA
	INDENT   EQU 24                      	;Screen indent
	LEFTLIM  EQU 00                      	;Left limit of data
	RIGHTLIM EQU 29                      	;Right limit of data
	NOCHARS  EQU 30                      	;Length of data
	COL      DB  00                      	;Screen column
	ROW      DB  10                      	;Screen row
	FRAME    DB  0C9H, 31 DUP(0CDH), 0BBH
	         DB  0C8H, 31 DUP(0CDH), 0BCH,0BAH
	DATASTR  DB  'abcdefghijklmno'       	;Area for editing data
	         DB  'pqrstuvwxyzABCD', 20H
.386                                 		; -------------------------------------------------
.CODE
A10MAIN PROC   FAR
	          MOV   AX, @data        	;Initialize segment
	          MOV   DS,AX            	;  registers
	          MOV   ES,AX
	          CALL  Q10CLEAR         	;Clear screen
	          CALL  Q20CURSOR        	;Set cursor start
	          CALL  Q20DISPLY        	;Display string
	A30:      
	          CALL  Q20CURSOR        	;Reset cursor start
	          CALL  B10KEYBRD        	;Get KB character
	          CMP   AH,01H           	;Escape key?
	          JNE   A30              	;  no, continue
	          MOV   AX,0600H         	;  yes, quit
	          CALL  Q10CLEAR         	;Clear screen
	          MOV   AX,4C00H         	;End of processing
	          INT   21H
A10MAIN ENDP
	;		Get keyboard character and determine action to take:
	;		----------------------------------------------------
B10KEYBRD PROC   NEAR            		;Uses AX only
	          MOV   AH,10H           	;Get
	          INT   16H              	;  character
	          CMP   AL,00H           	;Function/direction key?
	          JE    B20              	;  yes
	          CMP   AL,0E0H          	;Function/direction key?
	          JE    B20              	;  yes
	          CALL  H10CHARS         	;Other character
	          JMP   B90              	;Exit
	B20:      CMP   AH,4DH           	;Right arrow?
	          JNE   B30              	;  no
	          CALL  C10RTARRW        	;  yes, process
	          JMP   B90
	B30:      CMP   AH,4BH           	;Left arrow?
	          JNE   B40              	;  no
	          CALL  D10LFARRW        	;  yes, process
	          JMP   B90
	B40:      CMP   AH,53H           	;Delete key?
	          JNE   B50              	;  no
	          CALL  E10DELETE        	;  yes, process
	          JMP   B90
	B50:      CMP   AH,47H           	;Home key?
	          JNE   B60              	;  no
	          CALL  F10HOME          	;  yes, process
	          JMP   B90
	B60:      CMP   AH,4FH           	;End key?
	          JNE   B90              	;  no
	          CALL  G10END           	;  yes, process
	B90:      RET
B10KEYBRD ENDP
	;		Right arrow.  If at right edge, set cursor
	;		to left edge, else increment column:
	;		------------------------------------------
C10RTARRW PROC   NEAR
	          CMP   COL,RIGHTLIM     	;At rightmost edge?
	          JAE   C20              	;  yes,
	          INC   COL              	;  no, increment column
	          JMP   C90              	;  exit
	C20:      CALL  F10HOME          	;  cursor to left edge
	C90:      RET                    	;
C10RTARRW ENDP
	;		Left arrow.  If at left edge, set cursor
	;		to right edge, else decrement column:
	;		----------------------------------------
D10LFARRW PROC   NEAR
	          CMP   COL,LEFTLIM      	;At leftmost edge?
	          JBE   D20              	;  yes,
	          DEC   COL              	;  no, decrement column
	          JMP   D90              	;  exit
	D20:      CALL  G10END           	;  cursor to right edge
	D90:      RET
D10LFARRW ENDP
	;		Delete key.  Replace current character with one
	;		to right, shuffle rightmost characters to left:
	;		------------------------------------------------
E10DELETE PROC   NEAR            		;Uses BX, DI, SI
	          MOVZX BX,COL           	;Get column
	          PUSH  BX               	;Save for later
	          LEA   DI,[DATASTR+BX]  	;Init. present column
	          LEA   SI,[DATASTR+BX+1]	;  and adjacent column
	E20:      LODSB                  	;Store adjacent char
	          STOSB                  	;  in present column
	          CALL  Q40DISCHR        	;Display the char
	          INC   COL              	;Increment next column
	          CALL  Q20CURSOR        	;Set cursor
	          CMP   COL,RIGHTLIM     	;At right edge?
	          JBE   E20              	;  no, repeat
	          POP   BX               	;Get saved original
	          MOV   COL,BL           	;  column
	          RET
E10DELETE ENDP
	;		Home key.  Set cursor to left column:
	;		------------------------------------
F10HOME PROC	  NEAR
	          MOV   COL,LEFTLIM      	;Set cursor
	          CALL  Q20CURSOR        	;  at left edge
	          RET
F10HOME ENDP
	;		End key.  Set cursor to right column:
	;		------------------------------------
G10END PROC	  NEAR
	          MOV   COL,RIGHTLIM     	;Set cursor
	          CALL  Q20CURSOR        	;  at right edge
	          RET
G10END ENDP
	;		All other characters.  Bypass characters below
	;		20H and above 7EH, else insert at cursor:
	;		----------------------------------------------
H10CHARS PROC	  NEAR             		;Uses BX, DI
	          CMP   AL,20H           	;ASCII char below 20H?
	          JB    H90              	;  yes, bypass
	          CMP   AL,7EH           	;Above 7EH?
	          JA    H90              	;  yes, bypass
	          MOVZX BX,COL           	;Use COL as index
	          LEA   DI,DATASTR       	;Move character to
	          MOV   [DI+BX],AL       	;  data string
	          CALL  Q40DISCHR        	;Display the character
	          CMP   COL,RIGHTLIM     	;At right edge?
	          JAE   H90              	;  yes, exit
	          INC   COL              	;  no, increment column
	H90:      RET
H10CHARS ENDP
	;		Clear screen and set attribute:
	;		-------------------------------
Q10CLEAR PROC   NEAR
	          MOV   AX,0600H         	;Request scroll
	          MOV   BH,61H           	;Blue on brown
	          MOV   CX,0000          	;Full screen
	          MOV   DX,184FH
	          INT   10H
	          RET
Q10CLEAR ENDP
	;		Set cursor row: column:
	;		---------------------
Q20CURSOR PROC   NEAR
	          MOV   AH,02H           	;Request set cursor
	          MOV   BH,00            	;Page 0
	          MOV   DH,ROW           	;Row
	          MOV   DL,COL           	;Column
	          ADD   DL,INDENT        	;Indent on screen
	          INT   10H
	          RET
Q20CURSOR ENDP
	;		Display full data string:
Q20DISPLY PROC
	          MOV   AX,1301H
	          MOV   BX,0024H
			  LEA   BP,FRAME
			  MOV   CX,33
			  MOV   DH,ROW
			  SUB   DH,01H
			  MOV   DL,COL            	;
	          ADD   DL,INDENT-1
			  INT   10H
			  LEA   BP,FRAME+66
			  MOV   CX,01
			  MOV   DH,ROW
			  MOV   DL,COL            	;
	          ADD   DL,INDENT-1
			  INT 10H
			  LEA   BP,FRAME+66
			  MOV   CX,01
			  MOV   DH,ROW
			  MOV   DL,COL            	;
	          ADD   DL,INDENT+31
			  INT 10H
			  CALL  Q30DISPLY
			  MOV   AX,1301H
	          MOV   BX,0024H
			  LEA   BP,FRAME+33
			  MOV   CX,33
			  MOV   DH,ROW
			  ADD   DH,01H
			  MOV   DL,COL            	;
	          ADD   DL,INDENT-1
			  INT   10H
Q20DISPLY ENDP
Q30DISPLY PROC   NEAR
	          MOV   AX,1301H         	;Request display
	          MOV   BX,0016H         	;Page, attribute
	          LEA   BP,DATASTR       	;Data line
	          MOV   CX,NOCHARS+1     	;Length of line
	          MOV   DH,ROW           	;
	          MOV   DL,COL           	;
	          ADD   DL,INDENT        	;Indent on screen
	          INT   10H
	          RET
Q30DISPLY ENDP

	;		Display single character:
Q40DISCHR PROC   NEAR            		;Character in AL
	          MOV   AH,0AH           	;  on entry
	          MOV   BH,00            	;Page
	          MOV   CX,01            	;One character
	          INT   10H
	          RET
Q40DISCHR ENDP
		END	  A10MAIN
