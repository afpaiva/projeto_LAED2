//TRABALHO C
//MAIN

//18/10
//DEBORAH

//28/10
//ANDRE

//gcc -o inicial inicial.c registro.h funcoes.h

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cores.h"
#include "funcoes.h"

#ifdef _WIN32
#   define CLEAR_SCREEN system("cls || clear");
#else
#   define CLEAR_SCREEN puts("\x1b[H\x1b[2J");
#endif

void menuOcorrencias();

void main()
{
    listaPaciente lp;
    pilhaOcorrencia ocorrencias;
    int opc = 0;

    setlocale(LC_ALL, "Portuguese");

    cria(&lp);
    criaOcorrencias(&ocorrencias);

    do
    {
        CLEAR_SCREEN;
        printf("\n...........................\n");
        red();
        printf("\n AGENDA MÉDICA ELETRÔNICA:\n");
        reset_cores();
        printf("\n...........................\n");
        yellow();
        printf("\n\t  Menu:\n");
        blue();
        printf("\n...........................\n");
        printf("\n1. Cadastrar paciente");
        printf("\n2. Acessar agenda");
        printf("\n3. Ocorrencias");
        reset_cores();
        printf("\n4. Lista pacientes");
        printf("\n5. Sobre");
        printf("\n6. Sair\n");
        printf("\nInforme a opção: ");
        scanf("%d",&opc);
        printf("\n...........................\n");


    switch(opc)
        {
            case 1:
                CLEAR_SCREEN;
                cadastraPaciente(&lp);
            break;

            case 2:
                CLEAR_SCREEN;
                acessaAgenda(lp);
                pause();
            break;

            case 3:
                menuOcorrencias();
                // encontra-se abaixo,
                // neste arquivo mesmo
                // por ser apenas um menu
            break;

            case 4:
                CLEAR_SCREEN;
                mostraPacientes(lp);
                pause();
            break;

            case 5:
                CLEAR_SCREEN;
            break;

            case 6:
                CLEAR_SCREEN;
                printf("\nPrograma encerrado......\n");
            break;

            default:
                CLEAR_SCREEN;
                printf("\nOps....opção inválida... você está perdido amigo?\n");
                pause();
        }

    }while(opc != 6);
}

void menuOcorrencias()
{
    int opc = 0;
    do
    {
        CLEAR_SCREEN;
        printf("\n...........................\n");
        printf("\n OCORRENCIAS:\n");
        printf("\n...........................\n");
        printf("\n1. Registrar ocorrência");
        printf("\n2. Listar ocorrências");
        printf("\n3. Editar ocorrências");
        printf("\n4. Excluir ocorrência");
        printf("\n5. Voltar\n");
        printf("\nInforme a opção: ");
        scanf("%d",&opc);
        printf("\n...........................\n");
    } while (opc != 5);

     switch(opc)
        {
            case 1:
                CLEAR_SCREEN;

            break;

            case 2:
                CLEAR_SCREEN;
            break;

            case 3:
                CLEAR_SCREEN;
            break;

            case 4:
                CLEAR_SCREEN;
            break;

            case 5:
                CLEAR_SCREEN;
            break;

            default:
                CLEAR_SCREEN;
                printf("\nOps....opção inválida... você está perdido amigo?\n");
                pause();
        }
}