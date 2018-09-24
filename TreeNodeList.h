#include "TreeNode.h"

typedef unsigned char byte;
typedef struct list TreeNodeList;

TreeNodeList * TreeNodeListFactory();
void TreeNodeListDestroyer(TreeNodeList * l);
int Length(TreeNodeList * l);
int IsEmpty(TreeNodeList * l);
void PrintList(TreeNodeList * l);
void InsertNode(byte value, unsigned int frequency, TreeNodeList * l);