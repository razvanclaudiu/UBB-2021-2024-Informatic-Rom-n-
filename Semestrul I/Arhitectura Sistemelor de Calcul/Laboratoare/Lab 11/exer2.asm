bits 32


global start        


extern exit, printf, scanf            
import exit msvcrt.dll    
import printf msvcrt.dll
import scanf msvcrt.dll


segment data use32 class=data
    cuvant db 0
    mesaj_intr db "Introduceti un cuvant: ", 0
    mesaj_afis db "Cuvantul e: %s", 0
    format db "%s", 0
    


segment code use32 class=code
    start:
        
        push dword mesaj_intr
        call [printf]
        add esp, 4*1
        
        push dword cuvant 
        push dword format 
        call [scanf]
        add esp, 4*2
        
        push dword cuvant
        push dword mesaj_afis
        call [printf]
        add esp, 4*2
        
        push    dword 0      
        call    [exit]      
