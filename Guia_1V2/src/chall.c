#include <stdio.h>
#include <stdlib.h>
struct list {
    struct node* first;
};
struct node {
    char* data;
    struct node* first;
};
/*
void separarParesImpares(int* array1, int size1, int* array2, int size2, int** pares, int* sizePares, int** impares, int* sizeImpares)
Toma dos arreglos de enteros de tamaño diferente y retorna dos nuevos arreglos, uno con todos los números pares encontrados en los dos arreglos de entrada, y otro con todos los números impares. Si no hay pares o impares, retornar un cero.
*/

void separarParesImpares(int* array1, int size1, int* array2, int size2, int** pares, int* sizePares, int** impares, int* sizeImpares){
    /*
    Requiere: array1, array2, pares, impares != NULL
    Devuelve: el listado de pares e impares según corresponda. 

    */
    int* paresAux = (int*)malloc(sizeof(int));
    int* imparesAux = (int*)malloc(sizeof(int));
    int sizeParesAux = 0;
    int sizeImparesAux = 0;
    for(int i = 0; i < size1; i++){
        if(array1[i]%2 == 0){
            paresAux[sizeParesAux] = array1[i];
            sizeParesAux++;
            paresAux = (int*)realloc(paresAux, sizeof(int)*(sizeParesAux+1));
        }else{
            imparesAux[sizeImparesAux] = array1[i];
            sizeImparesAux++;
            imparesAux = (int*)realloc(imparesAux, sizeof(int)*(sizeImparesAux+1));
        }
    }
    for(int i = 0; i < size2; i++){
        if(array2[i]%2 == 0){
            paresAux[sizeParesAux] = array2[i];
            sizeParesAux++;
            paresAux = (int*)realloc(paresAux, sizeof(int)*(sizeParesAux+1));
        }else{
            imparesAux[sizeImparesAux] = array2[i];
            sizeImparesAux++;
            imparesAux = (int*)realloc(imparesAux, sizeof(int)*(sizeImparesAux+1));
        }
    }
    if(sizeParesAux == 0){
        *pares = NULL;
        *sizePares = 0;
    }else{
        *pares = paresAux;
        *sizePares = sizeParesAux;
    }
    if(sizeImparesAux == 0){
        *impares = NULL;
        *sizeImpares = 0;
    }else{
        *impares = imparesAux;
        *sizeImpares = sizeImparesAux;
    }

}

// Separarpareseimpares sin usar realloc

void separarParesEImpares2(int* array1, int size1, int* array2, int size2, int** pares, int* sizePares, int** impares, int* sizeImpares){
    /*
    Requiere: array1, array2, pares, impares != NULL
    Devuelve: el listado de pares e impares según corresponda. 

    */
    int* paresAux = (int*)malloc(sizeof(int)*size1);
    int* imparesAux = (int*)malloc(sizeof(int)*size1);
    int sizeParesAux = 0;
    int sizeImparesAux = 0;
    for(int i = 0; i < size1; i++){
        if(array1[i]%2 == 0){
            paresAux[sizeParesAux] = array1[i];
            sizeParesAux++;
        }else{
            imparesAux[sizeImparesAux] = array1[i];
            sizeImparesAux++;
        }
    }
    for(int i = 0; i < size2; i++){
        if(array2[i]%2 == 0){
            paresAux[sizeParesAux] = array2[i];
            sizeParesAux++;
        }else{
            imparesAux[sizeImparesAux] = array2[i];
            sizeImparesAux++;
        }
    }
    if(sizeParesAux == 0){
        *pares = NULL; // no se puede hacer free de NULL
        *sizePares = 0;
    }else{
        *pares = paresAux;
        *sizePares = sizeParesAux;
    }
    if(sizeImparesAux == 0){
        *impares = NULL;
        *sizeImpares = 0;
    }else{
        *impares = imparesAux;
        *sizeImpares = sizeImparesAux;
    }

}
/*
char* lista2string(struct list* l)
Toma una lista de nodos que contienen punteros a string. Recorre la lista y concatena todas las string en una sola que retorna. La lista original debe ser liberada.

*/
char* lista2string(struct list* l){
    /*
    Requiere: l != NULL
    Devuelve: un string con todos los datos de la lista concatenados. 
    */
    
    struct node* aux = l->first;
    char* string = (char*)malloc(sizeof(char));
    int size = 0;
    while(aux != NULL){
        for(int i = 0; aux->data[i]!='\0'; i++){
            string[size] = aux->data[i];
            size++;
            string = (char*)realloc(string, sizeof(char)*(size+1));
        }
        aux = aux->first;
    
    }
    return string;
}

int main(){
// pruebo lista2string
struct list* lista = (struct list*)malloc(sizeof(struct list));
struct node* nodo1 = (struct node*)malloc(sizeof(struct node));
struct node* nodo2 = (struct node*)malloc(sizeof(struct node));

lista->first = nodo1;
nodo1->data = "hola";
nodo1->first = nodo2;
nodo2->data = "mundo";
nodo2->first = NULL;

char* string = lista2string(lista);
printf("%s\n", string);
// pruebo separarparesimpares
int array1[5] = {1,2,3,4,5};
int array2[5] = {6,7,8,9,10};
int* pares;
int* impares;
int sizePares;
int sizeImpares;
separarParesImpares(array1, 5, array2, 5, &pares, &sizePares, &impares, &sizeImpares);
printf("Pares: ");
for(int i = 0; i < sizePares; i++){
    printf("%d ", pares[i]);
}
printf("\nImpares: ");
for(int i = 0; i < sizeImpares; i++){
    printf("%d ", impares[i]);
}
printf("\n");

// Pruebo separarpareseimpares2
int* pares2;
int* impares2;
int sizePares2;
int sizeImpares2;
separarParesEImpares2(array1, 5, array2, 5, &pares2, &sizePares2, &impares2, &sizeImpares2);
printf("Pares: ");
for(int i = 0; i < sizePares2; i++){
    printf("%d ", pares2[i]);
}
printf("\nImpares: ");
for(int i = 0; i < sizeImpares2; i++){
    printf("%d ", impares2[i]);
}
printf("\n");

return 0;
}
