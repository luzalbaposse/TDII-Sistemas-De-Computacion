; Ejercicio 5: Dados 3 números enteros de 8 bits, 16 bits y 32 bits respectivamente en complemento a 2, determinar si los tres n´umeros son positivos, o son negativos, o si hay positivos y negativos entre
; los tres números. Imprimir en pantalla el resultado.
; Ejemplo:
; números: [10, -200, 3233], resultado: Hay positivos y negativos
; números: [-21, -21, -300], resultado: Son todos negativos
; números: [111, 411, 8934], resultado: Son todos positivos
section .data
  numero1: db -10
  numero2: dw -9
  numero3: dd -120
                               
global _start
section .text

  _start:                

    ; En las etiquetas numero1, numero2 y numero3 se encuentran los tres numeros a comparar

    call tresNumeros

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

tresNumeros: ; Esta función compara los tres números y determina si son positivos, negativos o hay positivos y negativos entre los tres números

    ; Comparación de los tres números
    cmp byte [numero1], 0
    jg positivo1
    cmp byte [numero1], 0
    jl negativo1
    cmp word [numero2], 0
    jg positivo2
    cmp word [numero2], 0
    jl negativo2
    cmp dword [numero3], 0
    jg positivo3
    cmp dword [numero3], 0
    jl negativo3

    ; Si no se cumple ninguna de las condiciones anteriores, entonces los tres números son positivos
    mov eax, 4
    mov ebx, 1
    mov ecx, positivos
    mov edx, positivos_len
    int 0x80

    ; Exit
    mov eax, 1
    mov ebx, 0
    int 0x80
  ret

; b. Si el primer número fuera de 64 bits, ¿qué modificaciones habría que hacer en el código?
; Para que el primer número sea de 64 bits, se debe cambiar la etiqueta numero1 a dq y cambiar el registro de comparación a rcx