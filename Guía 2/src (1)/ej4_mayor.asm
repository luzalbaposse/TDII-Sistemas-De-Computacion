; Ejercicio 4: recorrer un arreglo de 16 números de 16 bits sin signo y determinar cuál es el mayor. Imprimir en pantalla elvalor resultante en hexadecimal.
; Ejemplo:
; arreglo: [10, 0, 39, 2, 8, 17, 51, 28, 2, 3, 20, 39, 52, 34, 12, 1, 8]
; resultado: 0x34 (52d)

section .data
  arreglo: dw 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los 16 numeros a comparar.
    ; dejar el resultado en eax

    call mayor

    ; Imprimo el valor en rax
    mov rdi, rax ; paso como parametro rax como rdi
    call printHex

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80

mayor: ; A CHEQUEAR Función para recorrer un arreglo de 16 numeros en memoria y devuelve el mayor
  ; Recibe: Arreglo de 16 numeros de 16 bits sin signo
  ; Devuelve: El mayor de los 16 numeros en eax
  push rbp ; Guardo el valor de rbp
  mov rbp, rsp ; Muevo el valor de rsp a rbp
  push rbx ; Guardo el valor de rbx
  push r12 ; Guardo el valor de r12
  push r13 ; Guardo el valor de r13
  push r14 ; Guardo el valor de r14
  push r15 ; Guardo el valor de r15
  mov r12, 0 ; Inicializo r12 en 0
  mov r13, 0 ; Inicializo r13 en 0
  mov r14, 0 ; Inicializo r14 en 0
  mov r15, 0 ; Inicializo r15 en 0
  mov rbx, 0 ; Inicializo rbx en 0
  mov rax, 0 ; Inicializo rax en 0
  mov rdi, arreglo ; Muevo la direccion de memoria del arreglo a rdi
  mov rsi, 0 ; Inicializo rsi en 0
  mov rdx, 16 ; Inicializo rdx en 16

  .ciclo:
    cmp rsi, rdx ; Comparo rsi con rdx
    je .fin ; Si son iguales salto a .fin
    mov rax, [rdi+rsi*2] ; Muevo el valor de la posicion del arreglo a rax
    cmp rax, r12 ; Comparo rax con r12
    jle .menor ; Si rax es menor o igual a r12 salto a .menor
    mov r12, rax ; Muevo el valor de rax a r12
    mov r13, rsi ; Muevo el valor de rsi a r13
    jmp .siguiente ; Salto a .siguiente
    .menor:
      inc rsi ; Incremento rsi
      jmp .ciclo ; Salto a .ciclo
    .siguiente:
      inc rsi ; Incremento rsi
      jmp .ciclo ; Salto a .ciclo
  .fin:
    mov rax, r12 ; Muevo el valor de r12 a rax
    mov rbx, r13 ; Muevo el valor de r13 a rbx
    mov rsi, 0 ; Inicializo rsi en 0
    mov rdi, 0 ; Inicializo rdi en 0
    mov rdx, 0 ; Inicializo rdx en 0
    mov r12, 0 ; Inicializo r12 en 0
    mov r13, 0 ; Inicializo r13 en 0
    mov r14, 0 ; Inicializo r14 en 0
    mov r15, 0 ; Inicializo r15 en 0
    pop r15 ; Restauro el valor de r15
    pop r14 ; Restauro el valor de r14
    pop r13 ; Restauro el valor de r13
    pop r12 ; Restauro el valor de r12
    pop rbx ; Restauro el valor de rbx
    pop rbp ; Restauro el valor de rbp
    ret ; Retorno
; La funcion devuelve el mayor de los 16 numeros en eax
  ret

; ---------------------------------------------
; printHex toma como parametro un valor en rdi
; e imprime dicho valor en hexadecimal
; ---------------------------------------------

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

; b. ¿Qué modifcaciones debe realizarse sobre el ejercicio anterior para soportar números con signo de 16 bits?
; Para hacer esto, hay que cambiar el tipo de dato de los elementos del arreglo a word, y cambiar la comparacion de los elementos del arreglo a signed. 