#include <stdio.h>
#include <stdlib.h>
/*
Para ambos items se debe comprender la operaci´on de Type Casting o de conversi´on de tipos. Se
debe definir una variable tipo puntero del tipo al que queremos ir, y luego se debe interpretar el
puntero como el tipo de la variable indique. De esta forma, tendremos dos punteros exactamente
iguales, apuntando a la misma memoria, pero que C los interpreta de forma diferente, porque son
de tipos diferentes.
*/
int sumAsBytes(char* v) {
    /*
    Interpretar al arreglo como un puntero a char* (enteros de un byte) y calcular la sumatoria de
    los datos almacenados. 
    */
    int res = 0;
    int contador = 0;
    while (contador < 12){
        res += v[contador];
        contador ++;
    }
    return res;
}

int sumAsInts(int* v) {
    /*
    Puntero a int* (enteros de 4 bytes), calcular la sumatoria de los datos
    */
   int res = 0;
   int contador = 0;
   for(contador = 0; contador < 3; contador ++){
       res += v[contador];
   }
    return res;
}

int main() {

    char v[12] = {0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00};

    int sumB = sumAsBytes((char*)v);
    int sumI = sumAsInts((int*)v);

    printf("El arreglo sumado de a bytes es: %i (d) %x (h)\n", sumB, sumB);
    printf("El arreglo sumado de a ints es: %i (d) %x (h)\n", sumI, sumI);

    // */

    return 0;
}