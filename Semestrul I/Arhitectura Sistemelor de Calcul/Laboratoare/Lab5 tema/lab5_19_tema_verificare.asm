bits 32 
global start        


extern exit               
import exit msvcrt.dll   
                         
segment data use32 class=data
    a db 2, 1, 3, -3, -4, 2, -6
    alen equ $-a    ; lungimea lui a
    b db 4, 5, -5, 7, -6, -2, 1
    blen equ $-b    ; lungimea lui b
    r resb alen + blen  
    len equ $-r
segment code use32 class=code
    start:
        mov edx, 0      ;EDX = 0
        mov ebx, alen   ;EBX = lungimea lui a
        mov edi, 0      ;j = 0
        
        ;pregatire pentru sirul a
        sir1:
            mov ecx, alen   ;ECX = lungimea lui a
            jecxz sir2      ;sarim peste primul sir daca ECX = 0
            mov esi, 0      ;i = 0
            jmp mov1
        
        ;pregatire pentru sirul b
        sir2:
            mov ecx, blen   ;ECX = lungimea lui b
            jecxz final     ;sarim la final daca b nu are elemente
            mov esi, 0      ;i = 0
            jmp mov2
        
        ;adaugarea elementelor din a
        mov1:
            cmp edx, ebx
            jge mov2        ;Daca edx > ebx => sirul a a fost parcurs
                            ;si trece la sirul b
            mov al, [a+esi] ;AL = pe rand elemetele lui a
            jmp repeta
        
        ;adaugarea elemetelor din b
        mov2:
            mov al, [b+esi] ;AL = pe rand elementele lui b
            jmp repeta
            
        ;verificarea daca elementul este negativ si pozitiv    
        repeta:
            cmp al, 0       ;verificam daca este negativ
            jge nextnr     ;sarim daca nu este negativ
            test al, 1h     ;verificam daca este par
            jz par_negativ ;daca este par sarim la adaugare
            jmp nextnr     ;altfel sarim la urmatorul numar
        
        ;adaugarea in sirul r a unui element pas si negativ
        par_negativ:
            mov [r+edi], al ;mutam in r numare negative si pare
            inc edi
        
        ;incrementare pentru a trece la urmatorul element
        nextnr:
            inc esi ;i = i + 1
            inc edx
            
        loop mov1
        cmp edx, ebx    ;verifica daca sirul "a" a fost parcurs
        jz sir2         ;daca da, se trece la sirul b

        mov ecx, len
        mov esi, 0
        repeta1:
            mov bl, [r+esi]
            inc esi
        loop repeta1
        final:
            push    dword 0     
            call    [exit]       
