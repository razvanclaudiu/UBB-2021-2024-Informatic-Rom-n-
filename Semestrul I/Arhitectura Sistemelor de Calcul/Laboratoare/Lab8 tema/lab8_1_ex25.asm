bits 32 
global start        

extern exit, printf, scanf       
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
                         
; Sa se citeasca de la tastatura doua numere a si b (in baza 10) şi să se determine relaţia de ordine dintre ele (a < b, a = b sau a > b). Afisati rezultatul în următorul format: "<a> < <b>, <a> = <b> sau <a> > <b>".
segment data use32 class=data
    x dd 0
    y dd 0
    format db "%d %d", 0
    mesaj_intr db "Introduceti doua numere: ", 0
    mesaj_mic db "%d < %d", 0
    mesaj_mare db "%d > %d", 0
    mesaj_egal db "%d = %d", 0
    
segment code use32 class=code
    start:
        ;mesajul de introducere: "Introduceti doua numere: "
        push dword mesaj_intr
        call [printf]
        add esp, 4*1
        
        ;citirea de la tastatura a doua numere
        push dword y
        push dword x 
        push dword format 
        call [scanf]
        add esp, 4*3
        
        ;compararea celor doua numere
        mov eax, [x]
        cmp eax, [y]
        jg mare
        jz egal
    
    ;daca x este mai mic ca y se afiseaza: "x < y"
    mic:
        push dword [y]
        push dword [x]
        push dword mesaj_mic
        call [printf]
        add esp, 4*3
        jmp final
    
    ;daca x este mai mare ca y se afiseaza: "x > y"
    mare:
        push dword [y]
        push dword [x]
        push dword mesaj_mare
        call [printf]
        add esp, 4*3
        jmp final
        
    ;daca x este egal cu y se afiseaza: "x = y"
    egal:
        push dword [y]
        push dword [x]
        push dword mesaj_egal
        call [printf]
        add esp, 4*3
    
    final:
        push    dword 0    
        call    [exit]     
