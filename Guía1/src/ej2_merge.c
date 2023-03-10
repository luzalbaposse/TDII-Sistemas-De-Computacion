#include <stdio.h>
#include <stdlib.h>


/*
Implementar una función que tome dos arreglos de enteros (int) ordenados de menor a mayor
y retorne un nuevo arreglo que combine ambos arreglos de forma ordenada. La función se debe
llamar int* merge(int* A, int sizeA, int* B, int sizeB), donde A y B son punteros a
arreglos y sizeA y sizeB sus respectivos tamaños.
Ejemplo: merge([2,3,5,7,9,9], 6, [8,10,12], 3) → [2,3,5,7,8,9,9,10,12]

*/
int* merge(int* A, int sizeA, int* B, int sizeB) {
    int* result = (int*) malloc((sizeA + sizeB) * sizeof(int));
    int i = 0; // Índice para recorrer el arreglo A
    int j = 0; // Índice para recorrer el arreglo B
    int k = 0; // Índice para recorrer el arreglo resultante
    
    // Recorrer ambos arreglos y agregar el elemento más pequeño al resultado
    while (i < sizeA && j < sizeB) {
        if (A[i] <= B[j]) {
            result[k] = A[i];
            i++;
        } else {
            result[k] = B[j];
            j++;
        }
        k++;
    }
    
    // Agregar los elementos restantes de A, si es que hay
    while (i < sizeA) {
        result[k] = A[i];
        i++;
        k++;
    }
    
    // Agregar los elementos restantes de B, si es que hay
    while (j < sizeB) {
        result[k] = B[j];
        j++;
        k++;
    }
    
    return result;
}

/*
b. Modificar el ítem anterior para que los números de los arreglos sean de tipo float.
*/
float* merge_b(float* A, int sizeA, float* B, int sizeB) {
    float* result = (float*) malloc((sizeA + sizeB) * sizeof(float));
    int i = 0; // Índice para recorrer el arreglo A
    int j = 0; // Índice para recorrer el arreglo B
    int k = 0; // Índice para recorrer el arreglo resultante
    
    // Recorrer ambos arreglos y agregar el elemento más pequeño al resultado
    while (i < sizeA && j < sizeB) {
        if (A[i] <= B[j]) {
            result[k] = A[i];
            i++;
        } else {
            result[k] = B[j];
            j++;
        }
        k++;
    }
    
    // Agregar los elementos restantes de A, si es que hay
    while (i < sizeA) {
        result[k] = A[i];
        i++;
        k++;
    }
    
    // Agregar los elementos restantes de B, si es que hay
    while (j < sizeB) {
        result[k] = B[j];
        j++;
        k++;
    }
    
    return result;
}
int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    int a[5] = {4,5,6,7,8};
    int b[4] = {1,2,3,9};

    int* result = merge(a, 5, b, 4);

    printf("Result:");
    for(int i=0; i<9; i++) {
        printf(" %i", result[i]);
    }
    printf("\n");

    free(result);

    

    return 0;
}
