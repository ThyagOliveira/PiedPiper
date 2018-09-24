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

TreeNodeList * TreeNodeListFactory() {
	TreeNodeList * l = (TreeNodeList *)malloc(sizeof(TreeNodeList));
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

void clear(TreeNodeList * l) {
	Node * aux = l->start;
	while (aux != NULL) {
		Node * aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
	l->start = NULL;
	l->length = 0;
}

void TreeNodeListDestroyer(TreeNodeList * l) {
	if (l != NULL) {
		clear(l);
		free(l);
	}
}

int Length(TreeNodeList * l) {
	return l->length;
}

int IsEmpty(TreeNodeList * l) {
	return Length(l) == 0;
}

void InsertNode(byte value, unsigned int frequency, TreeNodeList *l)
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

void PrintList(TreeNodeList * l)
{
    Node * foo = l->start;    
    printf("[\n");
    while (foo != NULL)
    {        
        printf("(%c, %d),\n", GetValue(foo->treeNode), GetFrequency(foo->treeNode));        
        foo = foo->next;
    }   
    printf("]\n"); 
}