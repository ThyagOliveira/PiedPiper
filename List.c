#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "ValueFrequency.h"
typedef struct node Node;
typedef struct list List;

struct list {
	int length;
	Node * start;
};
struct node {
    ValueFrequency * valueFrequency;
	Node * next;
};

List * ListFactory() {
	List * l = (List *)malloc(sizeof(List));
	l->start = NULL;
	l->length = 0;
	return l;
}

Node * createNode(ValueFrequency * vf) {
	Node * n = (Node *)malloc(sizeof(Node));    
    n->valueFrequency = vf;
	return n;
}

void ListDestroyer(List * l) {
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
    ValueFrequency * vf = ValueFrequencyFactory(value, frequency);
    Node * n = createNode(vf);
    if (!l->start)
    {
        l->start= n;
    }
    else if (GetFrequency(n->valueFrequency) < GetFrequency(l->start->valueFrequency))
    {
        n->next = l->start;
        l->start = n;
    }
    else
    {        
        Node *foo = l->start->next;        
        Node *bar = l->start;        
        while (foo && GetFrequency(foo->valueFrequency) <= GetFrequency(n->valueFrequency))
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
        printf("%c, %d", GetValue(foo->valueFrequency), GetFrequency(foo->valueFrequency));
        printf("]\n");
        foo = foo->next;
    }    
}