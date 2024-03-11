bits 32
global _sign
segment data public data use32
segment code public code use32
_sign:
    push ebp
	mov ebp, esp
	
    ;Se salveaza in EBX numarul si se compara cu 0
	mov ebx, [esp+8]
    cmp ebx, 0
    ;Daca este negativ EAX = 1, daca este pozitiv EAX = 0
    js negativ
    mov eax, 1
    jmp final
negativ:
    mov eax, 0
final:

    mov esp, ebp
	pop ebp
    ;Returnam EAX
	ret