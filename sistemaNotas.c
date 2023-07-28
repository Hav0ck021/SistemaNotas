#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 3
#define MAX_NOTAS 5

struct fichaAluno {
    char nome[50];
    char materia[30];
    char situacao[15];
    float nota[MAX_NOTAS];
};

int main()
{
    FILE *arquivo;
    struct fichaAluno aluno[MAX_ALUNOS];
    int i, j;

    printf("Bem vindo ao Sistema de Notas da Universidade Estadual do Rio de Janeiro (UERJ)!\nDesenvolvido por: Caio Gabriel.\n\n");
    printf(" - Caso o aluno tenha media maior ou igual a 7.0, eh considerado como aprovado\n");
    printf(" - Se a nota for menor que 4.0, o aluno eh diretamente reprovado.\n");
    printf(" - Se a nota for menor que 7.0 e maior ou igual a 4.0, podera fazer a prova final.\n\n");

    printf("Primeiramente, insira o nome da disciplina em que os alunos estao inscritos: ");
    scanf("%29[^\n]",aluno->materia);

    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Insira o nome do aluno: ");
        scanf(" %49[^\n]", aluno[i].nome);

        printf("\nInsira as notas do seguinte aluno:\n");
        for (j = 0; j < 2; j++) {
            do {
                scanf("%f", &aluno[i].nota[j]);
                if (aluno[i].nota[j] < 0.0 || aluno[i].nota[j] > 10.0) {
                    printf("Insira uma nota veridica!\n");
                }
            } while (aluno[i].nota[j] < 0.0 || aluno[i].nota[j] > 10.0);
        }

        aluno[i].nota[2] = (aluno[i].nota[0] + aluno[i].nota[1])/2;

        if(aluno[i].nota[2] >= 7.0) {
            printf("O aluno esta aprovado!\n");
            aluno[i].nota[3] = 0;
            aluno[i].nota[4] = aluno[i].nota[2];
            strcpy(aluno[i].situacao, "Aprovado");
        } else {
            if (aluno[i].nota[2] < 4.0) {
                printf("O aluno esta reprovado!\n");
                strcpy(aluno[i].situacao, "Reprovado");
            } else {
                printf("Insira a nota da prova final!\n");
                do {
                    scanf("%f", &aluno[i].nota[3]);

                    if (aluno[i].nota[3] < 0.0 || aluno[i].nota[3] > 10.0) {
                        printf("Insira uma nota veridica!\n");
                    } else {
                        aluno[i].nota[4] = (aluno[i].nota[2] + aluno[i].nota[3])/2;

                        if(aluno[i].nota[4] >= 5.0) {
                            printf("O aluno esta aprovado!\n");
                            strcpy(aluno[i].situacao, "Aprovado");
                        } else {
                            printf("O aluno esta reprovado!\n");
                            strcpy(aluno[i].situacao, "Reprovado");
                        }
                    }
                } while (aluno[i].nota[3] < 0.0 || aluno[i].nota[3] > 10.0);
            }
        }
        printf("\n");
        system("cls");
    }
    arquivo = fopen("notas.csv","w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo, ele não pode ser aberto.\n");
        return 1;
    } else {
        fprintf(arquivo, "Disciplina: %s\n", aluno->materia);
        for (i = 0; i < MAX_ALUNOS; i++) {
            fprintf(arquivo,"%s", aluno[i].nome);
            for (j = 0; j < MAX_NOTAS; j++)
            {
                fprintf(arquivo,",%.2f", aluno[i].nota[j]);
            }
            fprintf(arquivo,",%s", aluno[i].situacao);
            fprintf(arquivo, "\n");
        }
        fclose(arquivo);
    }

    printf("Os seguintes dados foram salvos no arquivo 'notas.csv'.\n");

    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Nome: %s ", aluno[i].nome);
        for (j = 0; j < MAX_NOTAS; j++)
        {
            printf(" %.2f ", aluno[i].nota[j]);
        }
        printf(" %s \n", aluno[i].situacao);
    }

    return 0;
}
