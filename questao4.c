#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    char nome[20];
    int idade;
    float media;
}Aluno;

void pesquisa(Aluno aluno[], int tam) {

    char busca[20];
    int i,aux=0;

    printf("\n----------------------------------");
    printf("\nBuscar aluno por nome: ");
    scanf("%s", busca);

    for(i=0; i<tam; i++) {
        if(strcmp(aluno[i].nome, busca)==0) {
            printf("\nNome: %s", aluno[i].nome);
            printf("\nIdade: %i", aluno[i].idade);
            printf("\nMedia: %.2f", aluno[i].media);
            aux=1;
            break;
        }
    }
    if(aux==0) {
        printf("\nAluno nao encontrado.");
    }

    printf("\n----------------------------------");
}

void media(Aluno aluno[], int tam) {

    float media=0;
    int i;

    for(i=0; i<tam; i++) {
        media += aluno[i].media;
    }
    media = media/tam;

    printf("\n+--------------------------+");
    printf("\n|A media dos alunos eh: %.2f|", media);
    printf("\n+--------------------------+");
}

int main() {

    int tam=0, i;
    printf("\nEscreva quantos alunos tem na turma: ");
    scanf("%i", &tam);

    Aluno aluno[tam];

    for(i=0; i<tam; i++) {
        printf("\n----------------------------------");
        printf("\n|Digite o nome do aluno %i:", i+1);
        scanf("%s", aluno[i].nome);

        printf("\n|Digite a idade do aluno %i:", i+1);
        scanf("%i", &aluno[i].idade);

        printf("\n|Digite a media do aluno %i:", i+1);
        scanf("%f", &aluno[i].media);
        printf("\n----------------------------------");
    }

    pesquisa(aluno, tam);
    media(aluno, tam);

    return 0;
}