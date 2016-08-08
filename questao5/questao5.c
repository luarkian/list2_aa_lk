#include <stdio.h>
#include <stdlib.h>

#include "questao5.h"

void inserList(List *L,int valor,	int chave)
{
	List* no =(List*)malloc(sizeof(List));
	if(L == NULL)
	{
		no->val= valor;
		no->prox= NULL;
		no->chave= chave;	

		L = no;
	}
	else
	{
		no->val = valor;
		no->chave= chave;
		L->prox = no;	
	}	
}

void remocList(List *L,int valor)
{
	List* aux;
	List* aux1;			
	if(L->val == valor)
		return L->prox;
	else
	{
		aux = L;
		aux1= L->prox;
		
		while(aux1 != NULL)
		{
			if(aux1->val == valor)
			{
				aux->prox = aux1->prox;
				free(aux1);
				return L; 			
			}
			else
			{
				aux = aux1;
				aux1= aux->prox;
			}
		}	
	}
}

List* busca(List *L, int valor)
{
	List* aux;
	for(aux = L; aux != NULL; aux = L->prox)
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
	for(aux = L; aux != NULL; aux = L->prox)
	{
		printf(" %d -",aux->val);
	}
}


/*
	Arvore Rubro Negra
	Disponivel em https://www.youtube.com/playlist?list=PL8iN9FQ7_jt6XjYc0H01AVJoCePsiSNEq
*/

int cor(Arv *arv)
{
	if(arv == NULL)
	{
		return BLACK;
	}
	else
		return arv->cor;

} 

void trocarCor(Arv *arv)
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
Arv* rDir(Arv *arv)
{
	Arv* aux = arv->dir;
	arv->esq = aux->dir;
	aux->dir = arv;
	
	aux->cor = arv->cor;
	arv->cor = RED;
	
	return aux;
}

//Rotacao esq
Arv* rEsq(Arv *arv)
{
	Arv* aux = arv->dir;
	arv->dir = aux->esq;
	aux->esq = arv;
	
	aux->cor = arv->cor;
	arv->cor = RED;
	
	return aux;
}

Arv* moveEsqRed(Arv* arv)
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

Arv* moveDirRed(Arv* arv)
{
	trocarCor(arv);
	if(cor(arv->esq->esq) == RED)
	{
		arv = rDir(arv);
		trocaCor(arv);
	}
	return arv;
}

int inserir(Arv* raiz, int valor, int chave)
{
	int resp;
	raiz = auxInsere(raiz, valor,&resp,&chave);
	if(raiz == NULL)
	{
		raiz->cor= BLACK;
	}
	return resp;
}

Arv* auxInsere(Arv* no, int valor,int* resp, int *chave)
{
	if(no == NULL)
	{
		Arv* novo = (Arv*) malloc(sizeof(Arv));
		if(novo == NULL)
		{
			*resp = 0;
			return NULL;
		}
		novo->val = valor;
		novo->chave = *chave;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->cor = RED;
		*resp = 1;
		return novo;
	}
	if(valor == no->val)
	{
		*resp = 0;	
	}
	else
	{
		if(valor > no->val)
		{
			no->dir = auxInsere(no->dir,valor,resp, chave);
		}
		else
		{
			no->esq = auxInsere(no->esq,valor,resp, chave);
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
		h->no = (hashList*) malloc(TB_SIZE * sizeof(hashList)); 
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
		h->no = (hashArv*) malloc(TB_SIZE * sizeof(hashArv)); 
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

int chaveDiv(int chave, int TB_SIZE)
{
	return (chave & 0x7FFFFFFF % TB_SIZE);
}

int insereHashList(hashList* H, List* L)
{
	if(H ==NULL || H->qt == H->TB_SIZE)
		return 0;
	
}

int insereHashArv(hashArv* H, Arv* A)
{

}

