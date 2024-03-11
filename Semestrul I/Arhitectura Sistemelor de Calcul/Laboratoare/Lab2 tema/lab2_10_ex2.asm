bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data
    a db 17
    b db 5
    c db 11
    d db 9
segment code use32 class=code
    start:
        mov eax, 0
        mov al, [a]
        add al, [d]
        add al, [d]
        sub al, [c]
        add al, [b]
        add al, [b]
        
        push    dword 0      
        call    [exit]       
