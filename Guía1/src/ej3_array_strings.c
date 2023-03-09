#include <stdio.h>
#include <stdlib.h>

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


char* superConcatenate(char* v[], int size) {

    // COMPLETAR

    return 0;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {

    // COMPLETAR

    return 0;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* v[5] = {"hola", "como", "va", "el", "dia"};

    char* l = longest(v, 5);

    printf("El string mas largo es: \"%s\"\n", l);

   
    return 0;
}
