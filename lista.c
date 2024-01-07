#include <stdio.h>
#include <stdlib.h>

//definindo a lista 

typedef struct no{
    int valor;
    struct no *proximo;
}No;

//metodo pra inserir no inicio

void inserir_inicio(No ** lista, int num){
    No *novo =(No*)malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else 
        printf("erro ao alocar!\n");
}
void inserir_fim(No ** lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        //é o primeiro
        if(*lista == NULL){
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else 
        printf("erro ao alocar!\n");
}

void inserir_no_meio(No **lista, int num,int  anterior){
    No *aux,*novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        //é o primeiro ? 
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->valor != anterior && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo; 
        
        }
        
    }
    else printf("Erro ao alocar memoria!!!");
}

void imprimindo_lista(No *lista){

    printf("\nLista: ");
    while(lista){
        printf("%d ",lista->valor);
        lista = lista->proximo;

    }   
    printf("\n\n");
}
int main(){
    
    int opc,valor, aux;
    No *lista = NULL;
    do{
        printf("\n\t 0 - sair\n\t 1 - InserirI \n\t 2 - INSERIRF\n\t 3 - INSERIRM\n\t 4 - Imprimir\n\n");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d %d",&valor, &aux);
            inserir_no_meio(&lista, valor,aux);
            break;
        case 4:
            imprimindo_lista(lista);
            break;    
        default:
            if(opc != 0)
                printf("opcao invalida!\n");
            break;
        }

    }while(opc!=0);

    
    return 0;
}