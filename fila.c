#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *criaFila(void){
	Fila *nova = (Fila *) malloc (sizeof (Fila));
	if (nova == NULL){
		printf ("Erro.\n");
		exit (1);
	}
	nova->inicio = NULL;
	nova->fim = NULL;
	nova->tamanho = 0;
	return nova;
}

Fila *insere(Fila *f, int chave){
	No *novo = (No *) malloc (sizeof (No));
	novo->chave = chave;
	novo->prox = NULL;
	if (f->fim != NULL) f->fim->prox = novo;
	else f->inicio = novo;
	f->fim = novo;
	f->tamanho++;
	return f;
}

int retira(Fila *f){
	No *aux;
	int chave;
	if (vazia (f)) {
		printf("Fila vazia. \n");
		exit (1);
	}
	aux = f->inicio;
	chave = aux->chave;
	f->inicio = aux->prox;
	f->tamanho--;
	if (f->inicio == NULL)
		f->fim = NULL;
	free(aux);
	return chave;
}

int primeiro(Fila *f){
    return f->inicio->chave; 
}

void imprimeFila(Fila *f){
	No *aux = f->inicio;
	while (aux != NULL){
		printf ("%d ", aux->chave);
		aux = aux->prox;
	}
    printf("\n");
}