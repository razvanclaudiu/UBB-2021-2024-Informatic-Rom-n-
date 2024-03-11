bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data
    a db 6
    b db 15
    c db 3
    d dw 19
segment code use32 class=code
    start:
        mov eax, 0
        mov al, [b]
        sub al, [a]
        add al, 2
        mov ah, 20
        mul ah
        mov bx, ax
        mov al, [c]
        mov ah, 10
        mul ah
        sub bx, ax
        mov ax, bx
        mov bx, 3
        mul bx
        mov bx, 5
        div bx
       
        push    dword 0      
        call    [exit]       
