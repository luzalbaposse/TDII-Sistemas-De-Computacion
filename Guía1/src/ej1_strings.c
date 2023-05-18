#include <stdio.h>
#include <stdlib.h>
// El lenguaje C no posee definido el tipo básico string, como sucede en otros lenguajes de programación. 
// Sin embargo, podemos implementar un string como una cadena de caracteres, es decir, un
// arreglo de caracteres. Para identificar dónde termina la cadena de caracteres, escribimos un 0 (cero)
// como último carácter de la cadena. Por lo tanto, se dice que un string de C es un arreglo de caracteres
// cuyo último carácter es un 0
int len(char* s) {

    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
} // La función len devuelve la cantidad de caracteres que tiene el string s, sin contar el 0 final. De esta forma, si s es un string de 5 caracteres, len(s) debe devolver 5.

char* copy(char* s) {
    int longitud = 0;
    while (s[longitud] != '\0') {
        longitud++;
    }
    char* nuevostring = (char*) malloc((longitud + 1) * sizeof(char));
    for (int i = 0; i < longitud; i++) {
        nuevostring[i] = s[i];
    }
    nuevostring[longitud] = '\0';
    return nuevostring;

} // La función copy devuelve una copia del string s. La copia debe ser un nuevo string, es decir, debe estar en una nueva posición de memoria. La función copy debe utilizar malloc para reservar memoria para el nuevo string.

void replaceChar(char* s, char old, char new) {

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == old) {
            s[i] = new;
        }
        i++;
    }
} //La funcion replaceChar recibe un string s, un caracter old y un caracter new. La función debe reemplazar todas las apariciones del caracter old por el caracter new en el string s.

char* concatenate(char* s1, char* s2) {
    /*La funcion concatenate recibe dos strings s1 y s2 y 
    devuelve un nuevo string que es la concatenación de s1 
    y s2. La función debe utilizar malloc para reservar memoria 
    para el nuevo string.
    */
   int string1 = 0;
   int string2 = 0;
    while (s1[string1] != '\0') {
         string1++;
    }
    while (s2[string2] != '\0') {
         string2++;
    }
    char* nuevostring = (char*) malloc((string1 + string2 + 1) * sizeof(char));
    for (int i = 0; i < string1; i++) {
        nuevostring[i] = s1[i];
    }
    for (int i = 0; i < string2; i++) {
        nuevostring[string1 + i] = s2[i];
    }
    nuevostring[string1 + string2] = '\0';
    return nuevostring;
} 


int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* s1 = "Ramon";
    char* s2 = "Ricardo";

    printf("El string \"%s\" mide %i\n",s1, len(s1));
    printf("El string \"%s\" mide %i\n",s2, len(s2));

    char* copyS1 = copy(s1);
    char* copyS2 = copy(s2);

    printf("El string \"%s\" es una copia de  %s\n",copyS1, s1);
    printf("El string \"%s\" es una copia de  %s\n",copyS2, s2);

    replaceChar(copyS1, 'a', 'o');
    replaceChar(copyS2, 'R', 'T');

    printf("Sobre el string \"%s\" remplazo 'a' por 'o': %s\n",s1, copyS1);
    printf("Sobre el string \"%s\" remplazo 'R' por 'T': %s\n",s2, copyS2);

    printf("Concateno \"%s\" con \"%s\":",copyS1, copyS2);

    char* concat = concatenate(copyS1, copyS2);

    printf(" \"%s\"\n",concat);
    
    free(concat);

    

    return 0;
}
