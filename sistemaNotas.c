#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "file/aluno.h"
#include "file/file.h"
#include "os/os.h"
#include "file/notas.h"

int main() {
    // Inicializar a adaptação do programa ao idioma Português.
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis e da estrutura de dados "Aluno".
    struct fichaAluno aluno[MAX_ALUNOS];
    int i, j, SO = 0;
    float media;

    /* Inicializa as funções de introdução ao Sistema, escolha
    do Sistema Operacional utilizado pelo usuário e entrada
    do nome da Disciplina que receberá as notas. */
    verificarSisOp(&SO);
    apresentacaoSistema();
    inserirDisciplina(aluno);

    /* Loop condicional, para realizar a entrada de notas e
    verificação de média para cada aluno. Para ajustar a
    quantidade de alunos, vá para o arquivo aluno.h e altere
    o valor da definição de MAX_ALUNOS. */
    for (i = 0; i < MAX_ALUNOS; i++) {
        lerNomeNotas(&aluno[i]);
        media = calcularMedia(&aluno[i]);
        if(verificarMedias(&aluno[i], &media) == false) {
            lerNotaFinal(&aluno[i]);
            verificarMediaFinal(&aluno[i]);
        }
        limparTelaSO(&SO);
    }

    /* Declaração das funções para criar o arquivo que receberá as notas,
    salvar as notas no arquivo e encerrar o Sistema, caso a função
    criarArquivo retorne um valor true. */
    if (criarArquivo(aluno->materia)){
        salvarNotas(aluno->materia, aluno);
        saidaTabelaNotas(aluno);
    }
    return 0;
}
