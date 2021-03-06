#include "lista.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.codon == d.codon){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last)
				l->last = tmp;
			free(aux);
			aux->prox = NULL;
		}
		else
			aux = aux->prox;
	}
}


void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%s\t", aux->data.codon);
		aux = aux->prox;
	}
    printf("\n");
}

int LSomarRestante(Block *Aux1, Block *Aux2){
	int aux = 1;
	while(Aux2 != NULL && Aux1 != NULL && strcmp(Aux1->data.codon,Aux2->data.codon) == 0){
		aux++;
		Aux1 = Aux1->prox;
		Aux2 = Aux2->prox;
	}
	return aux;
}
