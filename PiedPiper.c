#include <stdio.h>
#include "List.h"

void getByteFrequency(FILE *fileToCompress, unsigned int *listaBytes)
{
    byte c;
    while (fread(&c, 1, 1, fileToCompress) >= 1)
      listaBytes[(byte)c]++;
    rewind(fileToCompress);
}

void main(){
  unsigned frequencyList[256] = {0};
  List * listaTeste = create();
  printf("Pied Piper\n");
  FILE *fileToCompress = fopen("text.txt", "rb");
  if(!fileToCompress){
    printf("Erro ao abrir o arquivo!");
    return;
  }
  getByteFrequency(fileToCompress, frequencyList);  
  for (int i = 0; i < 256; i++)
  {
      if (frequencyList[i])
          insertNode(i, frequencyList[i], listaTeste);
  }
  printList(listaTeste);
}