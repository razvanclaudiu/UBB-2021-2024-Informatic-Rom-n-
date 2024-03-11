bits 32 
global start        

extern exit           
import exit msvcrt.dll   
                     


segment data use32 class=data
    a db 7
    ;b dw 0abcdh   
    b dw 3
    c dd 1234abcdh
    
segment code use32 class=code
    start:
        ; 7 + 5
        ; mov al,7        ; AL = 7
        ; mov bl, 5       ; BL = 5
        ; add al, bl      ; AL = AL +BL = 7 + 5
    
         mov al, 7         ; AL = 7
         add al, 5         ; AL = AL + 5 = 7 + 5
        
        ; a + 5
        ; mov al, [a]     ; AL = a
        ; add al, 5       ; AL = a + 5
        
        ; ; a - 3
        ; mov bl, [a]     ; BL = a
        ; sub bl, 3       ; BL = a - 3
    
        ; a + b
        mov ax, [b]     ; AX = B
        mov bh, 0       
        mov bl, [a]     ; BX = 00000000 xxxxxxxx
        ; mov bx, [a]   ; INCORECT
        add ax, bx      ; AX = AX + BX = a + b
        
        
    push  dword 0      
    call  [exit]  