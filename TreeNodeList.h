#include "TreeNode.h"

typedef unsigned char byte;
typedef struct list List;

List * ListFactory();
void ListDestroyer(List * l);
int length(List * l);
int is_empty(List * l);
void printList(List * l);
void insertNode(byte value, unsigned int frequency, List * l);