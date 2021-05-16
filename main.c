#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cria elementos da pilha
typedef struct nome {
  char name[55];
  //Chama o próximo da pilha
  struct nome *prox;
} NOME;

//Cria a pilha
typedef struct pilha {
  //Cria o topo
  NOME* topo;
} PILHA;

//Inicializa a pilha
void startup (PILHA* pilha) {
  pilha->topo = NULL;
}

void push (PILHA* pilha, char nome[]) {
  //Cria o nome
  NOME* neime = (NOME*) malloc (sizeof(NOME));
  //(destino, origem)
  strcpy (neime->name, nome);
  //prox = topo
  neime->prox = pilha->topo;
  //Cria um novo topo
  pilha->topo = neime;
} 

void pop (PILHA* pilha) {
  //Cria auxiliar que recebe o topo
  NOME* aux = pilha->topo;
  //Topo recebe o proximo, já que o topo foi apagado
  pilha->topo = aux->prox;
  //apaga o topo
  free (aux);
}

void printar (PILHA* pilha) {
  //Instancia o topo
  NOME* neime = pilha->topo;
  //loop para escrever a pilha
  while (neime != NULL) {
    printf ("%s\n", neime->name);
    //topo = proximo.
    neime = neime->prox;
  }
}

int main (void) {
  PILHA pilha;
  startup(&pilha);
  char nome[55] = "Jose";
  char nome2[55] = "Filomena";
  push(&pilha, nome);
  push(&pilha, nome2);
  printar(&pilha);

  return 0;
}