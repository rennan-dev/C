#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
}no;

void inserir(no **fila, int num) {
    no *aux, *novo = malloc(sizeof(no));
    if(novo) {
        novo->valor = num;
        novo->prox = NULL;
        if(*fila==NULL) {
            *fila = novo; //primeira inserção
        }else {
            aux = *fila;
            while(aux->prox) {
                aux=aux->prox;
            }
            aux->prox = novo; //segunda e adiante inserção
        }
    }else {
        printf("\nErro ao alocar memoria.\n");
    }
}

no* remover(no **fila) {
    no *remove = NULL;

    if(*fila) {
        remove = *fila;
        *fila = remove->prox;
    }else {

        printf("\nFila vazia.\n");
    }
    return remove;
}

void imprimir(no *fila) {
    printf("\n----------------------------------\n");
    while(fila) {
        printf("%i ", fila->valor);
        fila = fila->prox;
    }
    printf("\n----------------------------------\n");
}

int main() {

    no *r, *fila = NULL;
    int opcao, valor;

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
            inserir(&fila,valor);
            break;

        case 2:
            r = remover(&fila);
            if(r) {
                printf("\nNumeero removido: %i\n", r->valor);
                free(r);
            }
            break;
        
        case 3:
            imprimir(fila);
        
        default: printf("\nEscolha uma opcao adequada.\n");
            break;
        }

    }while(opcao!=4);

    return 0;
}