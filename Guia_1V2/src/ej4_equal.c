#include <stdio.h>
#include <stdlib.h>

void pairOfEquals(char v[], int size, char** a, char** b) {

    /*
    Implementar la función void pairOfEquals(char v[], int size, char** a, char** b) que busca dentro de v dos bytes iguales y escribe en a y b los punteros a los bytes encontrados. En el caso
de no encontrar ningún par de bytes iguales debe retornar cero en ambos punteros. Recordar que el tipo char es de 1 byte de tama˜no y se opera como un n´umero con signo. Ejemplo: pairOfEquals([14,23,55,21,55,53], &a, &b) → a = &v[2] y b = &v[4] Ejemplo: pairOfEquals([14,23,22,21,55,53], &a, &b) → a = 0 y b = 0
    Requiere: size > 0
    Devuelve: a y b apuntan a dos bytes iguales dentro de v o a 0 si no hay iguales.
    */
   for (int i = 0; i < size; i++) {
       for (int otro = i+1; otro < size; otro++) { // Se busca desde el siguiente al actual hasta el final del vector 
           if (v[i] == v[otro]) { // Si se encuentra un igual se devuelve
               *a = &v[i];
               *b = &v[otro];
               return;
           }
       }
  
   }
    *a = 0; // Si no hay iguales se devuelve 0
    *b = 0; // Si no hay iguales se devuelve 0 
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[7] = {9, 4, 5, 6, 1, 4, 1};

    char* a;
    char* b;

    pairOfEquals(v, 7, &a, &b);

    if(a == 0 || b == 0) {
        printf("No hay iguales");
    } else {
        printf("Los valores iguales son: %i == %i\n", (char)(*a), (char)(*b));
    }

    // */

    return 0;
}
