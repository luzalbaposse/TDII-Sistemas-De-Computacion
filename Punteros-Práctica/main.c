#include "common.h"
#include <stdio.h>

int main(void) {

  // 1. Primer ejemplo: repaso sintaxis
  pointer_to_int(3);

  printf("\n ---------------------------- \n\n");

  // 2. Ayuda sizeof...
  sizes();

  printf("\n ---------------------------- \n\n");

  // 3. Operaciones con lista enlazada
  struct node *n = NULL;
  int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  n = arrayToList(a, 9);

  printList(n, "Lista inicial");

  n = insert_at_beginning(n, -1);
  n = insert_at_beginning(n, -2);

  printList(n, "Lista luego de dos inserciones");

  n = delete_node(n, 2);

  printList(n, "Lista luego de borrar un nodo");

  n = reverse_list(n);

  printList(n, "Lista invertida");

  pp_reverse_list(&n);

  printList(n, "Lista invertida de nuevo");

  pp_delete_node_elegant(&n, 1);

  printList(n, "Lista sin el 1, elegante");

  return 0;
}

void printList(struct node *n, char *msg) {
  printf("%s: \n", msg);
  while (n != NULL) {
    printf("%d -> ", n->data);
    n = n->next;
  }
  printf("\n\n");
}