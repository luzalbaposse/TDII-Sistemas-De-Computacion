/*
Convertir un array a una lista
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node* arrayToList(int* a, int size){
    /*
    Requiere: un array 
    Devuelve: una lista
    */ 
    struct node *head = NULL;
    struct node *current = NULL;
    struct node *previous = NULL;
    int i = 0;
    if (a == NULL){
        return NULL; // Si el array es nulo, devolvemos nulo
    }else{ // Si no es nulo, creamos la lista
        while(i < size){ // Mientras no lleguemos al final del array
            current = (struct node*)malloc(sizeof(struct node)); // Creamos un nodo
            current->data = a[i]; // Le asignamos el valor del array
            current->next = NULL; // Le asignamos el puntero al siguiente nodo
            if (head == NULL){ // Si el puntero al primero nodo es nulo, el nodo actual es el primero
                head = current; // El puntero al primero nodo apunta al nodo actual
            }else{ // Si no es nulo, el nodo actual es el siguiente del nodo anterior
                previous->next = current; // El puntero al siguiente nodo del nodo anterior apunta al nodo actual
            }
            previous = current; // El nodo anterior es el nodo actual
            i++; // Incrementamos el contador
        }
        return head; // Devolvemos el puntero al primer nodo
    }
}

int main(){
    struct node *n = NULL; 
    int a[9] = {1,2,3,4,5,6,7,8,9};
    n = arrayToList(a,9);
    return 0;
}