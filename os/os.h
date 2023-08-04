#include <stdio.h>
#include <stdbool.h>

void verificarSisOp(int *num){
    int opcao;
    bool opcaoValida = false;

    printf("Antes de iniciarmos o sistema, poderia indicar qual é o seu sistema operacional?\n1 - Microsoft Windows\n2 - Linux e suas distribuições\n3 - MacOS\n");

    while(!opcaoValida){
        printf("Insira o número que corresponde ao seu sistema: ");
        scanf("%d", &opcao);
        if (opcao < 0 || opcao > 3) {
            printf("Número inválido, insira uma das opções mencionadas!\n");
        } else {
            opcaoValida = true;
            *num = opcao;
        }
    }
    limparTelaSO(&opcao);
}

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
