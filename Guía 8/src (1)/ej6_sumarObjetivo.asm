

section .data
  arreglo:  dd 1,-2,3,0,-9,2,4,2,1,8
  objetivo: dd 5
                               
global _start
section .text

  _start:                

    ; En la etiqueta arreglo se encuentran los numeros a sumar y comparar
    ; en Objetivo se encuentra el numero que deben sumar en el caso que exista.

    call sumarObjetivo

    ; Exit
    mov rax, 1     ; funcion 1 
    mov rbx, 0     ; codigo    
    int 0x80                   

sumarObjetivo: ; A partir de un arreglo de 10 números de 32 bits en complemento a 2, quiero ver si existe un par de números que sumen un valor objetivo, si es así imprimo verdadero y sino imprimo falso
  
      mov rsi, arreglo
      mov rdi, objetivo
      mov ecx, 10
      mov edx, 0
      mov ebx, 0
  
      ; Recorro el arreglo
      ; En cada iteracion, sumo el valor de la posicion actual con el valor de la posicion siguiente
      ; Si la suma es igual al objetivo, imprimo verdadero y salgo del programa
      ; Si la suma no es igual al objetivo, sigo recorriendo el arreglo
  
      ciclo:
          mov eax, [rsi + edx * 4]
          add eax, [rsi + edx * 4 + 4]
          cmp eax, [rdi]
          je imprimirVerdadero
          inc edx
          cmp edx, ecx
          jne ciclo
          jmp imprimirFalso
  
      imprimirVerdadero:
          mov ebx, 1 ; guardo el valor 1 en ebx para imprimirlo
          jmp imprimir ; salto a imprimir
  
      imprimirFalso:
          mov ebx, 0
          jmp imprimir
  
      imprimir: ; esto es para imprimir v o f en base a lo que haya guardado en ebx (1 o 0), y luego salir del programa
          mov eax, 4 
          mov ecx, msg 
          mov edx, msg_len 
          int 0x80 
          mov eax, 4 
          mov ecx, msg2 
          mov edx, msg2_len
          int 0x80
          mov eax, 4
          mov ecx, [ebx + 4]
          mov edx, 1
          int 0x80
          mov eax, 4
          mov ecx, msg3
          mov edx, msg3_len
          int 0x80
          mov eax, 4
          mov ecx, [ebx + 4]
          mov edx, 1
          int 0x80
          mov eax, 4
          mov ecx, msg4
          mov edx, msg4_len
          int 0x80
          mov eax, 4
          mov ecx, [ebx + 4]
          mov edx, 1
          int 0x80
          mov eax, 4
          mov ecx, msg5
          mov edx, msg5_len
          int 0x80
          mov eax, 4
          mov ecx, [ebx + 4]
          mov edx, 1
          int 0x80
          mov eax, 4
          mov ecx, msg6
          mov edx, msg6_len
  ret
