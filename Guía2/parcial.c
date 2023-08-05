/*
Implementar la función char* concat3(struct treString* v) que toma un puntero a una estructura treString y concatena las tres strings de la misma, una después de la otra. La función retorna las strings concatenadas y loibera toda la memoria correspondiente a la estructura treString y a sus tres strings. Si la estructura contuviera las  siguientes strings:
a -> 'comen'
b -> 'tar_el'
c -> '_codigo'
debería retornar 'comentar_el_codigo'
*/
#include <stdio.h>
#include <stdlib.h>
int strcopy_();
int strcate();

struct treString {
    char* a;
    char* b;
    char* c;
};
int strcopy_(char* dest, char* src) { // el tipo de dato que devuelve es int porque devuelve la cantidad de caracteres copiados
    /*
    Requiere: dest != NULL && src != NULL
    Modifica: dest
    Devuelve: la cantidad de caracteres copiados.
    */
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}

int strcate(char* dest, char* src) { // devuelve int porque 
    /*
    Requiere: dest != NULL && src != NULL
    Modifica: dest
    Devuelve: la cantidad de caracteres copiados.
    */
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return i;
}
char* concat3(struct treString* v) {
    /*
    Requiere: v != NULL
    Modifica: v
    Devuelve: una nueva string con la concatenación de las tres strings de v.
    */
    char* result = malloc(strlen(v->a) + strlen(v->b) + strlen(v->c) + 1);
    strcopy_(result, v->a);
    strcate(result, v->b);
    strcate(result, v->c);
    free(v->a);
    free(v->b);
    free(v->c);
    free(v);
    return result;
}
// Funcion auxiliar



int main(){
    struct treString* v = malloc(sizeof(struct treString));
    v->a = malloc(6);
    v->b = malloc(4);
    v->c = malloc(8);
    strcpy(v->a, "ravi");
    strcpy(v->b, "oles_con");
    strcpy(v->c, "tuco");
    printf("%s\n", concat3(v));
    return 0;
}