#include <stdio.h>
#include <stdlib.h>
#include "List.h"
typedef struct Node Node;
struct list {
	int length;
	Node * start;
	Node * end;
};

struct Node {
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

void inserir_pos(List * l, int p, int v)
{
    int i;
    Node * aux = l->start, * aux2;

    if (p < 0 || p > Length(l))
    {
        printf("Posicao invalida!\n");
        return;
    }

    aux2 = (Node *)malloc(sizeof(Node));
    aux2->info = v;
    aux2->next = NULL;
    if (p > 0 && p < l->length)
    {
        for (i=0; i<p-1; i++)
            aux = aux->next;

        aux2->next = aux->next;
        aux->next = aux2;
    }
    else
    {
        if (p == 0)
        {
            aux2->next = l->start;
            l->start = aux2;
        }
        if (p == l->length)
        {
            if (l->end != NULL)
                l->end->next = aux2;

            l->end = aux2;
        }
    }

    l->length++;
}

void insert_first(List * l, int v)
{
    inserir_pos(l, 0, v);
}

void insert_last(List * l, int v)
{
    inserir_pos(l, Length(l), v);
}

int search(List * l, int v)
{
    int p = 0;
    Node * aux = l->start;

    while (aux != NULL && aux->info != v)
    {
        aux = aux->next;
        p++;
    }

    return aux != NULL ? p : -1;
}
int read_index(List * l, int p)
{
    int i;
    Node * aux = l->start;
    if (p < 0 || p >= Length(l))
    {
        printf("Posicao invalida!\n");
        return -1;
    }
    for (i=0; i<p; i++)
        aux = aux->next;

    return aux->info;
}
