section .data   ; Quiero que imprima una letra debajo de la otra
    msg db 'Pepe', 0xa ; mensaje
    largo equ $-msg ; largo del mensaje               
         
                               
global _start                
section .text

  _start:                

    call nombre

    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

nombre: ; Ejercicio: porgrama que imprima su nombre en pantalla. Ejemplo: resultado: Pepe
    mov rax, 4     ; funcion 4
    mov rbx, 1     ; salida estandar
    mov rcx, msg   ; mensaje
    mov rdx, largo ; largo del mensaje
    int 0x80

    ret

    ;mov rax, 1     ; funcion 1 
    ;mov rbx, 0     ; codigo    
    ;int 0x80                   

    ;
ret

; c. Se llama al sistema para imprimir en pantalla el mensaje que esta en la seccion .data un total de 4 veces