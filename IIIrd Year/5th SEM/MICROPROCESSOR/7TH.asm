.MODEL SMALL
.data
 M1 db  "enter first no-$"
 M2 db 10,13,"enter second no-$"
 M3 db 10,13,"entered no are equal-$"
 M4 db 10,13,"entered no are not equal -$"
.code
.Startup
 
MOV AX,@DATA
MOV DS,AX

MOV DX,OFFSET M1
MOV AH,09H
INT 21H

MOV AH,01H
INT 21H
MOV CL,AL

MOV DX,OFFSET M2
MOV AH,09H
INT 21H

MOV AH,01H
INT 21H
MOV DL,AL

CMP CL,DL
JE LABEL1

MOV DX,OFFSET M4
MOV AH,09H
INT 21H
JMP E

LABEL1:
MOV DX,OFFSET M3
MOV AH,09H
INT 21H


E:EXIT
END