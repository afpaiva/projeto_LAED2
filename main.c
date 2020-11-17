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

//17/11
//LUCAS

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
        telaInicial();
        menuInicial();

        yellow();
        printf("Informe a opção: ");
        blue();
        scanf("%d", &opc);
        reset_cores();

        switch (opc)
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

            case 6: 
                CLEAR_SCREEN;
                opcaoSobre();
                pause();
            break;

            case 7: // sair
                CLEAR_SCREEN;
                red();
                printf("\nPrograma encerrado... Até logo!!! (∗ ･‿･)ﾉ゛\n\n");
                exit(0);
            break;

            default:
                CLEAR_SCREEN;
                red();
                printf("\nOps... Opção inválida, escolha uma opção válida.\n");
                pause();
        }

    }while(opc != 7);

  return 0;
}