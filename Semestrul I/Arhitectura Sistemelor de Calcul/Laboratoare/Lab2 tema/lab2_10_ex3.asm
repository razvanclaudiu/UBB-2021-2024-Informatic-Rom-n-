bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data
    a dw 31
    b dw 6
    c dw 13
    d dw 25
segment code use32 class=code
    start:
        mov eax, 0
        mov ax, [b]
        add ax, [c]
        add ax, [d]
        add ax, [a]
        sub ax, [d]
        sub ax, [c]
        
        push    dword 0      
        call    [exit]       
