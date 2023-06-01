; Ejercicio 3: Dado un arreglo de 10 numeros de 32 bits en complemento a dos. Realizar la suma de todos los valores e imprimir en pantalla si la suma total resultó en un número positivo o negativo
; Ejemplo:
; arreglo: [-10, 2, -8, 17, -1, 20, -9, 52, 4, 12], resultado: Positivo
; arreglo: [-10, 2, -8, -7, -1, -1, -9, -2, 4, 12], resultado: Negativo

section .data
  arreglo: dd -1,2,3,4,-5,6,7,8,9,-10
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los 10 numeros a sumar.
    ; dejar el resultado en eax

    call sumarArreglo

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

sumarArreglo: ; Realiza la suma de todos los valores del arreglo y deja el resultado en eax
    mov eax, 0 ; resultado
    mov ebx, 0 ; indice
    mov ecx, 10 ; cantidad de elementos
    mov esi, arreglo ; direccion del arreglo
    sumar: ; Suma los elementos del arreglo
        add eax, [esi + ebx * 4] ; eax = eax + arreglo[ebx]
        inc ebx ; ebx++
        loop sumar ; Repite el ciclo hasta que ecx = 0
    ret
  ret
