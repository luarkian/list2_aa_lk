#include <stdlib.h>
#include <stdio.h>
#include "questao5.h"

int main()
{
int a,b;
hashArv *HA;
hashList *HL;

	printf("Tabela hash:\n\t1 - Lista\n\t2 - Arvore Rubro Negra\n\t0 -Encerrar \n\n");
	scanf("%d",&a);
do
{
	switch(a)
	{
		case 1:
		{
			HL = criarHashList(1024);
			printf("\n\t1 - Insercao \n\t2 - Remocao\n\t3 - Busca\n\t0 -Encerrar \n\n");
			break;
		}
		case 2:
		{
			HA = criarHashArv(1024);
						
			printf("\n\t1 - Insercao \n\t2 - Remocao\n\t3 - Busca\n\t0 -Encerrar \n\n");		
			scanf("%d",&b);
			do{
				switch(b)
				{
					case 1:
					{

					}
					case 2:
					{

					}
					case 3:
					{

					}
					case 0:
					break;
				}
				
			}while(b != 0);			
			break;
		}
	}
}while(a != 0);

}
