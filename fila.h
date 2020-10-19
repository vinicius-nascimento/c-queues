#ifndef FILA_H
#define FILA_H


typedef struct no {
	int chave;
	struct no *prox;
} No;

typedef struct fila {
	unsigned int tamanho;
	No *inicio;
	No *fim;
} Fila;

Fila *criaFila();

Fila *insere(Fila *f, int chave);

int retira(Fila *f);

int primeiro(Fila *f);

void imprimeFila(Fila *f);

#endif