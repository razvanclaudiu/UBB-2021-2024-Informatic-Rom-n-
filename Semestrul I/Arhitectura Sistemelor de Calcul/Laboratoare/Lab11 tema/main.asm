bits 32

global start        


extern exit, printf, scanf, getchar
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import getchar msvcrt.dll

extern subsir

;10. Se citesc mai multe siruri de caractere. Sa se determine daca primul apare ca subsecventa in fiecare din celelalte si sa se dea un mesaj corespunzator.                         
segment data use32 class=data
    nr dd 0 ;nr de siruri citite
    format_nr db "%d", 0
    format_sir_initial db "%10[0-9a-zA-Z \.]%n", 0 
    format_sir db " %30[0-9a-zA-Z \.]%n", 0
    mesaj_intr1 db "Introduceti sirul initial de maxim 10 caractere: ", 0
    mesaj_intr2 db "Introduceti numarul de siruri: ", 0
    mesaj_repeta db "Introduceti %d siruri: ", 0
    mesaj_gasit db "Sirul exista in toate celelalte siruri", 0
    mesaj_negasit db "Sirul nu exista in toate celelalte siruri", 0
    newline db `\r`, 0
    len_initial dd 0
    len dd 0
    sir_initial dd 0
    resb 6  ;rezervam 6 biti ptr lungimea potentiala maxima de 10 caractere
    sir dd 0
    resb 26 ; rezervam 26 biti ptr lungimea potentiala maxima de 30 de caractere
segment code use32 class=code
    start:
        ;mesaj ptr sirul initial
        push dword mesaj_intr1
        call [printf]
        add esp, 4*1
        
        ;se citeste de la tastatura sirul si se salveaza si lungimea
        push dword len_initial
        push dword sir_initial
        push dword format_sir_initial
        call [scanf]
        add esp, 4*3
        sub [len], dword 1
        
        ;mesaj ptr numarul de siruri
        push dword mesaj_intr2
        call [printf]
        add esp, 4*1
        
        ;nr de siruri care urmeaza a fi citite
        push dword nr
        push dword format_nr 
        call [scanf]
        add esp, 4*2
        
        ;in BL se salveaza numarul de siruri ce trebuie citite
        ;in BH este folosit pentru a verifica la final daca s-a gasit sirul initial in toate celelalte siruri
        mov ebx, 0
        mov bh, 1
        mov bl, [nr]
        cmp bl, 0
        jz final
        
        ;mesaj ptr "nr" siruri
        push dword [nr]
        push dword mesaj_repeta
        call [printf]
        add esp, 4*2
        
    repeta:
        ;citirea sirurilor de nr ori
        push dword len
        push dword sir
        push dword format_sir
        call [scanf]
        add esp, 4*3
        sub [len], dword 1
        
        ;apelarea functiei subsir care verifica daca sirul initial este subsir a sirului tocmai citit
        push dword sir_initial
        push dword sir
        push dword [len_initial]
        push dword [len]
        call subsir
        add esp, 4*4
        
        ;newline
        push dword newline
        call [printf]
        add esp, 4*1
        
        ;trece la urmatorul sir
        sub bl, 1
        jnz repeta
    
    ;verifica daca s-a gasit sirul initial in toate celelalte siruri
    cmp bh, 0
    jz notfound
    
    ;mesaj daca s-a gasit
    push dword mesaj_gasit
    call [printf]
    add esp, 4*1
    jmp final
    
    ;mesaj daca nu s-a gasit
    notfound:
        push dword mesaj_negasit
        call [printf]
        add esp, 4*1
            
    final:
        
        ;doua getchar pentru a nu se inchide automat consola la final
        call [getchar]
        call [getchar]
        
        push    dword 0      
        call    [exit]       
