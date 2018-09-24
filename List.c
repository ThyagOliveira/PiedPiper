#include <stdio.h>
#include <stdlib.h>
#include "List.h"
typedef struct node Node;
typedef struct list List;

struct list {
	int length;
	Node * start;
};
struct node {
    byte value;
	unsigned frequency;
	Node * next;
};

List * create() {
	List * l = (List *)malloc(sizeof(List));
	l->start = NULL;
	l->length = 0;
	return l;
}

Node * createNode(byte value, unsigned frequency) {
	Node * n = (Node *)malloc(sizeof(Node));
	n->value = value;
	n->frequency = frequency;
	return n;
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
	l->length = 0;
}


int length(List * l) {
	return l->length;
}

int is_empty(List * l) {
	return length(l) == 0;
}

void insertNode(byte value, unsigned frequency, List *l)
{    
    Node * n = createNode(value, frequency);
    if (!l->start)
    {
        l->start= n;
    }
    else if (n->frequency < l->start->frequency)
    {
        n->next = l->start;
        l->start = n;
    }
    else
    {        
        Node *foo = l->start->next;        
        Node *bar = l->start;        
        while (foo && foo->frequency <= n->frequency)
        {
            bar = foo;
            foo = bar->next;
        }
        bar->next = n;
        n->next = foo;
    }
    l->length++;
}

void printList(List * l)
{
    Node * foo = l->start;    
    while (foo != NULL)
    {
        printf("[ ");
        printf("%c, %d", foo->value, foo->frequency);
        printf("]\n");
        foo = foo->next;
    }    
}