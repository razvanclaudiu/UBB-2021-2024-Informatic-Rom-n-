bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data
    ; a db 10
    ; b db 20
    ; c db 10
    ; rez resb 1
    
    a db 240
    b db 20
    c db 1
    rez resb 1
    
; a+b/c
segment code use32 class=code
    start:
    
        mov al, [b]
        mov ah, 0   ;ax - b
        div byte[c] ; al - ax / c - b/c, ah- ax%c
        
        add al, [a]
        mov [rez], al
        
        push    dword 0      
        call    [exit]       
