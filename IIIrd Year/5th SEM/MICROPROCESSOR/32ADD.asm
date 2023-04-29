.MODEL SMALL
.386
.DATA
M  DB "ENTER FIRST NUMBER= $"
M2 DB 10,13,"ENTER SECOND NUMBER: $"
M3 DB 10,13,"SUM IS:$"

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
     
      JMP L6

L1:
      SUB AL,37H

L6:  SUB AL,30H
     SHL EBX,4
     ADD BL,AL
     LOOP AGAIN


    MOV DX,OFFSET M2
    MOV AH,09H 
    INT 21H
    
    
    MOV CX,8
    MOV EDX,0
 
AGAIN1:
  
      MOV AH,01H
      INT 21H
      CMP AL,'A'
      JGE L3
      SUB AL,30H
      JMP L4

L3:
      SUB AL,37H

L4:
     SHL EDX,4
     ADD DL,AL
     LOOP AGAIN1
 
ADD EBX,EDX
 
  MOV DX,OFFSET M3
  MOV AH,09H
  INT 21H
  JNC C 

     MOV DL,1
     ADD DL,30H
     MOV AH,02H
     INT 21H
C:      
 MOV CX,8
ASH:
    ROL EBX,4
    MOV DL,BL
    AND DL,0FH
    CMP DL,09H
    JG L8
    ADD DL,30H
    JMP L5

L8:
  ADD DL,37H
L5:
   
   MOV AH,02H
   INT 21H
   LOOP ASH

.EXIT 
END