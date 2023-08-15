#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/*
El desafío es programar la función int check(struct node* t) que determina si el 
árbol binario de búsqueda pasado por parámetro está ordenado, y aún más! preguntarse 
si está función se puede resolver en O(n).
*/
struct node {
   int dato;
   struct node* izq;
   struct node* der;
};

bool isOrdered(struct node* root, int* prev) {
    /*
    La logica es la siguiente: si el arbol esta vacio, es ordenado, 
    si no, llamo a la funcion recursiva isOrdered con el subarbol izquierdo, 
    y si este es ordenado, actualizo el valor de prev con el dato actual y 
    llamo a la funcion recursiva con el subarbol derecho, si este es ordenado, 
    el arbol es ordenado, si no, no lo es
    */
    // Si el arbol esta vacio, es ordenado
    if (root == NULL) {
        return true;
    }
    // Si el subarbol izquierdo no es ordenado, el arbol no es ordenado
    if (!isOrdered(root->izq, prev)) {
        return false;
    }
    // Si el dato actual es menor o igual al anterior, el arbol no es ordenado
    if (root->dato <= *prev) {
        return false;
    }
    // Actualizo el valor anterior
    *prev = root->dato;
    // Si el subarbol derecho no es ordenado, el arbol no es ordenado
    return isOrdered(root->der, prev);
}

int check(struct node* t) {
    /*
    La logica aca es que si el arbol esta vacio, es ordenado, si no, llamo a la funcion recursiva isOrdered que me devuelve true si el arbol es ordenado y false si no lo es
    */
    int prev = -1;
    return isOrdered(t, &prev);
}

int main(){
    //Prueba
    struct node* root = NULL;
    struct node* aux = NULL;
    for (int i = 0; i < 10; i++) {
        /*
        Este for lo que hace es crear un arbol binario de busqueda con los numeros del 0 al 9
        */
        aux = (struct node*)malloc(sizeof(struct node));
        aux->dato = i;
        aux->izq = NULL;
        aux->der = NULL;
        if (root == NULL) {
            root = aux;
        } else {
            struct node* current = root;
            while (true) {
                if (aux->dato < current->dato) {
                    if (current->izq == NULL) {
                        current->izq = aux;
                        break;
                    } else {
                        current = current->izq;
                    }
                } else {
                    if (current->der == NULL) {
                        current->der = aux;
                        break;
                    } else {
                        current = current->der;
                    }
                }
            }
        }
    }

    //printeo el arbol 
    printf("Arbol binario de busqueda:\n");
   // for para printear
    for (int i = 0; i < 10; i++) {
        struct node* current = root;
        while (true) {
            if (current->dato == i) {
                printf("%d -> ", current->dato);
                break;
            } else if (i < current->dato) {
                current = current->izq;
            } else {
                current = current->der;
            }
        }
    }
    printf("El arbol es ordenado? %d\n", check(root)); // deberia imprimir 1
   
   // Caso en el que retornaria 0 con otro arbol

    struct node* root2 = NULL;
    struct node* aux2 = NULL;
    for (int i = 0; i < 10; i++) {
        /*
        Este for lo que hace es crear un arbol binario de busqueda con los numeros del 9 al 0
        */
        aux2 = (struct node*)malloc(sizeof(struct node));
        aux2->dato = 9 - i;
        aux2->izq = NULL;
        aux2->der = NULL;
        if (root2 == NULL) {
            root2 = aux2;
        } else {
            struct node* current = root2;
            while (true) {
                if (aux2->dato < current->dato) {
                    if (current->izq == NULL) {
                        current->izq = aux2;
                        break;
                    } else {
                        current = current->izq;
                    }
                } else {
                    if (current->der == NULL) {
                        current->der = aux2;
                        break;
                    } else {
                        current = current->der;
                    }
                }
            }
        }
    }

    //printeo el arbol 
    printf("Arbol binario de busqueda:\n");
    // for para printear
    for (int i = 0; i < 10; i++) {
        struct node* current = root2;
        while (true) {
            if (current->dato == i) {
                printf("%d -> ", current->dato);
                break;
            } else if (i < current->dato) {
                current = current->izq;
            } else {
                current = current->der;
            }
        }
    }
    printf("El arbol es ordenado? %d\n", check(root2)); // deberia imprimir 0

// esta resulto en O(n) porque recorre todos los nodos del arbol una sola vez y hace operaciones constantes en cada uno de ellos