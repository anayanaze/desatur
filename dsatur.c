#include "dsatur.h"





/* ========== FUNÇÕES DE LISTA ========== */
Lista* criar (void) {
 printf("running 01\n");
return NULL;
}

void inserir (Lista *lista, int a, int b){
  ITEM *aux;
  ITEM *tmp;
 
  aux = (ITEM*) malloc((int)sizeof(ITEM));    //retorno de um ponteiro genérico.
  aux->campo = b;
  aux->prox = NULL;

  lista[a]


  
  lista[a].campo++;
  if(lista[a].prox == NULL) // Caso a lista estiver vazia - Insere.	
    lista[a].prox = aux;
  else	{
    tmp = lista[a].prox;
    if (tmp->campo > b) { //insere como primeiro da lista
      aux->prox = tmp;
      lista[a].prox = aux;
    } 		          //insere os vértices ordenados
    else if (tmp->prox == NULL) { 
      aux->prox = tmp->prox;
      tmp->prox = aux;  
    }
    else {
      while((tmp->prox != NULL) &&(tmp->prox->campo < b))
	tmp = tmp->prox;
      aux->prox = tmp->prox;
      tmp->prox = aux;  
    }
  }
}

/*
Lista inserir (Lista* lista, int elem) {
Lista* novo = (Lista*)malloc((int)sizeof(Lista)); ;
novo->info = elem;
lista->next = novo;
return lista;
}*/
/*
void imprimir (Lista *graph){
	Lista *v = graph; 
	int i, j; 

	for (i = 0; i < 20; i ++){
		for (j = 0; v[i] != NULL; j++){
			printf("%d, ", v[i]->info);
			v[i] = v[i]->next;
	}
		printf("\n");
	}


} */

void imprimir (Lista lista){
	Lista v; /*var. para percorrer a lista*/
	for (v = lista; v != NULL; v = v.next) {
		printf("Valor: %d\t", v.info);
	}
}

Lista* remover (Lista *lista, int elem){
	Lista* prv = NULL; Lista* v = lista;
	while ((v != NULL) && (v->info != elem)) {
		prv = v;
		v = v->next;
	}
	if (v == NULL) { return lista; }
	if (prv == NULL) { lista = v->next; }
	else { prv->next = v->next; }
	free (v);
	return lista;
}
void liberar (Lista *lista) {
	while (lista != NULL) {
		Lista *aux = lista->next; /*guarda ref. p/ prox.*/
		free (lista); /*libera a memoria apontada por v*/
		lista = aux; /*faz v apontar p/ o prox. elem.*/
	}
}