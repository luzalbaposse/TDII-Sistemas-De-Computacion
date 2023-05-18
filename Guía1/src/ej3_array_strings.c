#include <stdio.h>
#include <stdlib.h>

/*
Considerar un arreglo de punteros a string.
a. Implementar la función char* longest(char* v[], int size), que toma un arreglo 
de punteros a string y retorna el puntero al string m´as largo. De existir 
más de un string que cumpla
la condición, se debe retornar el primero en aparecer en el arreglo.
Ejemplo: longest(["o","Hola","Pepe","Eh"], 4) → "Hola"
*/

char* longest(char* v[], int size) {

    char* str_maslargo = v[0];
    int longitud_masgrande = 0;

    for (int i = 0; i < size; i++) {
        int longitud = 0;
        while (*(v[i] + longitud) != '\0') {
            longitud++;
        }

        if (longitud > longitud_masgrande) {
            str_maslargo = v[i];
            longitud_masgrande = longitud;
        }
    }

    return str_maslargo;
}


/*
 b. Implementar la función char* superConcatenate(char* v[], int size), 
 que toma un arreglo de punteros a string y retorna la concatenación de 
 todos los elementos del arreglo.
Ejemplo: superConcatenate(["Eh_","oo oo","+Gol"], 3) → "Eh_oo oo+Gol"
*/

char* superConcatenate(char* v[], int size) {
char* result = NULL;
    int length = 0;
    int i, j;

    // Calcular la longitud total de los strings del arreglo
    for (i = 0; i < size; i++) {
        for (j = 0; v[i][j] != '\0'; j++) {
            length++;
        }
    }

    // Reservar memoria para almacenar la concatenación de todos los strings
    result = (char*) malloc(sizeof(char) * (length + 1));

    // Concatenar todos los strings del arreglo
    int pos = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; v[i][j] != '\0'; j++) {
            result[pos] = v[i][j];
            pos++;
        }
    }

    // Agregar el carácter nulo al final de la cadena
    result[pos] = '\0';

    return result;
}

/*
c. Modificar la función anterior para soportar un nuevo parámetro de tipo string. 
Este parámetro se utilizará para concatenarse entre cada par de string del arrelgo. 
La aridad de esta función será: char* superConcatenateWithSep(char* v[], int size, char* s).
Ejemplo: superConcatenateWithSep(["Hola","Pepe","Tito"], 3, "..") → "Hola..Pepe..Tito"
*/

char* superConcatenateWithSep(char* v[], int size, char* s) {
    char* result = NULL;
    int length = 0;
    int sep_len = strlen(s);
    int i, j;

    // Calcular la longitud total de los strings del arreglo y los separadores
    for (i = 0; i < size; i++) {
        length += strlen(v[i]);
        if (i < size - 1) {
            length += sep_len;
        }
    }

    // Reservar memoria para almacenar la concatenación de todos los strings y separadores
    result = (char*) malloc(sizeof(char) * (length + 1));

    // Concatenar todos los strings del arreglo y los separadores
    int pos = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; v[i][j] != '\0'; j++) {
            result[pos] = v[i][j];
            pos++;
        }
        if (i < size - 1) {
            for (j = 0; j < sep_len; j++) {
                result[pos] = s[j];
                pos++;
            }
        }
    }

    // Agregar el carácter nulo al final de la cadena
    result[pos] = '\0';

    return result;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* v[5] = {"supercalifragilisticoespialidoso", "como", "va", "el", "dia"};

    char* l = longest(v, 6);

    printf("El string mas largo es: \"%s\"\n", l);

   
    return 0;
}
