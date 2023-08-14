#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//#define CAMINHO_PASTA "SistemaNotas/data/"
#define MAX_ALUNOS 3
#define MAX_NOTAS 5

/* Função para criar o arquivo e verificar se já existe. */
bool criarArquivo(const char *nomeDisciplina) {
    char nomeArquivo[100];
    snprintf(nomeArquivo, sizeof(nomeArquivo), "notas_%s.csv", nomeDisciplina);

    FILE *arquivo = fopen(nomeArquivo ,"w");

    if (arquivo == NULL) {
        printf("O arquivo não pode ser criado, pois já existe!\n");
        return false;
    } else {
        printf("O arquivo '%s' foi criado com sucesso!\n", nomeArquivo);
        fclose(arquivo);
        return true;
    }
}
