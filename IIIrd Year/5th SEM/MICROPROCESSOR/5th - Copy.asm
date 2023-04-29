.Model SMALL
.data
m db 'Sum is: $'
.code
.Startup
mov ax,@data
mov ds,ax

mov bx,0202H
mov cx,0404H

add bx,cx
add bx,3030H

lea dx,m
mov ah,09H
int 21H

mov dl,bh
mov ah,02H
int 21H

mov dl,bl
mov ah,02H
int 21H

.exit
end