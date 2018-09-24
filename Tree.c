#include "Tree.h"

typedef unsigned char byte;
typedef struct tree Tree;
typedef struct treeNode TreeNode;
struct treeNode {
	byte value;
	int frequency;
	TreeNode * left;
	TreeNode * right;
};
struct tree {
	TreeNode * root;
};

Tree * TreeFactory() {
	Tree * t = (Tree *) malloc(sizeof(Tree));
	t->root = NULL;
	return t;
}

void TreeDesotryerRecursive(TreeNode * n) {
	if (n != NULL) {
		destroyTree_rec(n->left);
		destroyTree_rec(n->right);
		free(n);
	}
}

void TreeDesotryer(Tree * t) {
	destroyTree_rec(t->root);
	free(t);
}
