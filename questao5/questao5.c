#include <stdio.h>
#include <stdlib.h>

#include "questao5.h"

List* inserList(List *L,int valor)
{
	List* no =(List*)malloc(sizeof(List));
	if(L == NULL)
	{
		no->val= valor;
		no->ant= NULL;
		no->prox= NULL;	

		return no;
	}
	else
	{
		no->val = valor;
		no->ant = NULL;
		no->prox = L;
		L->ant = no;
	return no;	
	}	
}

void remocList(List *L,int valor)
{
	List* aux;
	List* aux1;
	List* aux2;
	for(aux = L; aux != NULL; aux->L->prox)
	{
		if(aux->val == valor)
		{
				aux1= aux->ant;
				aux2= aux->prox;
				
				aux1->prox = aux2;
				aux2->ant = aux1;
				
				free(aux);	
		}
}

List* busca(List *L, int valor)
{
	List* aux;
	for(aux = L; aux != NULL; aux->L->prox)
	{
		if(aux->val == valor)
		{
			return aux;		
		}
	} 
}
void imprList(List *L, int valor)
{
	List* aux;
	for(aux = L; aux != NULL; aux->L->prox)
	{
		printf(" %d -",aux->val);
	}
}


/*
	Arvore Rubro Negra
	Disponivel em https://www.youtube.com/playlist?list=PL8iN9FQ7_jt6XjYc0H01AVJoCePsiSNEq
*/

int cor(Arn *arv)
{
	if(arv == NULL)
	{
		return BLACK;
	}
	else
		return arv->cor;

} 

void trocarCor(Arn *arv)
{
	arv->cor = !arv->cor;
	if(arv->esq != NULL)
	{
		arv->esq->cor = !arv->esq->cor;
	}
	else
	{
		arv->dir->cor = !arv->dir->cor;
	}
}

//Rotacao dir
Arn* rDir(Arn *arv)
{
	Arn* aux = arv->dir;
	arv->esq = aux->dir;
	aux->dir = arv;
	
	aux->cor = arv->cor;
	arv->cor = RED;
	
	return aux;
}

//Rotacao esq
Arn* rEsq(Arn *arv)
{
	Arn* aux = arv->dir;
	arv->dir = aux->esq;
	aux->esq = arv;
	
	aux->cor = arv->cor;
	arv->cor = RED;
	
	return aux;
}

Arn* moveEsqRed(Arn* arv)
{
	trocarCor(arv);
	if(cor(arv->dir->esq) == RED)
	{
		arv->dir = rDir(arv->dir);
		arv = rEsq(arv);
		trocarCor(arv);
	}
	return arv;
}

Arn* moveDirRed(Arn* arv)
{
	trocarCor(arv);
	if(cor(arv->esq->esq) == RED)
	{
		H = rDir(arv);
		trocaCor(arv);
	}
	return arv;
}

int inserir(Arn* raiz, int valor)
{
	int resp
	*raiz = auxInsere(raiz, valor,&resp);
	if((*raiz) == NULL)
	{
		(*raiz)->cor= BLACK;
	}
	return resp;
}

Arn* auxInsere(Arn* no, int valor,int* resp)
{
	if(no == NULL)
	{
		Arv* novo = (Arv*) malloc(sizeof(Arv));
		if(novo == NULL)
		{
			*resp = 0;
			return NULL;
		}
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->cor = RED;
		*resp = 1;
		return novo;
	}
	if(valor == no->valor)
	{
		*resp = 0;	
	}
	else
	{
		if(valor > no->infor)
		{
			no->dir = auxInsere(no->dir,valor,resp);
		}
		else
		{
			no->esq = auxInsere(no->esq,valor,resp);
		}
	}

	if((cor(no->dir) == RED) && (cor(no->esq) == BLACK))
	{
		no = rEsq(no);
	}
	if((cor(no->esq) == RED) && (cor(no->esq->esq) == RED))
	{
		no = rDir(no);
	}
	if((cor(no->esq) == RED) && (cor(no->dir) == RED))
	{
		trocarCor(no);
	}

	return no;
}

hashList* criarHashList(int TB_SIZE)
{
	hashList* h =(hashList*) malloc(sizeof(hashList));
	if(h != NULL)
	{
		int i;
		h->TB_SIZE = TB_SIZE;
		h->no = (hashList**) malloc(TB_SIZE * sizeof(hashList)); 
		if(h->no == NULL)
		{
			free(h);
			return NULL;
		}
		h->qt = 0;
		for(i=0;i < h->TB_SIZE; i++)
		{
			h->no[i] = NULL; 
		}
	}
	return h;
}

hashArv* criarHashArv(int TB_SIZE)
{
	hashArv* h =(hashArv*) malloc(sizeof(hashArv));
	if(h != NULL)
	{
		int i;
		h->TB_SIZE = TB_SIZE;
		h->no = (hashArv**) malloc(TB_SIZE * sizeof(hashArv)); 
		if(h->no == NULL)
		{
			free(h);
			return NULL;
		}
		h->qt = 0;
		for(i=0;i < h->TB_SIZE; i++)
		{
			h->no[i] = NULL; 
		}
	}
	return h;
}

void liberaHashArv(hashArv* h)
{
	if(h == NULL)
	{
		int i;
		for(i=0; i< h->TB_SIZE;i++)
		{
			if(h->no != NULL)
			{
				free(h->no[i]);
			}
		}
		free(h->no);
		free(h);
	}
}

void liberaHashList(hashList* h)
{
	if(h == NULL)
	{
		int i;
		for(i=0; i< h->TB_SIZE;i++)
		{
			if(h->no != NULL)
			{
				free(h->no[i]);
			}
		}
		free(h->no);
		free(h);
	}
}
