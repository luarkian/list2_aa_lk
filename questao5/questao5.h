
// lista 
typedef struct list 
{
	int val;	
	List *ant;
	List *prox;
}List;

// Arvore RB
#define BLACK 0
#define RED 1

typedef struct No{
	int val;
	int cor;
	struct no *dir;
	struct no *esq;
}Arn;


// estrutura de tabela hash com arvore rubro negra
typedef struct hash_arv
{
	int qt, TB_SIZE.
	Arn **no;
}hashArv;

// estrutura de tabela hash com lista
typedef struct hash_list
{
	int qt, TB_SIZE.
	List **no;
}hashList;


List* inserList(List *L,int valor);

void remocList(List *L,int valor);

List* busca(List *L, int valor);

void imprList(List *L, int valor);

int cor(Arn *arv);

void trocarCor(Arn *arv);

Arn* rDir(Arn *arv);

Arn* rEsq(Arn *arv);

Arn* moveEsqRed(Arn* arv);

Arn* moveDirRed(Arn* arv);

int inserir(Arn* raiz, int valor)

Arn* auxInsere(Arn* no, int valor,int* resp);


