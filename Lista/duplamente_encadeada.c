#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ante;
}no;

void inserir_no_inicio(no **lista, int num) {
    no *novo = malloc(sizeof(no));

    if(novo) {
        novo->valor = num;
        novo->prox = *lista;
        novo->ante = NULL;
        if(*lista) {
            (*lista)->ante = novo;
        }
        *lista = novo;
    }else {
        printf("\nErro ao alocar memoria.\n");
    }
}

void inserir_no_fim(no **lista, int num) {
    no *aux, *novo = malloc(sizeof(no));

    if(novo) {
        novo->valor = num;
        novo->prox = NULL;

        //é o primeiro?
        if(*lista == NULL) {
            *lista = novo;
            novo->ante = NULL;
        }else {
            aux = *lista;
            while(aux->prox) {
                aux = aux->prox;
            }
            aux->prox = novo;
            novo->ante = aux;
        }
    }else {
        printf("\nErro ao alocar memoria.\n");
    }
}

void inserir_no_meio(no **lista, int num, int ant) {
    no *aux, *novo = malloc(sizeof(no));

    if(novo) {
        novo->valor = num;

        if(*lista == NULL) {
            novo->prox = NULL;
            novo->ante = NULL;
            *lista = novo;
        }else {
            aux = *lista;
            while(aux->valor != ant && aux->prox) {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            if(aux->prox) {
                aux->prox->ante = novo;
            }
            novo->ante = aux;
            aux->prox = novo;
        }
    }else {
        printf("\nErro ao alocar memoria.\n");
    }
}

void inserir_ordenado(no **lista, int num) {
    no *aux, *novo = malloc(sizeof(no));

    if(novo) {
        novo->valor = num;
        //a lista está vazia?
        if(*lista == NULL) {
            novo->prox = NULL;
            novo->ante = NULL;
            *lista = novo;
        }
        //é o menor?
        else if(novo->valor < (*lista)->valor) {
            novo->prox = *lista;
            (*lista)->ante = novo;
            *lista = novo;
        }else {
            aux = *lista;
            while(aux->prox && novo->valor > aux->prox->valor) {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            if(aux->prox) {
                aux->prox->ante = novo;
            }
            novo->ante = aux;
            aux->prox = novo;
        }
    }else {
        printf("\nErro na alocacao de memoria.\n");
    }
}

no* remover(no **lista, int num) {
    no *aux, *remover = NULL;

    if(*lista) {
        if((*lista)->valor == num) {
            remover = *lista;
            *lista = remover->prox;
            if(*lista) {
                (*lista)->ante = NULL;
            }
        }else {
            aux = *lista;
            while(aux->prox && aux->prox->valor != num) {
                aux = aux->prox;
            }
            if(aux->prox) {
                remover = aux->prox;
                aux->prox = remover->prox;
                if(aux->prox) {
                    aux->prox->ante = aux;
                }
            }
        }
    }
    return remover;
}

no *buscar(no **lista, int num) {
    no *aux, *procura = NULL;

    aux = *lista;
    while(aux && aux->valor != num) {
        aux = aux->prox;
    }
    if(aux) {
        procura = aux;
    }
    return procura;
}

void imprimir(no *no) {
    printf("\nLista: ");
    while(no) {
        printf("%i ", no->valor);
        no = no->prox;
    }
    printf("\n\n");
}

no* ultimo_no(no **lista) {
    if(*lista == NULL) {
        return NULL;
    }

    no *aux = *lista;
    while(aux->prox) {
        aux = aux->prox;
    }
    return aux;
}

void imprimir_da_ultima_posicao(no *no) {
    printf("\nLista: ");
    while(no) {
        printf("%i ", no->valor);
        no = no->ante;
    }
    printf("\n\n");
}

int main() {

    int opcao, valor, anterior;
    no *removido, *lista = NULL;

    do{
        printf("\n\t0 - sair\n\t1 - inserir inicio\n\t2 - inserir final");
        printf("\n\t3 - inserir meio\n\t4 - inserir ordenado\n\t5 - remover");
        printf("\n\t6 - imprimir\n\t7 - imprimir final\n\t8 - buscar\n\n\tResposta: ");
        scanf("%i", &opcao);

        switch(opcao) {

            case 0:
                printf("\nEncerrando aplicacao.\n");
                break;

            case 1:
                printf("\ndigite um valor: ");
                scanf("%i", &valor);
                inserir_no_inicio(&lista, valor);
                break;

            case 2:
                printf("\ndigite um valor: ");
                scanf("%i", &valor);
                inserir_no_fim(&lista, valor);
                break;

            case 3:
                printf("\ndigite um valor e o valor de referencia: ");
                scanf("%i%i", &valor, &anterior);
                inserir_no_meio(&lista, valor, anterior);
                break;
            
            case 4:
                printf("\ndigite um valor: ");
                scanf("%i", &valor);
                inserir_ordenado(&lista, valor);
                break;

            case 5:
                printf("Digite um valor a ser removido: ");
                scanf("%i", &valor);
                removido = remover(&lista, valor);
                if(removido) {
                    printf("\nElemento removido com sucesso.\n");
                    free(removido);
                }else {
                    printf("\nElemento inesistente.\n");
                }
                break;

            case 6:
                imprimir(lista);
                break;

            case 7:
                imprimir_da_ultima_posicao(ultimo_no(&lista));
                break;
            
            case 8:
                printf("\nDigite um valor a ser buscado: ");
                scanf("%i", &valor);
                removido = buscar(&lista,valor);
                if(removido) {
                    printf("\nElemento encontrado: %i\n", removido->valor);
                }else {
                    printf("\nElemento nao encontrado.\n");
                }
                break;

            default:
                printf("\nEscolha uma opcao valida.\n");
                break;
        }
    }while(opcao!=0);

    return 0;
}