bits 32

global subsir 

extern exit         
import exit msvcrt.dll
                    
segment data use32 class=data
    len1 dd 0
    len2 dd 0
segment code use32 public class=code
    subsir:
        ;salvam in len1 si len2 lungimile sirurilor
        mov eax, [esp+4]
        mov [len1], eax
        mov eax, [esp+8]
        mov [len2], eax
        
        ;daca len1 > len2 atunci siruri invalide
        cmp eax, [len1]
        ja invalid
        
        ;salvam in esi si edi cele doua siruri
        mov esi, [esp+12]
        mov edi, [esp+16]
        
        ;numarul de pozitii posibile pentru subsir
        mov ecx, [len1]
        sub ecx, [len2]
        add ecx, 1
    
    ;se va lua pe rand cate o litera din esi pana cand ecx = 0
    initiere:
        lodsb   ;AL = pe rand cate o litera din ESI
            
        push esi
        push ecx
            
        mov edx, 0
        mov ecx, [len2] 
    
    ;comparam pe rand litera cu litera ESI cu continutul lui EDI pana cand se gaseste o diferenta
    comparare:
        cmp al, [edi + edx]
        lodsb 
        jne reinitiere   
        inc edx                       
        loop comparare
    
    ;verificam daca s-a gasit subsirul, iar daca nu sarim la repetainitiere
    reinitiere:
 
        pop ecx
        pop esi
        
        ;daca EDX = len2 atunci s-a gasit si sarim la final
        cmp edx, [len2]
        jne repetainitiere
        jmp final
        
    repetainitiere:
        loop initiere
    
    invalid:
        mov bh, 0
        
    final:
         
        ret
        
        push    dword 0     
        call    [exit]       
