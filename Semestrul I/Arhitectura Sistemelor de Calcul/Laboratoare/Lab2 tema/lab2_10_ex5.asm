bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data
    a db 16
    b db 8
    c db 21
    d db 11
    e dw 4
    f dw 13
    g dw 17
    h dw 2
segment code use32 class=code
    start:
        mov eax, 0
        mov al, [a]
        mov ah, [d]
        mul ah
        mov bx, ax
        mov al, [b]
        mov ah, [c]
        mul ah
        add ax, bx
        
        push    dword 0      
        call    [exit]       
