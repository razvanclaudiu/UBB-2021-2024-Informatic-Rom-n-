bits 32 

global start        
extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 45
    b dw 78
    e dd 99
    x dq 50
    temp resd 0
;(a*a/b+b*b)/(2+b)+e-x cu semn
segment code use32 class=code
    start:
        ;a*a
        mov al, [a]     ;AL = a
        mul byte [a]    ;AX = a*a
        
        ;a*a/b
        cwd             ;DX:AX = a*a
        idiv word [b]   ;AX = a*a/b, DX = a*a%b
        mov bx, ax      ;BX = a*a/b
        
        ;b*b
        mov ax, [b]     ;AX = b
        imul word [b]   ;DX:AX = b*b
        mov cx, ax      ;
        mov ax, bx      ;AX = a*a/b
        mov bx, dx      ;BX:CX = b*b

        
        ;(a*a/b+b*b)
        cbw             ;DX:AX = a*a/b
        add ax, cx      ;
        adc dx, bx      ;DX:AX = a*a/b+b*b
        
        ;(a*a/b+b*b)/(2+b)
        mov bx, [b]     ; BX = b
        add bx, 2       ; BX = b + 2
        idiv bx         ; AX = DX:AX/BX, DX = DX:AX%BX
        
        ;(a*a/b+b*b)/(2+b)+e
        cwde            ;EAX = (a*a/b+b*b)/(2+b)
        add eax, [e]    ;EAX = (a*a/b+b*b)/(2+b)+e
        
        ;(a*a/b+b*b)/(2+b)+e-x
        cdq                     ;EDX:EAX = (a*a/b+b*b)/(2+b)+e
        mov ebx, dword [x]      ;
        mov ecx, dword [x+4]    ;ECX:EBX = x
        sub eax, ebx            ;
        sbb edx, ecx            ;EDX:EAX = (a*a/b+b*b)/(2+b)+e-x
        
        push    dword 0      
        call    [exit]       
