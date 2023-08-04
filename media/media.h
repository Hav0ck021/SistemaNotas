#include <stdio.h>
#define MAX_ALUNOS 3
#define MAX_NOTAS 5

struct fichaAluno {
    char nome[50];
    char materia[30];
    char situacao[10];
    float nota[MAX_NOTAS];
};

float calcularMedia(struct fichaAluno *aluno){
    int i;
    float soma = 0.0;
    for(i = 0; i < 2; i++){
        soma += aluno->nota[i];
    }
    aluno->nota[2] = soma/2.0;
    return aluno->nota[2];
}

void verificarMedia(struct fichaAluno *aluno, float *media){
    if(*media >= 7.0) {
        printf("O aluno esta aprovado!\n");
        aluno->nota[3] = 0;
        aluno->nota[4] = aluno->nota[2];
        strcpy(aluno->situacao, "Aprovado");
    } else {
        if (*media < 4.0) {
            printf("O aluno esta reprovado!\n");
            aluno->nota[3] = 0;
            aluno->nota[4] = aluno->nota[2];
            strcpy(aluno->situacao, "Reprovado");
        } else {
            printf("Insira a nota da prova final!\n");
            do {
                scanf("%f", &aluno->nota[3]);

                if (aluno->nota[3] < 0.0 || aluno->nota[3] > 10.0) {
                    printf("Insira uma nota veridica!\n");
                } else {
                    aluno->nota[4] = (aluno->nota[2] + aluno->nota[3])/2;
                    if(aluno->nota[4] >= 5.0) {
                        printf("O aluno esta aprovado!\n");
                        strcpy(aluno->situacao, "Aprovado");
                    } else {
                        printf("O aluno esta reprovado!\n");
                        strcpy(aluno->situacao, "Reprovado");
                    }
                }
            } while (aluno->nota[3] < 0.0 || aluno->nota[3] > 10.0);
        }
    }
}
