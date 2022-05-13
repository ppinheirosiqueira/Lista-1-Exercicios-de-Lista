#include "lista.h"
#include<time.h>

int main(){
	Lista l;
	Item aux;
    int n;
    int ValMax;
    int MaiorSoma;
    int AuxSoma;
    Block *ComecoSoma;
    Block *FinalSoma;
    Block *AuxBlock;
    Block *AuxComeco;
    Block *AuxFinal;

	FLVazia(&l);

    printf("Digite a dimenção do vetor de inteiros que você deseja: \n");
	scanf("%d", &n);

    printf("Digite o valor máximo (módulo) que você deseja para os inteiros deste vetor: \n");
	scanf("%d", &ValMax);

    srand(time(0));

    for (int i = 0; i < n; i++){
        aux.val = rand() % (2*ValMax + 1) - ValMax;
        //aux.val = 1-2*i;
        LInsert(&l, aux);
    }

    // No começo a maior soma é a soma de todos
    ComecoSoma = l.first->prox;
    FinalSoma = l.last;
    MaiorSoma = LSoma(ComecoSoma, FinalSoma);

    for (AuxComeco = l.first->prox; AuxComeco != NULL; AuxComeco = AuxComeco->prox){
        for(AuxFinal = AuxComeco; AuxFinal != NULL; AuxFinal = AuxFinal->prox){
            AuxSoma = 0;
            AuxBlock = AuxComeco;
            while(AuxBlock != AuxFinal){
                AuxSoma += AuxBlock->data.val;
                AuxBlock = AuxBlock->prox;
            }
            AuxSoma += AuxBlock->data.val;
            if (AuxSoma > MaiorSoma){
                MaiorSoma = AuxSoma;
                ComecoSoma = AuxComeco;
                FinalSoma = AuxFinal;
            }
        }
    }

    printf("\n");
    printf("O seu vetor é: \n");
    LImprime(&l);
	printf("\n");
    printf("A maior soma possível do vetor é: %d\n", MaiorSoma);
    printf("Esse valor é conseguido somando-se os valores entre os indices: %d e %d\n", ComecoSoma->data.val, FinalSoma->data.val);
    
	return 0;
}