#include "lista.h"
#include <string.h>
#include <ctype.h>

int main(){

	Lista l;
	Item aux;
    FILE *file;
    char c[50];
    int auxWhile;
    int auxNomes;
    int auxRemovidos = 0;

	FLVazia(&l);
    
    file = fopen("nome.txt", "r");

    if (file == NULL){   
        printf("Arquivo não encontrado!\n"); 
    }
    else{
        while( fscanf(file, "%s", c) == 1){
            strcpy(aux.nome, c);
            LInsert(&l,aux);
        }
    }

    fclose(file);
    
    printf("Lista Completa:\n");
    LImprime(&l);

    for(int i = 0; i< l.last - 1; i++){
        for(int j = i+1; j < l.last; j++){
            if(strcmp(l.vet[i].nome,l.vet[j].nome) == 0){
                strcpy(l.vet[j].nome, "\0");
                auxRemovidos++;
            }
        }
    }

    printf("Lista sem nome repetido:\n");
	LImprime(&l);

    do{
        printf("\nO que você deseja fazer agora?\n");
        printf("1 - Ver a lista\n");
        printf("2 - Inserir um nome na lista\n");
        printf("3 - Remover um nome da lista\n");
        printf("0 - Sair do programa\n");
        
        scanf("%d", &auxWhile);

        if (auxWhile == 1){
            printf("\nLista Atual:\n");
            LImprime(&l);
        }
        else if(auxWhile == 2){
            printf("\nDigite o nome que deseja inserir: ");
            scanf("%49s", c);

            auxNomes = 0;

            for(int i = 0; i<l.last - 1; i++){
                if(strcmp(l.vet[i].nome,c) == 0){
                    auxNomes = 1;
                    i = l.last;
                }
            }
            
            if(auxNomes == 0){
                if(auxRemovidos != 0){
                    for(int i = 0; i<= l.last - 1; i++){
                        if(strcmp(l.vet[i].nome,"\0") == 0){
                            strcpy(l.vet[i].nome, c);
                            i = l.last;
                            auxNomes = 1;
                            auxRemovidos--;       
                        }
                    }
                }
                else{
                    strcpy(aux.nome, c);
                    LInsert(&l,aux);
                }
                printf("Nome adicionado com sucesso!\n");
            }
            else{
                printf("Nome já existe na lista!\n");
            }
        }
        else if(auxWhile == 3){
            printf("\nDigite o nome que deseja excluir: ");
            scanf("%49s", c);
            auxNomes = 0;                
            for(int i = 0; i<l.last; i++){

                if(strcmp(l.vet[i].nome,c) == 0){
                    strcpy(l.vet[i].nome, "\0");
                    auxNomes = 1;
                    auxRemovidos++;
                    i = l.last + 1;
                }
            }

            if (auxNomes == 1){
                printf("Nome excluido com sucesso!\n");
            }
            else{
                printf("Nome não encontrado!\n");
            }

        }

    } while (auxWhile != 0);
    
	return 0;
}