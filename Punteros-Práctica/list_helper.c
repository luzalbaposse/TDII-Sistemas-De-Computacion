#include "common.h"
#include <stdio.h>
#include <stdlib.h>

struct node *arrayToList(int *a, int size) {

  struct node *prev = NULL;
  struct node *first = NULL;

  for (int i = 0; i < size; i++) {

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = a[i];
    current->next = NULL;

    if (prev != NULL) {
      // existe un elemento previo
      // estoy en el segundo o adelante
      prev->next = current;
    } else {
      // no existe un elemento previo
      first = current;
    }

    prev = current;
  }
  return first;
}