.MODEL SMALL
.Data
M DB "ENTER THE NO$"
M2 DB 10,13,"YOU ENTERED THE NO= $"
.code
.startup
MOV AX,@Data
MOV DS,AX
MOV DX,OFFSET M
MOV AH,09H
INT 21H
  
MOV AH,01H
INT 21H


MOV DX,OFFSET M2
MOV AH,09H
INT 21H
MOV DL,AL
MOV AH,06H
INT 21H
.EXIT
END 
