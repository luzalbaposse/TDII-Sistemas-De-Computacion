/*
Implementar una funcion en C tal que: ´
- sus parametros sean un arreglo de enteros (int) y el tamaño de dicho arreglo. ˜
- retorne true si el arreglo contiene al numero 5. ´
- retorne false si el arreglo no contiene al numero 5. ´
Imprimir el resultado por pantalla
*/

#include <stdio.h>

int contieneCinco(int arreglo[], int tamano){
    int i;
    for (i = 0; i < tamano; i++){ // recorre el arreglo y si encuentra un 5 retorna 1
        if (arreglo[i] == 5){
            return 1;
        }
    }
    return 0;
}

/*
Implementar una funcion en C tal que: ´
- sus parametros sean un arreglo de enteros (int) y el tamaño de dicho arreglo. ˜
- imprima en pantalla todos los multiplos de 3 que contenga el arreglo
*/

void multiplosDeTres(int arreglo[], int tamano){
    int i;
    for (i = 0; i < tamano; i++){ // recorre el arreglo y si encuentra un multiplo de 3 lo imprime
        if (arreglo[i] % 3 == 0){
            printf("%d\n", arreglo[i]);
        }
    }
}


/*
Implementar una funcion en C tal que: ´
- sus parametros sean un arreglo de floats y el tamaño de dicho arreglo. ˜
- calcule el promedio entre todos los numeros que componen el arreglo. ´
Imprimir el resultado por pantalla
*/

float promedio(float arreglo[], int tamano){
    float suma = 0;
    int i;
    for (i = 0; i < tamano; i++){ // recorre el arreglo y suma todos los elementos
        suma += arreglo[i];
    }
    return suma / tamano; // retorna el promedio
}



int main() {
// pruebo todas las funciones
    int arreglo1[] = {1, 2, 3, 4, 5};
    int arreglo2[] = {1, 2, 3, 4, 6};
    int arreglo3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float arreglo4[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float arreglo5[] = {1.0, 2.0, 3.0, 4.0, 6.0};
    float arreglo6[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    printf("%d\n", contieneCinco(arreglo1, 5));
    printf("%d\n", contieneCinco(arreglo2, 5));
    printf("%d\n", contieneCinco(arreglo3, 9));
    multiplosDeTres(arreglo1, 5);
    multiplosDeTres(arreglo2, 5);
    multiplosDeTres(arreglo3, 9);
    printf("%f\n", promedio(arreglo4, 5));
    printf("%f\n", promedio(arreglo5, 5));
    printf("%f\n", promedio(arreglo6, 6));
    return 0;
}q