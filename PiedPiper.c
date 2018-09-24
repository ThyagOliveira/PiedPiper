#include <stdio.h>
#include <locale.h>
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


void main() {
	
  setlocale(LC_ALL, "");
  title();
  		
  menu();
  printf("Pied Piper\n");

  FILE *fileToCompress = fopen("text.txt", "rb");
  if(!fileToCompress){
    printf("Erro ao abrir o arquivo!");
    return;
  }
  
  List * byteFrequencyList = createFrequencyList(fileToCompress);  
  
  printList(byteFrequencyList);
}
void clean_screen() {
	system("cls");
}

void credits() {
	printf("\n\n\n\n\tAlgoritmo de Huffman desenvolvido em C.\n\tPor Thyago Oliveira e Ryan Filho");
	printf("\n\n-------------------------------------------------------------------------------\t");
	printf("\n\tAperte qualquer tecla para voltar ao menu");
}
void instructions() {
	 printf("Uso: huffman [OPCAO] [ARQUIVO] [ARQUIVO]\n\n");
    printf("Opções:\n");
    printf("\t-c\tCompactar\n");
    printf("\t-x\tDescompactar\n");
    printf("\nExemplo: ./huffman -c teste.txt teste.ed2\n");
    printf("\n\n-------------------------------------------------------------------------------\t");
	printf("\n\tAperte qualquer tecla para voltar ao menu");
}
void menu() {
	char choice;
	
	printf("\n\n\t\tPied Piper");
	printf("\n\n\t\t01. Instruções");
	printf("\n\t\t02. Créditos");
	printf("\n\t\t03. Sair");
	printf("\n\n\t\tEscolha a opção: ");
	scanf("%s", &choice);
	
	switch(choice) {
		case '1':
			clean_screen();
			instructions();
			getch();
			clean_screen();
			return menu();
			break;
		case '2':
			clean_screen();
			credits();
			getch();
			clean_screen();
			return menu();
			break;
		case '3':
			exit(0);
			break;
		
		default:
			clean_screen();
			return menu();
			break;
	}
	
}

void title() {

	system("title Pied Piper");
	printf("\n\n\t\t\t Projeto de Estrutura de Dados II");
	printf("\n\t\t\t    Kappa Produções Apresenta");
	printf("\n\t\t\t\t Pied Piper");

	printf("\n\n-------------------------------------------------------------------------------\t");
}

