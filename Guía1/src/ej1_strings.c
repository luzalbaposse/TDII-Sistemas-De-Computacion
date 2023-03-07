#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// El lenguaje C no posee definido el tipo b´asico string, como sucede en otros lenguajes de programación. 
// Sin embargo, podemos implementar un string como una cadena de caracteres, es decir, un
// arreglo de caracteres. Para identificar d´onde termina la cadena de caracteres, escribimos un 0 (cero)
// como último carácter de la cadena. Por lo tanto, se dice que un string de C es un arreglo de caracteres
// cuyo último carácter es un 0
int len(char* s) {

    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

char* copy(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    char* new_s = (char*) malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        new_s[i] = s[i];
    }
    new_s[len] = '\0';
    return new_s;

}

void replaceChar(char* s, char old, char new) {

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == old) {
            s[i] = new;
        }
        i++;
    }
}

char* concatenate(char* s1, char* s2) {
    int long1 = strlen(s1);
    int long2 = strlen(s2);
    char* new_s = (char*) malloc((long1 + long2 + 1) * sizeof(char));
    for (int i = 0; i < long1; i++) {
        new_s[i] = s1[i];
    }
    for (int i = 0; i < long2; i++) {
        new_s[long1 + i] = s2[i];
    }
    new_s[long1 + long2] = '\0';
    free(s1);
    free(s2);
    return new_s;
}

int main() {
    /*
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

    // */

    return 0;
}
