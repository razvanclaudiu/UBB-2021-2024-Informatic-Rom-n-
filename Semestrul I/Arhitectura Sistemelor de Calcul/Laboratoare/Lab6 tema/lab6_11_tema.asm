bits 32 
global start        


extern exit               
import exit msvcrt.dll    
                          

; 11. Se da un sir A de dublucuvinte. Construiti doua siruri de octeti  
; - B1: contine ca elemente partea superioara a cuvintelor superioare din A
; - B2: contine ca elemente partea inferioara a cuvintelor inferioare din A
segment data use32 class=data
    A dd 127F5678h, 98FCDC76h, 05060108h
    len equ ($-A)/4
    B1 resb len
    B2 resb len
segment code use32 class=code

    start:
        mov esi, A      ;esi = A, astfel incat sa putem parcurge sirul
        mov edi, 0      ;i = 0
        cld             ;parcurgem sirul de la stanga la dreapta (DF = 0)
        mov ecx, len    ;vom parcurge elementele sirului intr-o bucla   loop cu len iteratii
      
    repeta:
        lodsd ;EAX = dublucuvintele pe rand pana cand s-a parcurs sirul "A"
        mov [B2+edi], al    ;B2 = partea inferioara a cuvantului inferior
        shr eax, 24         ;AL = partea superioara a cuvantului superior
        mov [B1+edi], al    ;B1 = partea superioara a cuvantului superior
        inc edi             ;i = i + 1
    loop repeta
    
        push    dword 0      
        call    [exit]       
