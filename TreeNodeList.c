#include <stdio.h>
#include <stdlib.h>
#include "TreeNodeList.h"

typedef struct node Node;
typedef struct list TreeNodeList;
typedef struct treeNode TreeNode;

struct list {
	int length;
	Node * start;
};
struct node {
    TreeNode * treeNode;
	Node * next;
};
struct treeNode {
	byte value;
	int frequency;
	TreeNode * left;
	TreeNode * right;
};

List * ListFactory() {
	List * l = (List *)malloc(sizeof(List));
	l->start = NULL;
	l->length = 0;
	return l;
}

Node * ListNodeFactory(byte value, int frequency) {
    TreeNode * tn = TreeNodeFactory(value, frequency);
	Node * n = (Node *)malloc(sizeof(Node));        
    n->treeNode = tn;
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

void insertNode(byte value, unsigned int frequency, List *l)
{    
    Node * n = ListNodeFactory(value, frequency);
    if (!l->start)
    {
        l->start= n;
    }
    else if (GetFrequency(n->treeNode) < GetFrequency(l->start->treeNode))
    {
        n->next = l->start;
        l->start = n;
    }
    else
    {        
        Node *foo = l->start->next;        
        Node *bar = l->start;        
        while (foo && GetFrequency(foo->treeNode) <= GetFrequency(n->treeNode))
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
        printf("%c, %d", GetValue(foo->treeNode), GetFrequency(foo->treeNode));
        printf("]\n");
        foo = foo->next;
    }    
}