bits 32 
global start        


extern exit           
import exit msvcrt.dll   
                     


segment data use32 class=data
    a db 7
    b dw 0abcdh     
    c dd 1234abcdh
    x db 0

segment code use32 class=code
    start:
        ; incarcarea unui registru cu o valoare imediata
        
        ; mov al, 7            ; AL=7
        ; mov al, 7h
        ; mov al ,111b
        
        ; INCORECT - AL are 8 biti, dar 256 are 9 biti
        ; mov eax, 0
        ; mov al, 256        
        
        ;mov ax, 256

        ; incarcarea adresei/offset unei variabile
        ; mov eax, a
        
        ; incarcarea valorii unei variabile
        ; mov eax, 0
        ; mov al, [a]
        
        mov ebx, 0
        ; INCORECT
        ; mov bl, [b]
        mov bx, [b]
        
        ; INCORECT 
        ; mov [x], [a]
        mov al, [a]
        mov [x], al
        
        push  dword 0      
        call  [exit]      