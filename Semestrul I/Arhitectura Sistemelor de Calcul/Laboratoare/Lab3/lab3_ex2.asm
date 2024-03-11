bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data
    a db 30
    b db 2
    c db 10
    rez resw 1
    
    ; a db 240
    ; b db 20
    ; c db 1
    ; rez resb 1
    
; a-b*c
segment code use32 class=code
    start:
    
        ;b*c
        mov al, [b]
        mov ah, 0   ; ax = b
        mul byte[c] ; ax = al * c
        
        ; a - b/c
        mov bl, [a] ; bl = a
        mov bh, 0 ; bx = a
        sub bx, ax ; bx = bx - ax 
        
        ; stocam rezultatul in memorie
        mov [rez], bx
        
        push    dword 0      
        call    [exit]       
