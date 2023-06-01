# Ejercicio 6
# Dado un arreglo de 10 n´umeros de 32 bits en complemento a 2, determinar si existe un par de
# números del arreglo que sumen un valor objetivo. En caso de existir al menos un par de n´umeros que
# sumen el valor objetivo, imprimir verdadero, en caso contrario falso.
# Ejemplo:
# arreglo: [1, -2, 3, 0, -9, 2, 4, 2, 1, 9], objetivo: 5, resultado: verdadero
# arreglo: [1, -2, 3, 0, -9, 2, 4, 2, 1, 9], objetivo: 8, resultado: falso

import random

def sumarObjetivo(arreglo, objetivo):
    for i in range(len(arreglo)):
        for j in range(len(arreglo)):
            if i != j:
                if arreglo[i] + arreglo[j] == objetivo:
                    return True
    return False

def main():
    arreglo = []
    for i in range(10):
        arreglo.append(random.randint(-10, 10))
    print(arreglo)
    objetivo = int(input("Ingrese el objetivo: "))
    print(sumarObjetivo(arreglo, objetivo))

main()
