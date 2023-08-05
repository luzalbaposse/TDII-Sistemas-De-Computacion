#include <stdio.h>
#include <stdlib.h>

int* merge(int* A, int sizeA, int* B, int sizeB) {
    /*
    Recibe: dos arreglos de enteros ordenados de menor a mayor.
    Devuelve: un nuevo arreglo que combine ambos arreglos de forma ordenada.
    */
    int* C = malloc(sizeof(int) * (sizeA + sizeB));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < sizeA && j < sizeB){
        if (A[i] < B[j]){ // si el de a es msas chico que el de b
            C[k] = A[i]; // pongo el de a
            i++;
            k++;
        } 
        else{
            C[k] = B[j]; // sino pongo el de b
            j++;
            k++;
        }
    }
   // si no tengo más elementos de A, pongo los de B
    while (j < sizeB){
        C[k] = B[j];
        j++;
        k++;
    }
    // si no tengo más elementos de B, pongo los de A
    while (i < sizeA){
        C[k] = A[i];
        i++;
        k++;
    }
    return C;
}
// modifico la funcion para que ahora devuelva un array pero de floats, aunque reciba arrays de enteros
float* merge2(int* A, int sizeA, int* B, int sizeB) {
    /*
    Recibe: dos arreglos de enteros ordenados de menor a mayor.
    Devuelve: un nuevo arreglo que combine ambos arreglos de forma ordenada.
    */
    float* C = malloc(sizeof(float) * (sizeA + sizeB));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < sizeA && j < sizeB){
        if (A[i] < B[j]){ // si el de a es msas chico que el de b
            C[k] = A[i]; // pongo el de a
            i++;
            k++;
        } 
        else{
            C[k] = B[j]; // sino pongo el de b
            j++;
            k++;
        }
    }
   // si no tengo más elementos de A, pongo los de B
    while (j < sizeB){
        C[k] = B[j];
        j++;
        k++;
    }
    // si no tengo más elementos de B, pongo los de A
    while (i < sizeA){
        C[k] = A[i];
        i++;
        k++;
    }
    return C;
}

int main() {

    int a[5] = {4,5,6,7,8};
    int b[4] = {1,2,3,9};

    int* result = merge(a, 5, b, 4);

    printf("Result:");
    for(int i=0; i<9; i++) {
        printf(" %i", result[i]);
    }
    printf("\n");

    free(result);
    // testo merge2
    int c[5] = {4,5,6,7,8};
    int d[4] = {1,2,3,9};

    float* result2 = merge2(c, 5, d, 4);

    printf("Result:");
    for(int i=0; i<9; i++) {
        printf(" %f", result2[i]);
    }


    return 0;
}
