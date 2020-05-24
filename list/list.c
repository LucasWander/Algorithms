#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void printListItem(ListItem item) {
	printf("%d\n",item.value);
}

ListItem* listCreate() {
	return NULL;
}

ListItem* listInsertStart(ListItem *item, int value) {

	ListItem *aux = (ListItem*) malloc(sizeof(ListItem));

	aux->value = value;
	aux->next = item;

	return aux;
}


void listPrint(ListItem *item) {
	ListItem *aux;

	for(aux=item; aux != NULL; aux=aux->next) {
		printf("%d\n",aux->value);
	}
}

int listEmpty(ListItem *item) {
	if(item == NULL) {
		return 1;
	}

	return 0;
}

ListItem* listSearch(ListItem *item, int value) {
	ListItem *aux;

	for(aux=item; aux!=NULL; aux=aux->next) {
		if(aux->value == value) {
			break;
		}
	}

	return aux;
}

void listFree(ListItem *item) {

	ListItem *next = item;

	while(next!=NULL) {
		next=item->next;
		free(item);
		item = next;
	}
}

int listLastValue(ListItem *item) {
	
	ListItem *aux = item;



	while(aux->next != NULL) {
		aux = aux->next;
	}

	return aux->value;
}

ListItem* listRemove(ListItem *item, int value) {
	
	ListItem *aux = item;
	ListItem *ant = NULL;

	while(aux != NULL && aux->value != value) {
		ant = aux;
		aux = aux->next;
	}


	if(aux == NULL) {
		return item;
	}


	if(ant == NULL) 
		item = aux->next;
	else 
		ant->next = aux->next;

	free(aux);

	return item;
}