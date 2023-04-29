.Model SMALL
.data
message db'hello ASHISH HOW R U$'
.code
.Startup
MOV AX,@data  
MOV DS,AX
MOV DX,OFFSET message ; or LEA DX, message
MOV AH,09H
INT 21H
.EXIT
END
