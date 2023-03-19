#include <stdio.h>
#include <stdlib.h>

struct list {
    struct node *first;
    int size;
};

struct node {
    struct node *next;
    struct node *prev;
    char *data;
};

struct list* listNew() {
    struct list* l = (struct list*)malloc(sizeof(struct list));
    l->first = 0;
    l->size = 0;
    return l;
}

void listDelete(struct list* l) {
    struct node* n = l->first;
    while ( n != 0 ) {
        struct node* r = n;
        n = n->next;
        free(r);
    }
    free(l);
}

void listPrint(struct list* l) {
    struct node* n = l->first;
    printf("[");
    while ( n != 0 ) {
        printf("\"%s\"", n->data);
        n = n->next;
        if( n != 0 ) {
            printf(",");
        }
    }
    printf("]");
}

struct list* addFirst(struct list* l, char* data) {
    // agregar el struct como primero de una lista utilizando doble puntero
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = l->first;
    n->prev = 0;
    if (l->first != 0) {
        l->first->prev = n;
    }
    l->first = n;
    l->size++;
    return 0;
}

struct list* removeFirst(struct list* l) {

    // eliniar el primer strcut de una lista usando doble puntero
    struct node* n = l->first;
    if (n != 0) {
        l->first = n->next;
        if (l->first != 0) {
            l->first->prev = 0;
        }
        free(n);
        l->size--;
    }

    
    return 0;
}

struct list* removeNode(struct list* l, struct node* n) {
    
    // eliminar un nodo con doble puntero
    if (n != 0) {
        if (n->prev != 0) {
            n->prev->next = n->next;
        } else {
            l->first = n->next;
        }
        if (n->next != 0) {
            n->next->prev = n->prev;
        }
        free(n);
        l->size--;
    }
    
    return 0;
}

struct list* removeNodei(struct list* l, int i) {

    // COMPLETAR
    
    return 0;
}

int main() {
    /*
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct list* l = listNew();
    l = addFirst(l, "back");
    struct node* toRemove1 = l->first;
    l = addFirst(l, "swim");
    l = addFirst(l, "for");
    l = addFirst(l, "anything");
    struct node* toRemove2 = l->first;
    l = addFirst(l, "save");
    l = addFirst(l, "never");
    struct node* toRemove3 = l->first;
    l = addFirst(l, "I");
    listPrint(l);
    printf("\n\n");

    printf("RemoveFirst\n");
    l = removeFirst(l);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove1->data);
    l = removeNode(l, toRemove1);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove2->data);
    l = removeNode(l, toRemove2);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove3->data);
    l = removeNode(l, toRemove3);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 0\n");
    l = removeNodei(l, 0);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 1\n");
    l = removeNodei(l, 1);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 0\n");
    l = removeNodei(l, 0);
    listPrint(l);
    printf("\n\n");

    listDelete(l);

    // */

    return 0;
}
