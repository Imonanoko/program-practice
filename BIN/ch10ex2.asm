TITLE	A10SELMU (EXE)  Select item from menu
		.MODEL SMALL
		.STACK 64
; -----------------------------------------------------
.DATA
	TOPROW EQU 08                                      	;Top row of menu
	BOTROW EQU 16                                      	;Bottom row of menu
	LEFCOL EQU 26                                      	;Left column of menu
	ATTRIB DB  ?                                       	;Screen attribute
	ROW    DB  00                                      	;Screen row
	SHADOW DB  32 DUP(0B2H)                            	;Shadow characters
	MENU   DB  0C9H, 20 DUP(0CDH), 0BBH
	       DB  0BAH, ' Add records        ', 0BAH
	       DB  0BAH, ' Delete records     ', 0BAH
	       DB  0BAH, ' Enter orders       ', 0BAH
	       DB  0BAH, ' Print report       ', 0BAH
	       DB  0BAH, ' Update accounts    ', 0BAH
	       DB  0BAH, ' View records       ', 0BAH
	       DB  0BAH, ' Exit from program. ', 0BAH
	       DB  0C8H, 20 DUP(0CDH), 0BCH
	PROMPT DB  'To select an item, use <Up/Down Arrow>'
	       DB  ' and press <Enter>.'
	       DB  13, 10, 'Press <Esc> to exit.'
	remind DB  ' press <F1> for a menu screen.'
.486                                               		; ------------------------------------------------
.CODE
A10MAIN PROC   FAR
	         MOV   AX, @data   	;Initialize segment
	         MOV   DS,AX       	;  registers
	         MOV   ES,AX
	         CALL  Q10CLEAR    	;Clear screen
	         CALL  OPENMENU		;展示按下F1會出現菜單的文字
	         MOV   ROW,BOTROW+4	;Set row
	A20:     
	         CALL  B10MENU     	;Display menu
	         MOV   ROW,TOPROW+1	;Set row to top item
	         MOV   ATTRIB,16H  	;Set reverse video
	         CALL  D10DISPLY   	;Highlight current menu line
	         CALL  C10INPUT    	;Provide for menu selection
	         Jmp   A20         	;  no, continue
	;mov ax,4c00h
	;int 21H
A10MAIN ENDP
	;			Display shadow box, next menu on top, then prompt
	;			  -------------------------------------------------
B10MENU PROC   NEAR
	         PUSHA             	;Preserve general registers
	         MOV   AX,1301H    	;Request display shadow box
	         MOV   BX,0060H    	;Page and attribute
	         LEA   BP,SHADOW   	;Shadow characters
	         MOV   CX,22       	;32 characters
	         MOV   DH,TOPROW+1 	;Top row of shadow
	         MOV   DL,LEFCOL+1 	;Left column of shadow
	B20:     INT   10H
	         INC   DH          	;Next row
	         CMP   DH,BOTROW+2 	;All rows displayed?
	         JNE   B20         	;  no, repeat
	         MOV   ATTRIB,71H  	;Blue on white
	         MOV   AX,1300H    	;Request display menu
	         MOVZX BX,ATTRIB   	;Page and attribute
	         LEA   BP,MENU     	;Menu line
	         MOV   CX,22       	;Length of line
	         MOV   DH,TOPROW   	;Row
	         MOV   DL,LEFCOL   	;Column
	B30:     
	         INT   10H
	         ADD   BP,22       	;Next menu line
	         INC   DH          	;Next row
	         CMP   DH,BOTROW+1 	;All rows displayed?
	         JNE   B30         	;  no, repeat

	         MOV   AX,1301H    	;Request display prompt
	         MOVZX BX,ATTRIB   	;Page and attribute
	         LEA   BP,PROMPT   	;Prompt line
	         MOV   CX,79       	;Length of line         ***
	         MOV   DH,BOTROW+4 	;Screen row,
	         MOV   DL,00       	;  column
	         INT   10H
	         POPA              	;Restore registers
	         RET
B10MENU ENDP
	;			   Accept keyboard request, Arrow and Enter
	;			   to select menu line, Esc to exit:
	;			   ----------------------------------------
C10INPUT PROC   NEAR
	         PUSHA             	;Preserve general registers
	C20:     MOV   AH,10H      	;Request one character
	         INT   16H         	;  from keyboard
;如果選到字首會等於按下對那行ENTER			 
.if al==68 || al==100      		;D
	         mov   ROW,10
	         CALL  EXEDISPLAY
.endif
.if al==65 || al==97 		;A
	      mov  ROW,9
	      CALL EXEDISPLAY
.endif
.if al==69 || al==101		;E
	      mov  ROW,11
	      CALL EXEDISPLAY
.endif
.if al==80 || al==112		;P
	      mov  ROW,12
	      CALL EXEDISPLAY
.endif
.if al==85 || al==117		;U
	      mov  ROW,13
	      CALL EXEDISPLAY
