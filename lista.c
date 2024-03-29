#include <stdio.h>
#include <stdlib.h>

//definindo a lista 

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No * inicio;
    int tam; 
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

//metodo pra inserir no inicio
void inserir_inicio(Lista * lista, int num){
    No *novo =(No*)malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else 
        printf("erro ao alocar!\n");
}
void inserir_fim(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        //é o primeiro
        if(lista->inicio == NULL){
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else 
        printf("erro ao alocar!\n");
}

void inserir_no_meio(Lista *lista, int num,int  anterior){
    No *aux,*novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        //é o primeiro ? 
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->valor != anterior && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo; 
        
        }
        lista->tam++;
        
    }
    else printf("Erro ao alocar memoria!!!");
}

void imprimindo_lista(Lista lista){
    No *no = lista.inicio;
    printf("\nLista tem: %d elemetnos\n ",lista.tam);
    while(no){
        printf("%d ",no->valor);
        no = no->proximo;

    }   
    printf("\n\n");
}
//lista so com nos
void inserirOrdenado(No **lista, int num){
    No *aux,*novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        // A lista está vazia
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        //é  o menor ?
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
}
void imprimindoLista(No *lista){

    printf("\nLista: ");
    while(lista){
        printf("%d ",lista->valor);
        lista = lista->proximo;

    }   
    printf("\n\n");
}

void inserindo_ordenado(Lista * lista, int num){
    No * novo, *aux = (No*)malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
           
        }
        else if(novo->valor > lista->inicio->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
            
        }else{
            aux = lista->inicio;
            if(aux->proximo && aux->proximo->valor < novo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;

        }
    }
     lista->tam++;
}
No * remover (Lista *lista, int num){
    No *remover,*aux = NULL;
    if(lista->inicio){
        if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }

    return remover;
}
int main(){
    
    int opc,valor, aux;
     No *lista1 = NULL;
    Lista  lista;
     ;
    criar_lista(&lista);

    do{
        printf("\n\t 0 - sair\n\t 1 - InserirI \n\t 2 - INSERIRF\n\t 3 - INSERIRM\n\t 4 - Imprimir\n\t 5 - Inserir ordenado\n\n");
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
            //imprimindoLista(lista1);
            imprimindo_lista(lista);
            break; 
        case 5:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserindo_ordenado(&lista, valor);
            
            break;   
        default:
            if(opc != 0)
                printf("opcao invalida!\n");
            break;
        }

    }while(opc!=0);

    
    return 0;
}