#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "Tree.h"


typedef struct no No;

struct no {
	int frequency;
	No * left;
	No * right;
};

typedef struct arvore Arvore;

struct arvore {
	No * raiz;
};	


  //////////////////////////
 // Opera��es Gen�ricas  //
////////////////////////// 

Arvore * criar() {
	Arvore * arv = (Arvore *) malloc(sizeof(Arvore));
	arv->raiz = NULL;
	return arv;
}

void destruir_rec(No * no) {
	if (no != NULL) {
		destruir_rec(no->left);
		destruir_rec(no->right);
		free(no);
	}
}

void destruir(Arvore * arv) {
	destruir_rec(arv->raiz);
	free(arv);
}
