#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "file/aluno.h"
#include "file/file.h"
#include "os/os.h"
#include "file/notas.h"

int main() {
    // Inicializar a adapta��o do programa ao idioma Portugu�s.
    setlocale(LC_ALL, "Portuguese");

    // Declara��o de vari�veis e da estrutura de dados "Aluno".
    struct fichaAluno aluno[MAX_ALUNOS];
    int i, j, SO = 0;
    float media;

    /* Inicializa as fun��es de introdu��o ao Sistema, escolha
    do Sistema Operacional utilizado pelo usu�rio e entrada
    do nome da Disciplina que receber� as notas. */
    verificarSisOp(&SO);
    apresentacaoSistema();
    inserirDisciplina(aluno);

    /* Loop condicional, para realizar a entrada de notas e
    verifica��o de m�dia para cada aluno. Para ajustar a
    quantidade de alunos, v� para o arquivo aluno.h e altere
    o valor da defini��o de MAX_ALUNOS. */
    for (i = 0; i < MAX_ALUNOS; i++) {
        lerNomeNotas(&aluno[i]);
        media = calcularMedia(&aluno[i]);
        if(verificarMedias(&aluno[i], &media) == false) {
            lerNotaFinal(&aluno[i]);
            verificarMediaFinal(&aluno[i]);
        }
        limparTelaSO(&SO);
    }

    /* Declara��o das fun��es para criar o arquivo que receber� as notas,
    salvar as notas no arquivo e encerrar o Sistema, caso a fun��o
    criarArquivo retorne um valor true. */
    if (criarArquivo(aluno->materia)){
        salvarNotas(aluno->materia, aluno);
        saidaTabelaNotas(aluno);
    }
    return 0;
}
