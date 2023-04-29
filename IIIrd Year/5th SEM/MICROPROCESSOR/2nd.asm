.Model SMALL
.data
 .code
.Startup
MOV AX,@data
MOV DS,AX

MOV AH,01H
INT 21H
.EXIT
END
