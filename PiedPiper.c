#include <stdio.h>
#include "List.h"
int main(){
  printf("Pied Piper\n");
  List * l = create();
  addNode(l,1);
  printf("A lista está vazia? %d", is_empty(l));
  return 0;
}