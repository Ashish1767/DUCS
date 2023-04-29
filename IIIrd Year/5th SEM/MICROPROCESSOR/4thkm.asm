.Model SMALL
.data
m db 'Sum of the 3+4 is: $'
.code
.Startup
mov ax,@data
mov ds,ax

mov al,03H
mov bl,04H

add al,bl
add al,30H

lea dx,m
mov ah,09H
int 21H

mov dl,al
mov ah,02H
int 21H

.exit
end