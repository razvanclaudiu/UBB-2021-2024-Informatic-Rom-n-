bits 32 ; 
global start        


extern exit                
import exit msvcrt.dll   process. It is defined in msvcrt.dll
    

segment data use32 class=data
    a dw 0111011101010111b
    b dw 1001101110111110b
    c dw 0
; Se dau cuvintele A si B. Se cere cuvantul C format astfel:
;- bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
;- bitii 3-6 ai lui C au valoarea 1
;- bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
;- bitii 11-12 ai valoarea 0
;- bitii 13-15 ai lui C concid cu inverul bitilor 9-11 ai lui B

segment code use32 class=code
    start:
    
        ; formam cuvantul C in registrul bx
        mov bx, 0
        
        ;- bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
        mov ax, [b]     ; AX = b
        and ax, 00001110000000000b      ; izolez bitii 10-12
        mov cl, 10
        ror ax, cl      ; am deplasat
        or bx, ax       ; concatenez la C
        
        ;- bitii 3-6 ai lui C au valoarea 1
        or bx, 0000000001111000b
        
        
        ;- bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui 
     
        
        push    dword 0     
        call    [exit]      
