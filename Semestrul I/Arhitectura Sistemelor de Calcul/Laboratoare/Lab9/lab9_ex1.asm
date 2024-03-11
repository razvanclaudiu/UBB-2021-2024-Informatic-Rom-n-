bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    max equ 50
    propozitie times max+1 db 0
    message db "Introduceti o propozitie: ", 0
    format_de_afisare db "Propozitia: %s", 0
    format_de_citire db "%50[0-9a-zA-Z \.]", 0
; Cititi de la tastatura si afisati o propozitie
; (mai multe siruri de caractere separate prin SPATII si care se termina cu caracterul '.')
segment code use32 class=code
    start:
        push dword message
        call [printf]
        add esp, 4
        
        push dword propozitie
        push dword format_de_citire
        call [scanf]
        add esp, 4
        
        push dword propozitie
        push dword format_de_afisare
        call [printf]
        add esp, 8
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
