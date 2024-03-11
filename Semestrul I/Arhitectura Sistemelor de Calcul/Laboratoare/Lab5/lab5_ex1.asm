bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        ; CMP d, s - executie FICTIVA d-s care modifica CF,OF,ZF,SF,AF,PF
        ;
        mov al, 100
        mov bl, 200
        
        ;1. comparatie intre 2 numere intregi
        cmp al, bl
        
        ;2. verificarea rezultatului unei operatii
        sub al, bl
        cmp al, 0
        
        ; TEST d, s - executie FICTIVA d AND s care modifica SF, ZF, AF
        ;
        ;1. e par?
        
        ;2. e negativ?
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
