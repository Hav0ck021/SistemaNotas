#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ALUNOS 3
#define MAX_NOTAS 5

struct fichaAluno {
    char nome[50];
    char materia[30];
    char situacao[12];
    float nota[MAX_NOTAS];
};

void inserirDisciplina(struct fichaAluno *aluno){
    printf("Primeiramente, insira o nome da disciplina em que os alunos estão inscritos: ");
    scanf("%29[^\n]",aluno->materia);
    return;
}

float calcularMedia(struct fichaAluno *aluno){
    int i;
    float soma = 0.0;
    for(i = 0; i < 2; i++){
        soma += aluno->nota[i];
    }
    aluno->nota[2] = soma/2.0;
    return aluno->nota[2];
}

void verificarMediaFinal(struct fichaAluno *aluno){
    aluno->nota[4] = (aluno->nota[2] + aluno->nota[3])/2;
    strcpy(aluno->situacao, (aluno->nota[4] >= 5.0) ? "Aprovado" : "Reprovado");
    printf("O aluno está %s!\n", aluno->situacao);
}

void verificarMedias(struct fichaAluno *aluno, float *media){
    if(*media >= 7.0) {
        aluno->nota[3] = 0.0;
        aluno->nota[4] = aluno->nota[2];
        strcpy(aluno->situacao, "Aprovado");
        printf("O aluno está %s!\n", aluno->situacao);
        return;
    } else {
        if (*media < 4.0) {
            aluno->nota[3] = 0.0;
            aluno->nota[4] = aluno->nota[2];
            strcpy(aluno->situacao, "Reprovado");
            printf("O aluno está %s!\n", aluno->situacao);
            return;
        }
    }
    lerNotaFinal(aluno);
    verificarMediaFinal(aluno);
}
