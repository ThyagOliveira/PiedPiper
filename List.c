#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct no No;

struct list {
	int length;
	No * start;
	No * end;
	
};

struct no {
	int info;
	No * next;
};

List * create() {
	List * l = (List *)malloc(sizeof(List));
	l->start = NULL;
	l->end = NULL;
	l->length = 0;
	return l;
}

void destroy(List * l) {
	if (l != NULL) {
		clear(l);
		free(l);
	}
}

void clear(List * l) {
	No * aux = l->start;
	while (aux != NULL) {
		No * aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
	l->start = NULL;
	l->end = NULL;
	l->length = 0;
}


int length(List * l)
{
	return l->length;
}

int is_empty(List * l)
{
	return length(l) == 0;
}
