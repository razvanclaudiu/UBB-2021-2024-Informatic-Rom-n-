bits 32 

global start        
extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 34
    b dw 1543
    c dd 670
    d dq 1130
    x resq 0
; (c-a) + (b - d) + d  fara semn
segment code use32 class=code
    start:
        ;c-a
        mov eax, [c]        ;EAX = c
        mov edx, 0          ;
        mov dl, [a]         ;EDX = a
        sub eax, edx        ;EAX = c-a
        
        ;x = c-a
        mov edx, 0          ;EDX:EAX = c-a
        mov [x], eax        ;
        mov [x+4], edx      ;x = c-a
        
        ;b-d
        mov eax, 0          ;
        mov ax, [b]         ;EAX = b
        mov edx, 0          ;EDX:EAX = b
        mov ebx, dword [d]  ;
        mov ecx, dword [d+4];ECX:EBX = d
        sub eax, ebx        ;
        sbb edx, ecx        ;EDX:EAX = b-d
        
        ;(c-a) + (b - d)
        add [x], eax        ;
        adc [x+4], edx      ;x = x + (b - d) = (c - a) + (b - d)
        
        ; (c-a) + (b - d) + d
        add ebx, dword [x]
        add ecx, dword [x+4]      ; ECX:EBX = ECX:EBX  + d 
        
        push    dword 0      
        call    [exit]       
