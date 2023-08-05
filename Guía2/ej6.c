#include <stdio.h>
#include <stdlib.h>


struct treString{
char *a;
char *b;
char *c;
};

// Funcion que toma un doble puntero a una string y calcula su longitud.
int len(char **s){
    int i = 0;
    while (**s != NULL){
        i++;
        (*s)++;
    }
    return i;
}

/*
Implementar la función char* concat3(struct treString* v) que toma un puntero a una estuctura
treString y concatena las tres strings de la misma, una después de la otra. La función retorna las strings
concatenadas y libera toda la memoria correspondiente a la estuctura treString y a sus tres strings.
*/

char* concat3(struct treString*v){
    int lenA = len(&(v->a));
    int lenB = len(&(v->b));
    int lenC = len(&(v->c));
    char *concat = malloc(sizeof(char)*(lenA+lenB+lenC+1));
    char *aux = concat;
    while (*(v->a) != NULL){
        *aux = *(v->a);
        aux++;
        (v->a)++;
    }
    while (*(v->b) != NULL){
        *aux = *(v->b);
        aux++;
        (v->b)++;
    }
    while (*(v->c) != NULL){
        *aux = *(v->c);
        aux++;
        (v->c)++;
    }
    *aux = NULL;
    free(v->a);
    free(v->b);
    free(v->c);
    free(v);
    return concat;
}