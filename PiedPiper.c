#include <stdio.h>
#include "List.h"

void getByteFrequency(FILE *fileToCompress, unsigned int *listaBytes)
{
    byte c;
    while (fread(&c, 1, 1, fileToCompress) >= 1)
      listaBytes[(byte)c]++;
}

List * createFrequencyList(FILE *fileToCompress)
{
  unsigned frequencyList[256] = {0};
  List * byteFrequencyList = create();
  getByteFrequency(fileToCompress, frequencyList);  
  for (int i = 0; i < 256; i++)
  {
      if (frequencyList[i])
          insertNode(i, frequencyList[i], byteFrequencyList);
  }
  return byteFrequencyList;
}

void main(){
  printf("Pied Piper\n");

  FILE *fileToCompress = fopen("text.txt", "rb");
  if(!fileToCompress){
    printf("Erro ao abrir o arquivo!");
    return;
  }
  
  List * byteFrequencyList = createFrequencyList(fileToCompress);  
  
  printList(byteFrequencyList);
}