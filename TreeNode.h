typedef unsigned char byte;
typedef struct treeNode TreeNode;

TreeNode * TreeNodeFactory(byte value, int frequency);
void TreeNodeDestroyer(TreeNode * tn);
int GetFrequency(TreeNode * tn);
byte GetValue(TreeNode * tn);