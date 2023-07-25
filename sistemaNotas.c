#include <stdio.h>
#include <string.h>

struct fichaAluno {
    char nome[50];
    char materia[30];
    float nota;
    float notaPF;
};

int main()
{
    struct fichaAluno aluno[3];
    char nomes[3][50];
    float vetor[3][5] = {0};

    printf("Bem vindo ao Sistema de Notas da Universidade Estadual do Rio de Janeiro (UERJ)!\nDesenvolvido por: Caio Gabriel.\n\n");
    printf(" - Caso o aluno tenha media maior ou igual a 7.0, eh considerado como aprovado\n");
    printf(" - Se a nota for menor que 4.0, o aluno eh diretamente reprovado.\n");
    printf(" - Se a nota for menor que 7.0 e maior ou igual a 4.0, podera fazer a prova final.\n\n");

    printf("Primeiramente, insira o nome da disciplina em que os alunos estao inscritos: ");
    scanf("%29[^\n]",aluno->materia);

    for (int i = 0; i < 3; i++) {
        printf("Insira o nome do aluno: ");
        scanf(" %49[^\n]", aluno[i].nome);

        printf("\nInsira as notas do seguinte aluno:\n");
        for (int j = 0; j < 2; j++) {
            do {
                scanf("%f", &aluno[i].nota);
                if (aluno[i].nota < 0.0 || aluno[i].nota > 10.0) {
                    printf("Insira uma nota veridica!\n");
                } else {
                    vetor[i][j] = aluno[i].nota;
                }
            } while (aluno[i].nota < 0.0 || aluno[i].nota > 10.0);
        }

        vetor[i][2] = (vetor[i][0] + vetor[i][1])/2;

        if(vetor[i][2] >= 7.0) {
            printf("O aluno esta aprovado!\n");
            vetor[i][4] = vetor[i][2];
        } else {
            if (vetor[i][2] < 4.0) {
                printf("O aluno esta reprovado!\n");
            } else {
                printf("Insira a nota da prova final!\n");
                do {
                    scanf("%f", &aluno[i].notaPF);

                    if (aluno[i].notaPF < 0.0 || aluno[i].notaPF > 10.0) {
                        printf("Insira uma nota veridica!\n");
                    } else {
                        vetor[i][3] = aluno[i].notaPF;
                        vetor[i][4] = (vetor[i][2] + vetor[i][3])/2;

                        if(vetor[i][4] >= 5.0) {
                            printf("O aluno esta aprovado!\n");
                        } else {
                            printf("O aluno esta reprovado!\n");
                        }
                    }
                } while (aluno[i].notaPF < 0.0 || aluno[i].notaPF > 10.0);
            }
        }
        printf("\n");
    }

    printf("Disciplina: %s\n\n", aluno->materia);

    for (int i = 0; i < 3; i++) {
        printf("Aluno: %s  ", aluno[i].nome);
        for (int j = 0; j < 5; j++)
        {
            printf("%.2f  ", vetor[i][j]);
        }
        printf("\n");
    }
    return 0;
}
