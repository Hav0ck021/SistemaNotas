#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "media/media.h"
#include "file/notas.h"
#include "os/os.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct fichaAluno aluno[MAX_ALUNOS];
    int i, j, SO = 0;
    float media;
    verificarSisOp(&SO);
    printf("Bem vindo ao Sistema de Notas da Universidade Estadual do Rio de Janeiro (UERJ)!\nDesenvolvido por: Caio Gabriel.\n\n");
    printf(" - Caso o aluno tenha média maior ou igual a 7.0, é considerado como aprovado\n");
    printf(" - Se a nota for menor que 4.0, o aluno é diretamente reprovado.\n");
    printf(" - Se a nota for menor que 7.0 e maior ou igual a 4.0, poderá fazer a prova final.\n\n");

    printf("Primeiramente, insira o nome da disciplina em que os alunos estão inscritos: ");
    scanf("%29[^\n]",aluno->materia);

    for (i = 0; i < MAX_ALUNOS; i++) {
        lerNotas(&aluno[i]);
        media = calcularMedia(&aluno[i]);
        verificarMedia(&aluno[i], &media);
        limparTelaSO(&SO);
    }

    salvarNotas(&aluno);
    printf("Os seguintes dados foram salvos no arquivo 'notas.csv'.\n");
    saidaTabelaNotas(&aluno);
    return 0;
}
