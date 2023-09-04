#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ALUNOS 3 // A quantidade de alunos pode ser editada aqui!
#define MAX_NOTAS 5

struct fichaAluno {
    char nome[50];
    char materia[30];
    char situacao[12];
    float nota[MAX_NOTAS];
};

/* Fun��o simples para o usu�rio inserir a disciplina. */
void inserirDisciplina(struct fichaAluno *aluno){
    printf("Primeiramente, insira o nome da disciplina em que os alunos est�o inscritos: ");
    scanf("%29[^\n]",aluno->materia);
    return;
}

/* Fun��o para calcular e retornar a m�dia do aluno. */
float calcularMedia(struct fichaAluno *aluno){
    int i;
    float soma = 0.0;
    for(i = 0; i < 2; i++){
        soma += aluno->nota[i];
    }
    aluno->nota[2] = soma/2.0;
    return aluno->nota[2];
}

/* Fun��o para apresenta��o do sistema de notas e
instru��es de como utilizar suas funcionalidades. */
void verificarMediaFinal(struct fichaAluno *aluno){
    aluno->nota[4] = (aluno->nota[2] + aluno->nota[3])/2;
    strcpy(aluno->situacao, (aluno->nota[4] >= 5.0) ? "Aprovado" : "Reprovado");
    printf("O aluno est� %s!\n", aluno->situacao);
}

/* Fun��o booleana para retornar true, nos casos do
aluno ser reprovado ou aprovado por conta da m�dia.
Para o caso de retornar false, quer dizer que o aluno
ir� dar entrada na nota final e receber� a m�dia final. */
bool verificarMedias(struct fichaAluno *aluno, float *media){
    if(*media >= 7.0) {
        aluno->nota[3] = 0.0;
        aluno->nota[4] = aluno->nota[2];
        strcpy(aluno->situacao, "Aprovado");
        printf("O aluno est� %s!\n", aluno->situacao);
        return true;
    } else {
        if (*media < 4.0) {
            aluno->nota[3] = 0.0;
            aluno->nota[4] = aluno->nota[2];
            strcpy(aluno->situacao, "Reprovado");
            printf("O aluno est� %s!\n", aluno->situacao);
            return true;
        }
    }
    return false;
}
