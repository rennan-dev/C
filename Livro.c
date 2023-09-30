#include <stdio.h>
#include <stdlib.h>

typedef struct Livro {
    char nome_livro[20];
    char nome_autor[20];
    int ano;
    struct Livro *prox;
}Livro;

typedef struct pilha {
    Livro *topo;
}pilha;

void inicializa(pilha *p) {
    p->topo = NULL;
}

void empilhar(pilha *p) {

    Livro *ptr = (Livro*) malloc(sizeof(Livro));

    if(ptr==NULL) {
        printf("\nErro na alocacao de memoria.");
        return;
    }else {

        printf("\nDigite o nome do livro: ");
        scanf("%s", ptr->nome_livro);

        printf("Digite o nome do autor: ");
        scanf("%s", ptr->nome_autor);

        printf("Digite o ano de publicacao: ");
        scanf("%i", &ptr->ano);

        ptr->prox = p->topo;
        p->topo = ptr;
        printf("\nLivro Adicionado na biblioteca.\n");
    }
}

void desempilhar(pilha *p) {

    if (p->topo == NULL) {
        printf("\nPilha vazia, impossivel desempilhar.\n");
        return;
    }

    Livro *temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
    printf("\nLivro desempilhado da biblioteca.\n");
}


void printar(pilha *p) {

    printf("\n-------------------------------------");
    Livro *ptr = p->topo;
    if(ptr==NULL) {
        printf("\nNao possui livros na biblioteca.");
        printf("\n-------------------------------------");
        return;
    }else {

        while(ptr != NULL) {
            printf("\nLivro: %s", ptr->nome_livro);
            printf("\nAutor: %s", ptr->nome_autor);
            printf("\nAno: %i\n", ptr->ano);
            ptr=ptr->prox;
        }
    }
    printf("-------------------------------------\n");
}

//teste 1
void imprimir_ordem(pilha *p) {
    if (p->topo == NULL) {
        printf("\nPilha vazia, impossível imprimir.\n");
        return;
    }

    Livro *atual = p->topo;

    printf("\nElementos na ordem que foram adicionados:\n");

    while (atual != NULL) {
        printf("Nome do Livro: %s\n", atual->nome_livro);
        printf("Nome do Autor: %s\n", atual->nome_autor);
        printf("Ano de Publicacao: %d\n\n", atual->ano);

        atual = atual->prox;
    }
}

//teste 2
void imprimir_ordem_inversa(Livro *livro) {
    if (livro == NULL) {
        return;
    }

    imprimir_ordem_inversa(livro->prox);

    printf("Nome do Livro: %s\n", livro->nome_livro);
    printf("Nome do Autor: %s\n", livro->nome_autor);
    printf("Ano de Publicacao: %d\n", livro->ano);
    printf("-------------------------------------\n");
}

void imprimir_ordem_inversa_pilha(pilha *p) {
 
   imprimir_ordem_inversa(p->topo);
}



int main() {

    pilha *p1 = (pilha*)malloc(sizeof(pilha));
    int res=0;

    if(p1==NULL) {
        printf("\nErro de alocacao de memoria.");
        exit(0);
    }else {

        inicializa(p1);

        while(res!=5) {

            printf("\nEscolha uma opcao:");
            printf("\nAdicionar livro [1]");
            printf("\nRemover livro [2]");
            printf("\nImprimir livros [3]");
            printf("\nImprimir ordem [4]");
            printf("\nEncerrar aplicacao [5]\nR: ");
            scanf("%i", &res);

            switch(res) {
                case 1:
                    empilhar(p1);
                    break;
                case 2: {
                    desempilhar(p1);
                    break;
                }    
                case 3:
                    printar(p1);
                    break;
                case 4:
                    imprimir_ordem_inversa_pilha(p1);
                    break;    
                case 5:
                    free(p1);
                    printf("\nEncerrando aplicacao...");
                    break;
                default:
                    printf("\nEscolha uma opcao certa.\n");
                    break;
            }
        }
    }

    return 0;
}