#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
}no;

typedef struct fila{
    no *prim;
    no *fim;
    int tam;
}fila;

void inicializa(fila *ptr) {
    ptr->prim = NULL;
    ptr->fim = NULL;
    ptr->tam = 0;
}

void inserir(fila *ptr, int num) {
    no *aux, *novo = malloc(sizeof(no));
    if(novo) {
        novo->valor = num;
        novo->prox = NULL;
        if(ptr->prim==NULL) {
            ptr->prim = novo; //primeira inserção
            ptr->fim = novo;

        }else {
            
            ptr->fim->prox = novo;
            ptr->fim = novo;
        }
        ptr->tam++;
    }else {
        printf("\nErro ao alocar memoria.\n");
    }
}

no* remover(fila *ptr) {
    no *remove = NULL;

    if(ptr->prim) {
        remove = ptr->prim;
        ptr->prim = remove->prox;
        ptr->tam--;
    }else {

        printf("\nFila vazia.\n");
    }
    return remove;
}

void imprimir(fila *ptr) {
    no *aux = ptr->prim;

    printf("\n----------------------------------\n");
    while(aux) {
        printf("%i ", aux->valor);
        aux = aux->prox;
    }
    printf("\n----------------------------------\n");
}

int main() {

    no *r;
    fila f1;
    int opcao, valor;

    inicializa(&f1);

    do{
        printf("\nEscolha uma opcao:");
        printf("\nInserir [1]");
        printf("\nRemover [2]");
        printf("\nImprimir [3]");
        printf("\nSair [4]\nR: ");
        scanf("%i", &opcao);

        switch(opcao) {

        case 1: 
            printf("\nDigite um valor: ");
            scanf("%i", &valor);
            inserir(&f1,valor);
            break;

        case 2:
            r = remover(&f1);
            if(r) {
                printf("\nNumeero removido: %i\n", r->valor);
                free(r);
            }
            break;
        
        case 3:
            imprimir(&f1);
        
        default: printf("\nEscolha uma opcao adequada.\n");
            break;
        }

    }while(opcao!=4);

    return 0;
}