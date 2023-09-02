#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addLast(struct node* n, int data) {
   struct node *new = malloc(sizeof(struct node));
    new->data = data;
    int i = 0;
    while(n->next != NULL){
        n = n->next;
        i++;
    }
    n->next = new;
    return n;
}

struct node* removeFirst(struct node* n) {
    if (n == NULL){
       return NULL;} else{
            struct node *aux = n;
            n = n->next;
            free(aux);
            return n;
       }
}

struct node* join(struct node* n1, struct node* n2) {
   int i = 0;
   while(n1->next != NULL){
       n1 = n1->next;
       i++;}
    n1->next = n2;
    return n1;
}

struct node* removeData(struct node* n, int data) {
    
    /*
    Implementar la funci´on struct node* removeData(struct node* n, int data), que toma
    un puntero a una lista y un dato, y borra todas las apariciones de data en la lista. La funci´on
    debe retornar el puntero a la lista resultado   
    */
   struct node *aux = n;
   int i = 0;
    while(n->next != NULL){
        if(n->data == data){
            aux->next = n->next;
            free(n);
            n = aux->next;
        } else {
            aux = n;
            n = n->next;
        }
        i++;   
    }
    if(n->data == data){
        aux->next = NULL;
        free(n);
    }
    return aux;
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
    
    // -- Descomentar para probar --
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
