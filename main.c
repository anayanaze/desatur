//Ana Flávia Yanaze, Fillipe de Freitas
//Trabalho de coloração de grafos - Matemática Discreta 2017.1
//Prof. Ricardo Luders

#include "dsatur.h"
#define VERTICES 20
#define BUFLEN 256

int main(int argc, const char * argv[]) {
    Lista graph[VERTICES+1]; //vetor de listas
   	char str[BUFLEN];
    FILE* input;
	int i, data, j, tam_linha[VERTICES+1];
	char aux;
	input = fopen("entrada.csv","r+");
    
    if(!input) { // testa o arquivo, se n abrir mostra msg de erro.
        printf ("Nao foi possivel abrir o arquivo %s!\n", "entrada.csv");
        exit(1);
    }
    
  	for (i=1; i <= VERTICES; i++){ //inicializando listas
    	graph[i].info = 0;
    	graph[i].next = NULL;
  	}

//conta numero de numeros de uma linha
  	for (i = 1; i <= VERTICES; i++){
  		while (aux != '\n'){
  			if (aux == ','){
  				tam_linha[i]++;
  			}
  			aux = getc(input);
  		}
  		tam_linha[i] = tam_linha[i] + 1; 
  	}

  	rewind(input);

  	for (i = 1; i <= VERTICES; i++){
  		for (j = 1; j <= tam_linha[i]; j++){
  			fscanf(input, "%s, " &str );
  			data = atoi (str);
  			inserir (graph, i, data);


  			/*Lista* novo;
  			novo.info = data;
  			graph.next = novo;*/
  			//graph[i] = inserir(graph[i], data);
  		}
  	}

  	for(i = 1; i<= VERTICES; i++){
  		Lista v;
  		for (v = graph; v != NULL; v = v.next) {
		printf("Valor: %d\t", v.info);
  		printf("\n");
  	}



    return 0;
}
