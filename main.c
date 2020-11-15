//TRABALHO C
//MAIN

//18/10
//DEBORAH

//28/10
//ANDRE

//10/11
//DEBORAH

//14/11
//ANDRE

//gcc -Wall -o main main.c

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

#ifdef _WIN32
#   define CLEAR_SCREEN system("cls || clear");
#else
#   define CLEAR_SCREEN puts("\x1b[H\x1b[2J");
#endif

int main()
{
    listaPaciente lp;
    int opc = 0;

    setlocale(LC_ALL, "Portuguese");

    cria(&lp);

    do
    {
        CLEAR_SCREEN;
        printf("\n...........................\n");
        printf("\n AGENDA MÉDICA ELETRÔNICA:\n");
        printf("\n...........................\n");
        printf("\n\t  Menu:\n");
        printf("\n...........................\n");
        printf("\n1. Marcar consulta");
        printf("\n2. Acessar agenda");
        printf("\n3. Ocorrencias");
        printf("\n4. Lista pacientes");
        printf("\n5. Editar ocorrencias");
        printf("\n6. Sobre");
        printf("\n7. Sair\n");
        printf("\nInforme a opção: ");
        scanf("%d",&opc);
        printf("\n...........................\n");

    switch(opc)
        {
            case 1: // marcar consulta
                CLEAR_SCREEN;
                cadastraPaciente(&lp);
            break;

            case 2: // acessar agenda
                CLEAR_SCREEN;
                acessaAgenda(lp);
                pause();
            break;

            case 3: // ocorrencias


            break;

            case 4: // listar pacientes
                CLEAR_SCREEN;
                mostraPacientes(lp);
                pause();
            break;

            case 5: // editar ocorrencias
                CLEAR_SCREEN;
            break;

            case 6: // sobre
                CLEAR_SCREEN;
            break;

            case 7: // sair
                CLEAR_SCREEN;
                printf("\nPrograma encerrado......\n");
            break;

            default:
                CLEAR_SCREEN;
                printf("\nOps....opção inválida... você está perdido amigo?\n");
                pause();
        }

    }while(opc != 6);

  return 0;
}