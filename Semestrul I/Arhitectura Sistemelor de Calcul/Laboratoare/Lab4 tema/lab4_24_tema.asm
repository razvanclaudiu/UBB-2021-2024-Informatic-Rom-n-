bits 32 
global start        


extern exit           
import exit msvcrt.dll   
                       
                       
segment data use32 class=data
    m dd 11101001110100011101110110010110b
    mnew dd 0
  
; Se da dublucuvantul M. Sa se obtina dublucuvantul MNew astfel:
; bitii 0-3 a lui MNew sunt identici cu bitii 5-8 a lui M
; bitii 4-7 a lui MNew au valoarea 1
; bitii 27-31 a lui MNew au valoarea 0
; bitii 8-26 din MNew sunt identici cu bitii 8-26 a lui M.
segment code use32 class=code
    start:
        ;bitii 0-3 a lui MNew sunt identici cu bitii 5-8 a lui M
        mov ebx, 111100000b   ;masca ptr bitii 5-8
        mov eax, [m]          ;EAX = m
        and eax, ebx          ;bitii 5-8 din EAX sunt izolati
        ror eax, 5            ;bitii 0-3 din EAX = bitii 5-8 din m
        mov [mnew], eax       ;bitii 0-3 din mnew = bitii 5-8 din m
        
        ;bitii 4-7 a lui MNew au valoarea 1
        mov ebx, 11110000b    ;biti 4-7 = 1
        ; add [mnew], ebx       ;bitii 4-7 din mnew = 1
        or [mnew], ebx       ;bitii 4-7 din mnew = 1       Trebuia OR nu ADD       
        
        ;bitii 8-26 din MNew sunt identici cu bitii 8-26 a lui M
        mov ebx, 111111111111111111100000000b   ;masca ptr bitii 8-26
        mov eax, [m]           ;EAX = m
        and eax, ebx           ;bitii 8-26 diN EAX sunt izolatii
        add [mnew], eax        ;bitii 8-26 din mnew = bitii 8-26 din m
        or [mnew], eax        ;bitii 8-26 din mnew = bitii 8-26 din m   Trebuia OR nu ADD / Diferenta e ca cu ADD functioneaza doar daca mnew este initial 0
        ;Also mi s-o recomandat sa nu lucrez direct in variabila, ci in registrii
        
        ;bitii 27-31 a lui MNew au deja valoarea 0
        
        push    dword 0
        call    [exit]     
