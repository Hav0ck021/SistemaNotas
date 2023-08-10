#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ALUNOS 3
#define MAX_NOTAS 5

void criarArquivo() {
    FILE *arquivo;
    arquivo = fopen("notas.csv","w");
    if (arquivo == NULL) {
        printf("O arquivo não pode ser criado, pois já existe!\n");
    } else {
        printf("O arquivo foi criado com sucesso!\n");
        fclose(arquivo);
    }
}
