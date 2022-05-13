#include "lista.h"

int main(){

	Lista l, ldna;
	Item aux;
    char auxWhile[1];
    char cAux[3];
    FILE *file;
    Block *AuxBlock;
    Block *AuxBlock2;
    Block *ComecoCadeia;
    Block *ComecoCadeiaAux;
    Block *FinalCadeia;
    Block *FinalCadeiaAux;
    int numNucle,auxNucle,numEnt;

    FLVazia(&l);
    FLVazia(&ldna);

    printf("Programa feito para achar a maior cadeia de DNA dentro de uma cadeia maior.\n");
    printf("Esta cadeia maior precisa estar dentro de um arquivo chamado dna.txt na mesma pasta que o seu makefile\n");
    printf("Já a outra entrada fica a sua preferência.\nVocê prefere colocar os nucleotideos a mão, ou ler de um arquivo input.txt?\n");
    printf("0 - Ler do arquivo input.txt\n");
    printf("1 - Escrever eles a mão.\n");
    scanf("%1s", auxWhile);

    numEnt = 0;
    if(strcmp(auxWhile,"1")==0){

        printf("Ok. Lembre-se que um Nucleotídeo é formado de 3 bases formadas por A, C, G e T. Exemplo: ACG\n");

        do{    
            printf("\nQual o nucleotídeo que deseja adicionar?\n");
            scanf("%3s", cAux);
            strcpy(aux.codon, cAux);
            LInsert(&l, aux);
            printf("Nucleotídeo adicionado!\n\n");
            numEnt++;

            printf("Deseja adicionar outro nucleotídeo?(s/n)\n");
            scanf("%1s", auxWhile);

        } while (strcmp(auxWhile,"s")==0 || strcmp(auxWhile,"S")==0);

    }
    else{
        printf("Abrindo input.txt para vermos qual entrada você quer ler\n");
        file = fopen("input.txt", "r");
        if (file == NULL){   
            printf("Arquivo não encontrado!\n"); 
        }
        else{
            while( fscanf(file, "%3s", cAux) == 1){
                strcpy(aux.codon, cAux);
                LInsert(&l,aux);
                numEnt++;
            }
        }
    }

    printf("\nOk! Você colocou a seguinte cadeia para ser testada:\n");    
    LImprime(&l);

    printf("\nProcurando e lendo arquivo agora...\n"); 
    file = fopen("dna.txt", "r");

    if (file == NULL){   
        printf("Arquivo não encontrado!\n"); 
    }
    else{
        while( fscanf(file, "%3s", cAux) == 1){
            strcpy(aux.codon, cAux);
            LInsert(&ldna,aux);
        }
    }
    
    fclose(file);

    printf("Ok! Lemos o arquivo dna.txt, e essa é a cadeia que lemos:\n");    
    LImprime(&ldna);

    ComecoCadeia = NULL;
    FinalCadeia = NULL;
    ComecoCadeiaAux = NULL;
    FinalCadeiaAux = NULL;
    numNucle = 0;

    for (AuxBlock = ldna.first->prox; AuxBlock != NULL; AuxBlock = AuxBlock->prox){
    	for (AuxBlock2 = l.first->prox; AuxBlock2 != NULL; AuxBlock2 = AuxBlock2 -> prox){
		if (strcmp(AuxBlock->data.codon,AuxBlock2->data.codon) == 0){
		    	ComecoCadeiaAux = AuxBlock;
		    	auxNucle = 1;
		    	if(AuxBlock->prox != NULL && AuxBlock2->prox != NULL){
				auxNucle = LSomarRestante(AuxBlock->prox,AuxBlock2->prox);
			}
			if (auxNucle > numNucle){
				numNucle = auxNucle;
				FinalCadeiaAux = ComecoCadeiaAux;
				if(auxNucle != 1){
					while(auxNucle > 1){
						FinalCadeiaAux = FinalCadeiaAux->prox;
						auxNucle--;
					}	
				}
				ComecoCadeia = ComecoCadeiaAux;
				FinalCadeia = FinalCadeiaAux;
			}
		}
	}
    }
    if(numNucle == 0){
        printf("A cadeia não foi encontrada em momento algum\n");
    }
    else if(numNucle == numEnt){
    	printf("A cadeia foi encontrada por completo\n");        
    	printf("Aqui o endereço do primeiro nucleotideo : %p\n", ComecoCadeia);
        printf("Aqui o endereço do ultimo nucleotideo: %p\n", FinalCadeia);
    }
    else{
        printf("A maior sequência encontrada da sua entrada foi de %d nucleotídeos\n", numNucle);
        printf("Aqui o primeiro nucleotideo da maior cadeia encontrada: %s\n", ComecoCadeia->data.codon);
        printf("Aqui o ultimo nucleotideo da maior cadeia encontrada: %s\n", FinalCadeia->data.codon);
    }
	return 0;
}