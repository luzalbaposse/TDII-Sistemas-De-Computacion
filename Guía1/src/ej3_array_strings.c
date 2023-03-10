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
    
        char concatenacion = ""; // Variable que va a contener la concatenación
        for (int i = 0; i < size; i++) { // Recorro el arreglo de strings
            concatenacion = concatenate(concatenacion, v[i]); // Concateno el string actual con la concatenación
        }
        
    
        return 0;
}

/*
c. Modificar la función anterior para soportar un nuevo parámetro de tipo string. 
Este parámetro se utilizará para concatenarse entre cada par de string del arrelgo. 
La aridad de esta función será: char* superConcatenateWithSep(char* v[], int size, char* s).
Ejemplo: superConcatenateWithSep(["Hola","Pepe","Tito"], 3, "..") → "Hola..Pepe..Tito"
*/

char* superConcatenateWithSep(char* v[], int size, char* s) {

    char concatenacion = ""; // Variable que va a contener la concatenación
    for (int i = 0; i < size; i++) { // Recorro el arreglo de strings
        concatenacion = concatenate(concatenacion, v[i]); // Concateno el string actual con la concatenación
        if (i != size - 1) { // Si no es el último string, concateno el separador
            concatenacion = concatenate(concatenacion, s);
        }
    }
    

    return 0;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* v[5] = {"supercalifragilisticoespialidoso", "como", "va", "el", "dia","supercalifragilisticoespialidososupercalifragilisticoespialidoso"};

    char* l = longest(v, 6);

    printf("El string mas largo es: \"%s\"\n", l);

   
    return 0;
}
