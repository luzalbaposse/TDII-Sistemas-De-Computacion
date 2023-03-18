#include "common.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*Versión Luz*/
struct node *insert_at_beginning(struct node *head, int data) {
     // Crear un nuevo nodo que tiene la data que se pasa por parámetro, este se inserta al inicio de la lista
  struct node *nuevoNodo = (struct node*)malloc(sizeof(struct node));
  nuevoNodo->data = data; // le paso la data q me dan por parametro
  nuevoNodo->next = 0; // este nodo va a apuntar a 0 
  if(head == 0){ // Si la lista esta vacia
    head = nuevoNodo; // Este va a ser el primer nodo
  } else { // s no esta vacia
    nuevoNodo->next = head; // el nuevo nodo va a apuntar al primer nodo
    head = nuevoNodo; // el nuevo nodo va a ser el primer nodo
  }
  return head;
  return NULL;
}
/*
Opción 2: Versión de Tomi Ibarra
struct node *insert_at_beginning(struct node *head, int data){
  struct node* nuevo = (struct node*)malloc(sizeof(struct node));
  nuevo -> data = data;
if (head == NULL){
  head = nuevo;
  nuevo -> next = NULL;
  return nuevo;
}
}
*/

struct node *delete_node(struct node *head, int key) {
  // Elimino un nodo de la lista que tenga la data key
  // Si no existe un nodo con esa data, no hago nada
  // Si la lista está vacía, no hago nada
  // Si el nodo a eliminar es el primero, devuelvo el segundo nodo
  // Si el nodo a eliminar es el último, devuelvo el primer nodo
  // Si el nodo a eliminare está 
  struct node *ayuda = head;
  struct node *anterior = NULL;
  while (ayuda != NULL && ayuda->data != key){ // recorro la lista hasta que encuentre el nodo que quiero eliminar
    anterior = ayuda; // me voy a guardar el nodo anterior
    ayuda = ayuda->next; // y le digo a ayuda que apunte al siguiente nodo
  }
  if (ayuda == NULL){ // si ayuda es igual a NULL, significa que no encontre el nodo que quiero eliminar
    return head; // entonces devuelvo la lista tal cual
  } 
  if (anterior == NULL){ // si anterior es null, entonces el q quiero eliminar es el primero
    head = ayuda -> next; // asi que le digo a head que apunte al siguiente nodo
  } else { // si anterior no es null, entonces el q quiero eliminar no es el primero
    anterior -> next = ayuda -> next;  // entonces le digo al nodo anterior que apunte al siguiente nodo
  }
  free(ayuda); // libero el nodo que quiero eliminar
  return head; // devuelvo la lista
}

struct node *reverse_list(struct node *head) {
  // El objetivo es dar vuelta la lista 
  // si la lista está vacía, no hago nada
  // si la lista tiene un solo nodo, no hago nada
  // si la lista tiene dos nodos o mas, los invierto
  struct node *anterior = NULL; // tengo un nodo anterior que apunta a null
  struct node *siguiente = NULL; // tengo un nodo siguiente que apunta a null
  struct node *actual = head; // y tengo el nodo en el que estoy parada
  while (actual != NULL){ // si el nodo actual, no apunta a null entonces tengo que seguir pasando la lista
    siguiente = actual -> next; // voy ahacer que el siguiente sea el actual que aputna a next
    actual -> next = anterior; // acá actual que apunta a next, es el anterior
    anterior = actual; // y le digo al anterior ¡¡ey!! vos sos el actual
    actual = siguiente; // entonces el actual es el siguiente
  } 
  head = anterior; // head es el anterior 
  return head; // 
}