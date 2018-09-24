typedef unsigned char byte;
typedef struct list List;

List * create();
void destroy(List * l);
void clear(List * l);
int length(List * l);
int is_empty(List * l);
void printList(List * l);
void insertNode(byte value, unsigned int frequency, List * l);