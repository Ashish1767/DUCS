
.MODEL SMALL
.386
.DATA
M DB" ENTER FIRST NUMBER= $"

.CODE
.STARTUP

  MOV AX,@DATA
  MOV DS,AX
    
  MOV DX,OFFSET M
  MOV AH,09H
  INT 21H
    MOV EBX,0
  MOV CX,8

 
  
AGAIN:
  
MOV AH,01H
INT 21H
CMP AL,'A'
JGE L1
SUB AL,30H
JMP L6

L1:
SUB AL,37H

L6:
SHL EBX,4
ADD BL,AL
LOOP AGAIN




.EXIT 
END