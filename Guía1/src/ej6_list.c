#include <stdio.h>
#include <stdlib.h>

/*

Suponer la siguiente estructura de nodos para una lista:

struct node {
int data;
struct node *next;
};



*/

struct node {
    int data;
    struct node *next;
};

struct node* addLast(struct node* n, int data) {
/*
a. Implementar la función struct node* addLast(struct node* n, int data), que toma un
puntero al primer nodo de la lista y agrega en el último lugar de la lista un nuevo nodo que
contiene el dato pasado por par´ametro. La función debe retornar el puntero al primer nodo de
la lista.
*/
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = 0;
    if(n == 0){
        n = newNode;
        } else {

            struct node *aux = n;
            while(aux-> next !=0){
                aux = aux -> next;
            }
            aux -> next = newNode;

        }
        return n;
}

struct node* removeFirst(struct node* n) {

    /*
    b. Implementar la función struct node* removeFirst(struct node* n), que toma un puntero
    al primer nodo de la lista, borra el primer nodo de la lista y retorna el puntero al nuevo primer
    elemento de la lista (el que antes era el segundo elemento).
    */
   if(n == 0){
    return 0;
   }
   struct node *aux = n;
   n = n -> next;
   free(aux);
   return n;
}

struct node* join(struct node* n1, struct node* n2) {

    /*
    c. Implementar la función struct node* join(struct node* n1, struct node* n2), que toma
    dos punteros a listas y las concatena: primero n1 y luego n2. La lista resultado utilizar´a los nodos
    de las listas pasadas por par´ametro. Esta función debe retonar el puntero al primer elemento de
    la lista resultado.
    */
   if(n1 == 0){
    return n2;
   }
    if(n2 == 0){
    return n1;
    }
    struct node *aux = n1;  
    while(aux->next != 0){
        aux = aux -> next;
    }
    aux -> next = n2;
    return n1;
    
}

struct node* removeData(struct node* n, int data) {
    /*
    d. Implementar la función struct node* removeData(struct node* n, int data), que toma
un puntero a una lista y un dato, y borra todas las apariciones de data en la lista. La función
debe retornar el puntero a la lista resultado.
    */
    if(n == 0){
         return 0;
    }
    struct node *aux = n;
    struct node *aux2 = n;
    while(aux->next != 0){
        if(aux->data == data){
            aux2->next = aux->next;
            free(aux);
            aux = aux2->next;
        } else {
            aux2 = aux;
            aux = aux->next;
        }
    }
    if(aux->data == data){
        aux2->next = 0;
        free(aux);
    }
    
    
    return 0;
}

void printList(struct node* n) {
    printf("[");
    if(n == 0){
        printf("]\n");
    } else {
        while(n->next != 0){
            printf("%i, ", n->data);
            n = n->next;
        }
        printf("%i]\n", n->data);
    }
}

int main() {
    /*
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct node *n1 = NULL;
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n1\n");
    n1 = addLast(n1, 2021);
    n1 = addLast(n1, 42);
    n1 = addLast(n1, 0x400);
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n2\n");
    struct node *n2 = NULL;
    n2 = addLast(n2, 0);
    n2 = addLast(n2, 42);
    printList(n2);
    printf("\n");
    
    printf("Join lista n1 y n2: n3\n");
    struct node *n3 = join(n1, n2);
    printList(n3);
    printf("\n");

    printf("RemoveFirst: n3\n");
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");
    
    printf("RemoveData: 42\n");
    n3 = removeData(n3, 42);
    printList(n3);
    printf("\n");
    
    printf("RemoveFirst dos veces: n3\n");
    n3 = removeFirst(n3);
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");

    // */

    return 0;
}
