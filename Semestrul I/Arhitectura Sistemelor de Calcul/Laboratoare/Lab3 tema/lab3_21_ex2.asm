bits 32 

global start        
extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 45
    b dw 78
    c dd 32
    d dq 102
;d-a+(b+a-c) cu semn
segment code use32 class=code
    start:
        ;d-a
        mov al, [a]         ;AL = a
        cbw                 ;AX = a
        cwde                ;EAX = a
        cdq                 ;EDX:EAX = a
        sub [d], eax        ;
        sbb [d+4], dword 0  ;d = d - a
        
        ;b+a
        mov bx, [b]         ;BX = b
        add bx, ax          ;BX = a
        mov ax, bx          ;AX = b + a-c
        
        ;b+a-c
        cwde
        sub eax, [c]        ;EAX = EAX - c
        
        ;d-a+(b+a-c)
        add [d], eax
        add [d+4], dword 0  ;d = d + (b+a-c)
        
        mov eax, dword [d]
        mov edx, dword [d+4];EDX:EAX = d
        
        push    dword 0      
        call    [exit]       
