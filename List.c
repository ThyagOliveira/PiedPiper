#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct node Node;

struct list {
	int length;
	Node * start;
	Node * end;
};

struct node {
	int info;
	Node * next;
};

List * create() {
	List * l = (List *)malloc(sizeof(List));
	l->start = NULL;
	l->end = NULL;
	l->length = 0;
	return l;
}

List * addNode(List * l, int info) {
	Node * n = (Node *)malloc(sizeof(Node));
	n->info = info;
	l->start = n;
	l->end = n;
	l->length = l->length + 1;
	return l;
}

void destroy(List * l) {
	if (l != NULL) {
		clear(l);
		free(l);
	}
}

void clear(List * l) {
	Node * aux = l->start;
	while (aux != NULL) {
		Node * aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
	l->start = NULL;
	l->end = NULL;
	l->length = 0;
}


int length(List * l) {
	return l->length;
}

int is_empty(List * l) {
	return length(l) == 0;
}
