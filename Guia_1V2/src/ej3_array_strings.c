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
char* longest(char* v[], int size) {
    /*
    Implementar la fución char* longest(char* v[], int size) que toma un arreglo
    de punteros a string y retorna el puntero al string más largo. De existir más de un string que cumpla la condición, se debe retornar el primero en aparecer en el arreglo. Por ejemplo longest[“hola”, “como”, “va”, “el”, “dia”] debe retornar “como”.
    */
   int i = 0;
   char *p = v[0];
   while( i < size){ // recorro el arreglo
         if (len(v[i]) > len(p)){ // si la longitud de donde estoy ahora es mas grande que el puntero, le digo a p "capo sos v[i]"
              p = v[i]; 
         }
         i++; 
   }
    return p;
}

char* superConcatenate(char* v[], int size) {

    /*
    Implementar la función char* superConcatenate(char* v[], int size), que toma un 
    arreglo de punteros a string y retorna la concatenaci´on de todos los elementos del arreglo.
    La lógica que voy a aplciar es la siguiente: como no sé cuánto espacio ocupa cada string, voy a tener que sumar el tamaño de cada string en el llamado a malloc para mi char* concatencion. Para eso, voy a recorrer el arreglo de strings y voy a ir sumando el tamaño de cada string. Luego, voy a hacer un malloc de ese tamaño y voy a ir copiando cada string en el nuevo string.
    El orden de complejidad es de O(n) porque recorro el arreglo una sola vez.
    */
   int i = 0;
   int tamaño = 0;
    while (i < size){
         tamaño = tamaño + len(v[i]);
         i++;
    }
    char *concatenacion = malloc(sizeof(char) * tamaño);
    i = 0;
    int b = 0;

    while (i < size){
         int j = 0;
         while (v[i][j] != '\0'){
              concatenacion[b] = v[i][j];
              j++;
              b++;
         }
         i++;
    }
    return concatenacion;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {

    /*
    Modificar la función anterior para soportar un nuevo parámetro de tipo string. Este par´ametro
se utilizar´a para concatenarse entre cada par de string del arrelgo. La aridad de esta funci´on
ser´a: char* superConcatenateWithSep(char* v[], int size, char* s).
Ejemplo: superConcatenateWithSep(["Hola","Pepe","Tito"], 3, "..") → "Hola..Pepe..Tito"
    */
   int i = 0;
   int tamaño = 0;
    while (i < size){
         tamaño = tamaño + len(v[i]);
         i++;
    }
    char *concatenacionstep = malloc(sizeof(char) * (tamaño + len(s) * (size - 1)));
    i = 0;
    int b = 0;

    while (i < size){
         int j = 0;
         while (v[i][j] != '\0'){
              concatenacionstep[b] = v[i][j];
              j++;
              b++;
         }
         i++;
         if (i < size){
              int k = 0;
              while (s[k] != '\0'){
                   concatenacionstep[b] = s[k];
                   k++;
                   b++;
              }
         }
        
    }
     return concatenacionstep;
}


int main() {
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* v[5] = {"a", "m", "vamos", "el", "murcielago"};

    char* l = longest(v, 5);

    printf("El string mas largo es: \"%s\"\n", l);

    char* sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);

    char* scs = superConcatenateWithSep(v, 5, "...");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", scs);

    free(sc);
    free(scs);


    return 0;
}
