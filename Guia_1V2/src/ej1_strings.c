#include <stdio.h>
#include <stdlib.h>

int len(char* s) {

    // Toma un string y retorna su longitud sin considerar el carácter nulo de terminación.
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }

    return i;
}

char* copy(char* s) {
    int i = 0;
    char* aux = malloc(sizeof(char) * len(s));
    while (s[i] != '\n'){        
        aux[i] = s[i];
        i++;
    }
    return aux;
}

void replaceChar(char* s, char old, char new) {
    int i = 0;
    while(s[i]!='\0'){
        if (s[i] == old){
            s[i] = new;}
        i++;
    }
    return;
    }

char* concatenate(char* s1, char* s2) {
   int i = 0;
   int b = 0;
   char *nuevo = malloc(sizeof(char)* (len(s1) + len (s2)));
   while(s1[i] != '\0'){
    nuevo[b] = s1[i];
    i++;
    b++;
   }
i = 0;
   while(s2[i] != '\0'){
    nuevo[b] = s2[i];
    i++;
    b++;
   }
   free(s1);
   free(s2);
   return nuevo;

    
    return 0;
}

int main() {
   

    char* s1 = "Ramon";
    char* s2 = "Ricardo";
    char* s3 = "Maico";

    printf("El string \"%s\" mide %i\n",s1, len(s1));
    printf("El string \"%s\" mide %i\n",s2, len(s2));

    char* copyS1 = copy(s1);
    char* copyS2 = copy(s2);
    char* copyS3 = copy(s3);

    printf("El string \"%s\" es una copia de  %s\n",copyS1, s1);
    printf("El string \"%s\" es una copia de  %s\n",copyS2, s2);
    printf("El string \"%s\" es una copia de  %s\n",copyS3, s3);

 
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
