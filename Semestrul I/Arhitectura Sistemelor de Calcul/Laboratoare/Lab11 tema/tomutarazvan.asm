bits 32 


global start        


extern exit, fopen, fclose, fread, printf               
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
                          


segment data use32 class=data
    mod_accesr db "r", 0
    
    desc_fis dd -1

    nume_fisier db "input.txt", 0
    
    format db "%c", 0
    
    len equ 100
    text times len db 0
    

segment code use32 class=code
    start:
        push dword mod_accesr
        push dword nume_fisier
        call [fopen]
        add esp, 8
        
        mov [desc_fis], eax
        cmp eax, 0
        je final
        
        push dword [desc_fis]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 16
        
        mov esi, 0
        mov ebx, '9'
        
    repeta:
        mov al, [text+esi]
        cmp al, 0
        jz afisare
        cmp al, '0'
        jl reset
        cmp al, '9'
        jg reset
        test al, 1h
        jnp gasit
        inc esi
        jmp repeta
        
    reset:
        inc esi
        jmp repeta
        
    gasit:
        inc esi
        cmp bl, al
        jl repeta
        mov bl, al
        mov edx, 1
        jmp repeta
        
    afisare:
        cmp edx, 0
        jz final
        push dword ebx
        push dword format
        call [printf]
        add esp, 8
    
    final:
        push dword [desc_fis]
        call [fclose]
        add esp, 4
       
        push    dword 0      
        call    [exit]       
