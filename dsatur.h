#ifndef DSATUR_dsatur_h
#define DSATUR_dsatur_h
#include <stdlib.h>
#include <stdio.h>
typedef struct node {
int info;
struct node* next;
} Lista;
Lista inserir (Lista* lista, int elem);
void imprimir (Lista lista);
void liberar (Lista *lista);



#endif
