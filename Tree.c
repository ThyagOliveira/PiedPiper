#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "TreeNode.h"
#include "TreeNodeList.h"

typedef unsigned char byte;
typedef struct tree Tree;
struct tree {
	TreeNode * root;
};

Tree * TreeFactory() {
	Tree * t = (Tree *) malloc(sizeof(Tree));
	t->root = NULL;
	return t;
}

Tree * TreeFactory(List * list) {
	Tree * t = (Tree *) malloc(sizeof(Tree));
	t->root = NULL;
	return t;
}

void TreeDesotryer(Tree * t) {
	TreeNodeDestroyer(t->root);
	free(t);
}
