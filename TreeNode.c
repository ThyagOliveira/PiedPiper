#include <stdlib.h>
#include "TreeNode.h"

typedef struct treeNode TreeNode;

struct treeNode {
	byte value;
	int frequency;
	TreeNode * left;
	TreeNode * right;
};

TreeNode * TreeNodeFactory(byte value, int frequency) {
	TreeNode * tn = (TreeNode *) malloc(sizeof(TreeNode));        
    tn->value = value;
		tn->frequency = frequency;
		tn->left = NULL;
		tn->right = NULL;
	return tn;
}

void TreeNodeDestroyer(TreeNode * tn) {
	if (tn != NULL) {
		TreeNodeDestroyer(tn->left);
		TreeNodeDestroyer(tn->right);
		free(tn);
	}
}

byte GetValue(TreeNode * tn){
	return tn->value;
}

int GetFrequency(TreeNode * tn){
	return tn->frequency;
}