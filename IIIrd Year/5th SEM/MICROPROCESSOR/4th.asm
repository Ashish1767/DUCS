.model small
.data
m db "sum of 4 and 5 is= $"
.code
.startup
mov ax,@data
mov ds,ax
 
mov al,04h
mov bl,05h

add al,bl
add al,30h

 mov dx,offset m
 mov ah,09h
 int 21h
 mov dl,al
 mov ah,02h
 int 21h
 .exit
 end