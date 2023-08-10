#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ALUNOS 3
#define MAX_NOTAS 5

bool validarNota(float *nota) {
    return *nota >= 0.0 && *nota <= 10.0;
}

void lerNotaFinal(struct fichaAluno *aluno){
    bool opcaoValida = false;

    do {
        printf("Insira a nota da prova final!\n");
        printf("Nota PF: ");
        scanf("%f", &aluno->nota[3]);

        if (!validarNota(&aluno->nota[3])) {
            printf("Insira uma nota veridica!\n");
        } else {
            opcaoValida = true;
        }
    } while (!opcaoValida);
}

void lerNomeNotas(struct fichaAluno *aluno){
    int j;
    printf("Insira o nome do aluno: ");
    scanf(" %49[^\n]", aluno->nome);

    printf("\nInsira as notas do seguinte aluno:\n");
    for (j = 0; j < 2; j++) {
        do {
            printf("Nota %d: ", j + 1);
            scanf("%f", &aluno->nota[j]);

            if (!validarNota(&aluno->nota[j])) {
                printf("Insira uma nota veridica!\n");
            }
        } while (!validarNota(&aluno->nota[j]));
    }
}

void salvarNotas(struct fichaAluno *aluno){
    FILE *arquivo;
    int i, j;

    arquivo = fopen("notas.csv","r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
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
        printf("\nOs dados anteriores foram salvos no arquivo 'notas.csv'.\n");
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
