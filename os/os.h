#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <windows.h> //Biblioteca para funções do terminal Microsoft Windows
#include <unistd.h>  //Biblioteca para funções do terminal Linux

/* Função para apresentação do sistema de notas e
instruções de como utilizar suas funcionalidades. */
void apresentacaoSistema(){
    printf("Bem vindo ao Sistema de Notas da Universidade Estadual do Rio de Janeiro (UERJ)!\nDesenvolvido por: Caio Gabriel.\n\n");
    printf(" - Caso o aluno tenha média maior ou igual a 7.0, é considerado como aprovado\n");
    printf(" - Se a nota for menor que 4.0, o aluno é diretamente reprovado.\n");
    printf(" - Se a nota for menor que 7.0 e maior ou igual a 4.0, poderá fazer a prova final.\n\n");
    return;
}

/* Função para realizar a limpeza de tela, com
base no sistema operacional indicado pelo usuário. */
void limparTelaSO(int *num){
    switch(*num){
        case 1:
            sleep(3);
            system("cls");
            break;
        case 2:
            sleep(3);
            system("clear");
            break;
        case 3:
            sleep(3);
            system("clear");
            break;
    }
}

/* Função para identificar o sistema operacional,
podendo ser 3 opções: Windows, Linux ou MacOS. */
void verificarSisOp(int *num){
    int opcao;
    bool opcaoValida = false;

    printf("Antes de iniciarmos o sistema, poderia indicar qual é o seu sistema operacional?\n1 - Microsoft Windows\n2 - Linux e suas distribuições\n3 - MacOS\n");

    while(!opcaoValida){
        printf("Insira o número que corresponde ao seu sistema: ");
        scanf("%d", &opcao);
        if (opcao < 0 || opcao > 3) {
            printf("Número inválido, insira uma das opções mencionadas!\n");
            continue;
        }
        opcaoValida = true;
        *num = opcao;
    }
    *num = (*num >= 1 && *num <= 3) ? *num : 0;
    limparTelaSO(&opcao);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
