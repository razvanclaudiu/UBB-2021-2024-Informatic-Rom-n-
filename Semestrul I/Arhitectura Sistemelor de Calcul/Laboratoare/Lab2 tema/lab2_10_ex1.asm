bits 32 
global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data

segment code use32 class=code
    start:
    
        mov eax, 0
        mov al, 9
        add al, 7
        
        push    dword 0      
        call    [exit]       
