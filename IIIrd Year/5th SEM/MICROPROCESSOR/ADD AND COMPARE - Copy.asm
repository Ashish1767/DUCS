.Model SMALL
.DATA
M1 DB"ENTER FIRST NUMBER=$"
M2 DB 10,13,"ENTER SECOND NUMBER$"
M3 DB 10,13,"SUM IS=$"
M4 DB 10,13,"SUM IS EQUAL$"
M5 DB 10,13,"SUM IS  NOT EQUAL$"
.CODE
.STARTUP
MOVE AX,@DATA
MOV DS,AX

MOV DX,OFFSET M1
MOV AH,09H
INT 21H

MOV AH,01H
INT 21H

MOV BL,AL
SUB BL,30H


MOV DX,OFFSET M2
MOV AH,09H
INT 21H

MOV AH,01H
INT 21H
SUB BH,30H

MOV CL,BL
ADD BL,CL
MOV AL,BL

 MOV AH,0H
 AAA
 
 
MOV BX,AX
ADD BX,3030H

MOV DX,OFFSET M3
MOV AH,09H
INT 21H

MOV DL,BH
MOV AH,02H
INT 21H

MOV DL,BL
MOV AH,02H
INT 21H



CMP BX,"A"
JE LABEL1

MOV DX,OFFSET M5
MOV AH,09H
INT 21H
JMP E

LABEL1:
MOV DX,OFFSET M4
MOV AH,09H
INT 21H

E:EXIT
END