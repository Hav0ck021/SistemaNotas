#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 3
#define MAX_NOTAS 5

void lerNotas(struct fichaAluno *aluno){
    int i, j;
    printf("Insira o nome do aluno: ");
    scanf(" %49[^\n]", aluno->nome);
    printf("\nInsira as notas do seguinte aluno:\n");
    for (j = 0; j < 2; j++) {
        do {
            scanf("%f", &aluno->nota[j]);
            if (aluno->nota[j] < 0.0 || aluno->nota[j] > 10.0) {
                printf("Insira uma nota veridica!\n");
            }
        } while (aluno->nota[j] < 0.0 || aluno->nota[j] > 10.0);
    }
}

void salvarNotas(struct fichaAluno *aluno){
    FILE *arquivo;
    int i, j;
    arquivo = fopen("notas.csv","w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo, ele não pode ser aberto.\n");
        return 1;
    } else {
        fprintf(arquivo, "Disciplina: %s\n", aluno->materia);
        for (i = 0; i < MAX_ALUNOS; i++) {
            fprintf(arquivo,"%s", aluno[i].nome);
            for (j = 0; j < MAX_NOTAS; j++) {
                fprintf(arquivo,",%.2f", aluno[i].nota[j]);
            }
            fprintf(arquivo,",%s", aluno[i].situacao);
            fprintf(arquivo, "\n");
        }
        fclose(arquivo);
    }
}

void saidaTabelaNotas(struct fichaAluno *aluno) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Nome: %s ", aluno[i].nome);
        for (int j = 0; j < MAX_NOTAS; j++)
        {
            printf(" %.2f ", aluno[i].nota[j]);
        }
        printf(" %s \n", aluno[i].situacao);
    }
}
