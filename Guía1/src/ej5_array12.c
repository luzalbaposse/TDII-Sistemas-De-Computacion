/*
Ejercicio 5
Suponer un puntero a un arreglo de 12 bytes.
a. Interpretar al arreglo como un puntero a char* (enteros de un byte) y calcular la sumatoria de
los datos almacenados. La aridad de la función es int sumAsBytes(char* v)
Ejemplo: sumAsBytes( [0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00] )
→ 0x05+0x01+0x00+0x00+0x05+0x01+0x00+0x00+0x05+0x01+0x00+0x00 → 0x12
b. Interpretar al arreglo como un puntero a int* (enteros de 4 bytes) y calcular la sumatoria de
los datos almacenados. La aridad de la funci´on es int sumAsInts(int* v)
Ejemplo: sumAsInts( [0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00] )
→ 0x00000105+0x00000105+0x00000105 →  0x30F
*/

#include <stdio.h>
#include <stdlib.h>

int sumAsBytes(char* v) {
    /*
    La función calcula la sumatoria de los datos almacenados en el arreglo de 12 bytes. Interpretar al arreglo como un puntero a char*
    */
    int i;
    int sum = 0;
    for(i = 0; i < 12; i++) {
        sum += v[i];
    }
    return sum;
}

int sumAsInts(int* v) {
    /*
    Interpretar al arreglo como un puntero a int* (enteros de 4 bytes) y 
    calcular la sumatoria de los datos almacenados. La aridad de la función 
    es int sumAsInts(int* v)
    */
   int i;
    int sum = 0;
    for(i = 0; i < 3; i++){
        sum += v[i];
    }
    return sum;
}

int main() {

    char v[12] = {0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00};

    int sumB = sumAsBytes((char*)v);
    int sumI = sumAsInts((int*)v);

    printf("El arreglo sumado de a bytes es: %i (d) %x (h)\n", sumB, sumB);
    printf("El arreglo sumado de a ints es: %i (d) %x (h)\n", sumI, sumI);


    return 0;
}