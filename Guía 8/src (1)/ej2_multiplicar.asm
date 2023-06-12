section .data
  numero1: dw 10
  numero2: dw 30
                               
global _start
section .text

  _start:                

    mov di, [numero1]
    mov si, [numero2]

    ; En "di" y en "si" vamos a tener los numeros a multiplicar
    ; dejar el resultado en eax

    call multiplicar

    ; Imprimo el valor en rax
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80

multiplicar: ; Ejercicio: Funcion que toma dos numeros enteros sin signo de 16 bits y los multiplica utilizando sumas sucesivas. Quiero imprimir por pantalla el valor resultado en hexadecimal
    xor eax, eax     ; Limpiar eax (utilizado para acumular el resultado)
    mov cx, si       ; Guardar el segundo número en cx

; ---------------------------------------------
; printHex toma como parametro un valor en rdi
; e imprime dicho valor en hexadecimal
; ---------------------------------------------
multiplicar_ciclo: ; Acá voy a multiplicar el primer número por el segundo, sumando el primer número tantas veces como indique el segundo. Otra versión
    add eax, di      ; Sumar el primer número al resultado acumulado
    dec cx           ; Decrementar el segundo número
    jnz multiplicar_ciclo ; Saltar al bucle si el segundo número no es cero

    ret
printHex:
  push rbx
  push r12
  push r13
  push r14
  push r15
  push rbp
  mov rcx, 15
  mov rbx, hexachars
  .ciclo:
    mov rax, rdi
    and rax, 0xF
    mov dl, [rbx+rax]
    mov [number+rcx], dl
    dec rcx
    shr rdi, 4
    cmp rcx, -1
    jnz .ciclo
  mov rax, 4      ; funcion 4
  mov rbx, 1      ; stdout
  mov rcx, number ; mensaje
  mov rdx, 17     ; longitud
  int 0x80
  pop rbp
  pop r15
  pop r14
  pop r13
  pop r12
  pop rbx
ret

section .rodata
  hexachars: db "0123456789ABCDEF"

section .data
  number:    db "0000000000000000",10