.endif
.if al==86 || al==118		;V
	      mov  ROW,14
	      CALL EXEDISPLAY
.endif
	           CMP   AH,50H      	;Down arrow?
	           JE    C30
	           CMP   AH,48H      	;Up arrow?
	           JE    C40
	           CMP   AL,0DH      	;Enter key?
	           JE    C90
	           CMP   AL,1BH      	;Escape key?
	           JE    C60
	           JMP   C20         	;None, retry
	C30:       MOV   ATTRIB,71H  	;Blue on white
	           CALL  D10DISPLY   	;Set old line to normal video
	           INC   ROW         	;Increment for next row
	           CMP   ROW,BOTROW-1	;Past bottom row?
	           JBE   C50         	;  no, ok
	           MOV   ROW,TOPROW+1	;  yes, reset
	           JMP   C50
	C40:       MOV   ATTRIB,71H  	;Blue on white
	           CALL  D10DISPLY   	;Set old line to normal video
	           DEC   ROW
	           CMP   ROW,TOPROW+1	;Below top row?
	           JAE   C50         	;  no, ok
	           MOV   ROW,BOTROW-1	;  yes, reset
	C50:       MOV   ATTRIB,17H  	;White on blue
	           CALL  D10DISPLY   	;Set new line to reverse video
	           JMP   C20
;按下ESC建會結束程式
	C60:       
	           CALL  Q10ENDCLEAR
	           MOV   AX,4C00H
	           INT   21H
	C90:       POPA              	;Restore registers
	           CALL  EXEDISPLAY		;展示現在選到什麼
	           RET
C10INPUT ENDP
	;			  Set menu line to highlight (if
	;			  selected) or normal (if not selected):
	;			  -------------------------------------
D10DISPLY PROC   NEAR
	           PUSHA             	;Preserve general registers
	           MOVZX AX,ROW      	;Row tells which line to set
	           SUB   AX,TOPROW
	           IMUL  AX,22       	;Multiply by length of line
	           LEA   SI,MENU+1   	;  for selected menu line
	           ADD   SI,AX
	           MOV   AX,1300H    	;Request display
	           MOVZX BX,ATTRIB   	;Page and attribute
	           MOV   BP,SI       	;Character string
	           MOV   CX,20       	;Length of string
	           MOV   DH,ROW      	;Row
	           MOV   DL,LEFCOL+1 	;Column
	           INT   10H
	           POPA              	;Restore registers
	           RET
D10DISPLY ENDP
	;			   Clear screen:
	;			   ------------
	;description
EXEDISPLAY PROC
	           PUSHA
	           MOVZX AX,ROW      	;Row tells which line to set
	           SUB   AX,TOPROW
	           IMUL  AX,22       	;Multiply by length of line
	           LEA   SI,MENU+1   	;  for selected menu line
	           ADD   SI,AX
	           MOV   AX,1300H
	           MOV   ATTRIB,17H
	           MOVZX BX,ATTRIB   	;Page and attribute
	           MOV   BP,SI       	;Character string
	           MOV   CX,20       	;Length of string
	           MOV   DH,3        	;Row
	           MOV   DL,27       	;Column
	           INT   10H
	           CMP   ROW,BOTROW-1	;判斷是否在最後一行按下ENTER
	           JE    ENDPRO			;跳轉到結束程式
	           POPA
	           RET
	ENDPRO:    
	           CALL  Q10ENDCLEAR
	           MOV   AX,4C00H
	           INT   21H
EXEDISPLAY ENDP
Q10CLEAR PROC   NEAR
	           PUSHA             	;Preserve general registers
	           MOV   AX,0600H
	           MOV   BH,61H      	;Blue on brown
	           MOV   CX,0000     	;Full screen
	           MOV   DX,184FH
	           INT   10H
	           POPA              	;Restore registers
	           RET
Q10CLEAR ENDP
Q10ENDCLEAR PROC   NEAR
	           PUSHA             	
	           MOV   AX,0600H
	           MOV   BH,0FH      	
	           MOV   CX,0000     	;Full screen
	           MOV   DX,184FH
	           INT   10H
	           POPA              	;Restore registers
	           RET
Q10ENDCLEAR ENDP
OPENMENU PROC
	           MOV   AX,0600H    	;  yes, end
	           CALL  Q10CLEAR    	;Clear screen
	           MOV   AX,1301H    	;Request display prompt
	           MOV   BX,0017H    	;Page and attribute
	           LEA   BP,remind   	;Prompt line
	           MOV   CX,30       	;Length of line
	           MOV   DH,3        	;Screen row,
	           MOV   DL,25       	;  column
	           INT   10H
	C21:       
	           MOV   AH,10H
	           INT   16H
	           CMP   AH,3BH
	           JE    C22
	           JMP   C21
	C22:       
	           CALL  Q10CLEAR
	           RET
OPENMENU ENDP
		END	  A10MAIN
