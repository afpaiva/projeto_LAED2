#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"
#include "kiss_sdl.h"


void button_event(kiss_button *button, SDL_Event *e, int *draw, int *quit, listaPaciente *lp)
{
  if (kiss_button_event(button, e, draw)) cadastraPaciente(lp);
}

void button2_event(kiss_button *button, SDL_Event *e, int *draw, int *quit, listaPaciente lp)
{
  if (kiss_button_event(button, e, draw)) mostraPacientes(lp);
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "Portuguese");

  listaPaciente lp;
  int opc = 0;
  cria(&lp);

  SDL_Renderer *renderer;
  SDL_Event e;
  kiss_array objects;
  kiss_window window;

  kiss_label labelTitulo = {0};
  kiss_label labelAgendar = {0};
  kiss_button button_cadastraPaciente = {0};
  kiss_button button_mostraPacientes = {0};

  char titulo[KISS_MAX_LENGTH];
  int draw, quit;

  quit = 0;
  draw = 1;

  kiss_array_new(&objects);
  renderer = kiss_init("Agenda Médica Eletrônica", &objects, 1024, 768);
  if (!renderer) return 1;

  kiss_window_new(&window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);

  
  strcpy(titulo, "MENU PRINCIPAL");
  kiss_label_new(&labelTitulo, &window, titulo, window.rect.w/2 - strlen(titulo) * kiss_textfont.advance/2, 20);
  labelTitulo.textcolor.r = 255;

  kiss_label_new(&labelAgendar, &window, "Agendar uma consulta", 200, 200);


  kiss_button_new(&button_cadastraPaciente, &window, " ", 400, 100);
  kiss_button_new(&button_mostraPacientes, &window, " ", 400, 200);

  window.visible = 1;

  while (!quit) {
    SDL_Delay(10);
    while (SDL_PollEvent(&e)) {

      if (e.type == SDL_QUIT) quit = 1;
      kiss_window_event(&window, &e, &draw);
      //melhorar:
      button_event(&button_cadastraPaciente, &e, &draw, &quit, &lp);
      button2_event(&button_mostraPacientes, &e, &draw, &quit, lp);

    }
    if (!draw) continue;
    SDL_RenderClear(renderer);
    kiss_window_draw(&window, renderer);

    kiss_label_draw(&labelTitulo, renderer);
    kiss_label_draw(&labelAgendar, renderer);
    kiss_button_draw(&button_cadastraPaciente, renderer);
    kiss_button_draw(&button_mostraPacientes, renderer);

    SDL_RenderPresent(renderer);
    draw = 0;
  }
  kiss_clean(&objects);









    
    do
    {
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
                cadastraPaciente(&lp);
            break;

            case 2: // acessar agenda
                acessaAgenda(lp);
                pausar();
            break;

            case 3: // ocorrencias
            break;

            case 4: // listar pacientes
                mostraPacientes(lp);
                pausar();
            break;

            case 5: // editar ocorrencias
            break;

            case 6: 
                opcaoSobre();
                pausar();
            break;

            case 7: // sair
                red();
                printf("\nPrograma encerrado... Até logo!!! (∗ ･‿･)ﾉ゛\n\n");
                exit(0);
            break;

            default:
                red();
                printf("\nOps... Opção inválida, escolha uma opção válida.\n");
                pausar();
        }

    }while(opc != 7);

  return 0;
}