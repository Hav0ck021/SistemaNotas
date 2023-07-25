#include <stdio.h>

int main()
{
    float vetor[3][5];

    printf("Bem vindo ao sistema de notas da UERJ!\nDesenvolvido por: Caio Gabriel.\n");
    printf(" - Caso o aluno tenha media maior ou igual a 7.0, eh considerado como aprovado\n");
    printf(" - Se a nota for menor que 4.0, o aluno sera reprovado diretamente.\n");
    printf(" - Se a nota for menor que 7.0 e maior ou igual a 4.0, podera fazer a prova final.\n");

    for (int i = 0; i < 3; i++) {
        float nota;

        printf("\nInsira a nota do seguinte aluno:\n");
        for (int j = 0; j < 2; j++) {
            scanf("%f", &nota);

            if (nota < 0.0 || nota > 10.0) {
                printf("Insira uma nota veridica!");
            } else {
                vetor[i][j] = nota;
            }
        }

        vetor[i][2] = (vetor[i][0] + vetor[i][1])/2;

        if(vetor[i][2] >= 7.0) {
            printf("O aluno esta aprovado!\n");
            vetor[i][4] = vetor[i][2];
        } else {
            if (vetor[i][2] < 4.0) {
                printf("O aluno esta reprovado!\n");
            } else {
                float notaPF;
                printf("Insira a nota da prova final!\n");
                scanf("%f", &notaPF);

                vetor[i][3] = notaPF;
                vetor[i][4] = (vetor[i][2] + vetor[i][3])/2;

                if(vetor[i][4] >= 5.0){
                    printf("O aluno esta aprovado!\n");
                } else {
                    printf("O aluno esta reprovado!\n");
                }
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Aluno %d:  ", i);
        for (int j = 0; j < 5; j++)
        {
            printf("%.2f  ", vetor[i][j]);
        }
        printf("\n");
    }
    return 0;
}
