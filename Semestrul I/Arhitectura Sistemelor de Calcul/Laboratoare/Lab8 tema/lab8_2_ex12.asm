bits 32 
global start        

extern exit, printf, scanf, fopen, fclose, fprintf  
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
                         
; Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura numere si sa se scrie valorile citite in fisier pana cand se citeste de la tastatura valoarea 0.
segment data use32 class=data
    nr dd 0
    format db "%d", 0
    nume_fisier db "ex12.txt", 0
    mod_acces db "w", 0
    desc_fis dd -1
    mesaj_intr db `Introduceti numere, urmand ca acestea sa se scrie in fisier, iar apoi introduceti 0 pentru terminarea programului. \n`, 0
    
segment code use32 class=code
    start:
        ;crearea/deschiderea fisierului
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        ;verificam daca s-a creat cu succes fisierul
        mov [desc_fis], eax
        cmp eax, 0
        je final
        
        ;afisarea unei intructiuni pentru utilizator
        push dword mesaj_intr
        call [printf]
        add esp, 4*1
        
    repeta:
        ;citim numere de la tastatura
        push dword nr
        push dword format 
        call [scanf]
        add esp, 4*2
        
        ;verificam daca s-a citit 0
        mov eax, [nr]
        cmp eax, 0
        je inchidef
        
        ;se adauga numarul citit in fisier
        push dword [nr]
        push dword format
        push dword [desc_fis]
        call [fprintf]
        add esp, 4*3
        
        jmp repeta
    
    inchidef:
        ;inchiderea fisierului
        push dword [desc_fis]
        call [fclose]
        add esp, 4*1
     
    final:
        push    dword 0    
        call    [exit]     
