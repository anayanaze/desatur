//Ana Flávia Yanaze, Filipe de Freitas
//Trabalho de coloração de grafos - Matemática Discreta 2017.1
//Prof. Ricardo Luders

#include <stdio.h>
#include <stdlib.h>

#define VERTICES 20
#define BUFLEN 256

enum boolean {
    true = 1, false = 0
};
typedef  enum boolean  bool;


typedef struct vertice {
	int id; 
	char cor;
	int grau_saturacao;
	int arestas;
	bool colorido; //variavel booleana para decidir se o vértice está colorido ou nao

} Vertice; 

Vertice vertice[VERTICES+1];
int maior_grau (int* grau_n);

int main (){
	int graph[VERTICES+1][VERTICES+1]; //tamanho maximo
	int i, v, data, j, grau[VERTICES+1], nos_pintados = 0;
	int n_cromatico = 0; //numero cromatico
	char straux[BUFLEN];
    FILE* input;

	char aux;
	input = fopen("entrada.csv","r+");
    
    if(!input) { // testa o arquivo, se n abrir mostra msg de erro.
        printf ("Nao foi possivel abrir o arquivo %s!\n", "entrada.csv");
        exit(1);
    }

    //inicializa 
  	for (i = 1; i <= 20; i++){
  		vertice[i].id = i;
  		vertice[i].cor = '0'; 
  		vertice[i].grau_saturacao = 0;
  		vertice[i].arestas = 0;
  		vertice[i].colorido = false; 
  	}

    //conta numero de valores de uma linha
  	for (i = 1; i <= VERTICES; i++){
  		while (aux != '\n'){
  			if (aux == ','){
  				grau[i]++;
  			}
  			aux = getc(input);
  		}
  		aux = getc(input);
  	}

  	for (i = 1; i <= VERTICES; i++){
  		printf("Grau do no %d: %d\n", i, grau[i]);
  	}


  	rewind(input);

  	for (i = 1; i <= VERTICES; i++){
  		for (j = 1; j <= grau[i]+1; j++){
  			fscanf(input, "%s, ", straux);
  			data = atoi (straux);
  			graph[i][j] = data;
  		}
  	}

  	for(i = 1; i<= VERTICES; i++){
  		for (v = 1; v <= grau[i]+1; v++) {

  			if (v == 1){
  				printf("Linha %d: ", graph[i][v]);
  			}
  			else if (v == grau[i]+1)
  				printf("%d", graph[i][v]);
  			else
				printf("%d, ", graph[i][v]);
  		}
  		  		printf("\n");
  	}

bool nao_coloriu, repetiu = false;
char cor_inicial = 'A';
char cor_pintada;

  	while (nos_pintados < VERTICES){

  		no_pintado = maior_grau(grau); //nó a ser colorido
  		nao_coloriu = true;
  		cor_pintada = cor_inicial;

  		while (nao_coloriu){ //colore o nó e atribui grau de saturacao para nos adjacentes
  			for (j = 1+1; i <= grau[no_pintado]; j++){
				if (vertice[graph[no_pintado][j]].cor == cor_pintada)
					repetiu = true;				
  			}

			if (!(repetiu)){
				nao_coloriu = false;
				nos_pintados++;
				vertice[no_pintado].colorido = true;
				verce[no_pintado].cor = cor_pintada;
				for (j = 1+1; i <= grau[no_pintado]+1; j++){
					vertice[graph[no_pintado][j]].grau_saturacao++; //aumenta grau de saturação dos nós adjacentes 
  				}
			}
			else
				cor_pintada++;
  		}

  	}

  	for (i = 1; i < VERTICES+1; i++){
  		for (j = 2; j < grau[i]; j++){
  			if (graph[i][j] == i)
  				continue;
  			else
  				vertice[i].arestas++;
  		}
  	}

  	fclose(input);

  	FILE * output;
  	output = fopen ("output.csv", "w+");
	fprintf(output, "%s | %s | %s | %s", "Numero_Nos", "Numero_Arestas", "Grau_Nos", "Cores");
	fprintf(output, "%s | %s | %s | %d", "Numero_Nos", "Numero_Arestas", "", 2012);
    
    for (i = 1; i < VERTICES+1; i++){
		fprintf(output, "%d | %d | %d | %c\n", i, vertice[i].arestas, grau[i], vertice[i].cor);

    }

    fclose(fp);
    

}



int maior_grau (int* grau_n){ //funcao define qual nó vai ser colorido

	int i, maior = 0, j = 2, empate_id[VERTICES+1], n_iguais = 0;
	bool empate = false, achou = false;

	for (i = 1; i < VERTICES+1; i++){
		if (grau_n[i] > maior){
			grau_n[i] = maior;
			achou = true;
			n_iguais=1;
                        empate_id[1] = i;
		}
                else if(grau_n[i] == maior)
                       n_iguais++;

		if (n_iguais > 1){ //se houve empate no grau, desempata pelo grau de saturacao
			empate_id[j] = i; //guarda id dos empates
                        empate=true;
			j++; //contador de empates
		}
        }
	if (empate){ //desempata pelo grau de saturação
		
		for (i = 1; i <= VERTICES; i++){ //desempata pelo grau de saturacao
			if (empate_id[i] == vertice.id[i]){
                            
			}
		}
	}




	return maior; //retorna id do nó a ser colorido
}