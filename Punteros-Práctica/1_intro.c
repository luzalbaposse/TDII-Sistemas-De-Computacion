#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void pointer_to_int(int value) {

  int *p;
  p = malloc(sizeof(int));
  // p es un puntero a un entero
  assert(p != NULL);
  printf("addr pointed to by p: %p\n", p);
  

  *p = value;
  printf("value of p: %d\n", *p);

  printf("addr of p: %p \n", &p);
  // p es una variable que contiene la dirección de memoria de un entero
}

typedef struct airport {
  char *name;
  float latitude;
  float longitude;
  struct airport *next;
} Airport;

void sizes() {
  printf("Size of int: %lu\n", sizeof(int));
  printf("Size of double: %lu\n", sizeof(double));
  printf("Size of char: %lu\n", sizeof(char));
  printf("Size of float: %lu\n", sizeof(float));
  printf("Size of a pointer to a char: %lu\n", sizeof(char *));
  printf("Size of Airport: %lu\n", sizeof(Airport));
}