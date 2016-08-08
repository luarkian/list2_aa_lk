
// lista 
typedef struct list 
{
	int chave;		
	int val;	
	struct list *prox;
}List;

// Arvore RB
#define BLACK 0
#define RED 1

typedef struct no{
	int chave;	
	int val;
	int cor;
	struct no *dir;
	struct no *esq;
}Arv;


// estrutura de tabela hash com arvore rubro negra
typedef struct hash_arv
{
	int qt, TB_SIZE;
	Arv **no;
}hashArv;

// estrutura de tabela hash com lista
typedef struct hash_list
{
	int qt, TB_SIZE;
	List **no;
}hashList;


void inserList(List *L,int valor);

void remocList(List *L,int valor);

List* busca(List *L, int valor);

void imprList(List *L, int valor);

int cor(Arv *arv);

void trocarCor(Arv *arv);

Arv* rDir(Arv *arv);

Arv* rEsq(Arv *arv);

Arv* moveEsqRed(Arv* arv);

Arv* moveDirRed(Arv* arv);

int inserir(Arv* raiz, int valor);

Arv* auxInsere(Arv* no, int valor,int* resp, int* chave);

hashArv* criarHashArv(int TB_SIZE);

hashList* criarHashList(int TB_SIZE);

int insereHashList(hashList* H, List* L);

int insereHashArv(hashArv* H, Arv* A);

int chaveDiv(int chave, int TB_SIZE);
