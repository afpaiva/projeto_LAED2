/*

PUC-MG Poços de Caldas, 02 de dezembro de 2020
LABORATÓRIO DE ALGORÍTMOS E ESTRUTURAS DE DADOS 2
PROF. Cláudio Corrêa

EQUIPE.
André Fonseca de Paiva
Deborah Dalonso Frederico
Fernando Thales Pereira
Lucas Omar Andrade Leal

O trabalho consiste na elaboração de um programa
em C que trabalhe com estruturas dinâmicas.
Nesta proposta elaboramos um sistema de
cadastro de pacientes e consultas médicas
utilizando a estrutura LISTA.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"
#include "kiss_sdl.h"

#ifdef _WIN32
#   define CLEAR_SCREEN system("cls || clear");
#else
#   define CLEAR_SCREEN puts("\x1b[H\x1b[2J");
#endif

// cabeçalhos de funções para chamadas de botões
void button_event_cadastraPaciente(kiss_button *button, SDL_Event *e, int *draw, listaPaciente *lp);
void button_event_acessaAgenda(kiss_button *button, SDL_Event *e, int *draw, listaPaciente lp);
void button_event_mostraPacientes(kiss_button *button, SDL_Event *e, int *draw, listaPaciente lp);
void button_event_opcaoSobre(kiss_button *button, SDL_Event *e, int *draw);
void button_event_opcaoSair(kiss_button *button, SDL_Event *e, int *draw, int *quit);

int main(int argc, char **argv)
{
  CLEAR_SCREEN;
  setlocale(LC_ALL, "Portuguese");
  telaInicial();

  listaPaciente lp;
  cria(&lp);

  for (int i = 0; i < 10; i++)
  {
  insereListaFake(&lp, i); /* inclui automaticamente uma
                          lista fake de 10 pacientes, apenas
                          para o programa iniciar com dados */ 
  }

  SDL_Renderer *renderer;
  SDL_Event e;
  kiss_array objects;
  kiss_window window;
  kiss_label labelTitulo = {0};

  kiss_label label_cadastraPaciente = {0};
  kiss_label label_acessaAgenda = {0};
  kiss_label label_mostraOcorrencias = {0};
  kiss_label label_mostraPacientes = {0};
  kiss_label label_opcaoSobre = {0};
  kiss_label label_opcaoSair = {0};

  kiss_button button_cadastraPaciente = {0};
  kiss_button button_acessaAgenda = {0};
  kiss_button button_mostraOcorrencias = {0};
  kiss_button button_mostraPacientes = {0};
  kiss_button button_opcaoSobre = {0};
  kiss_button button_opcaoSair = {0};


  char titulo[KISS_MAX_LENGTH];
  int draw, quit;

  quit = 0;
  draw = 1;

  kiss_array_new(&objects);
  renderer = kiss_init("Agenda Médica Eletrônica", &objects, 400, 500);
  if (!renderer) return 1;

  kiss_window_new(&window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);

  
  strcpy(titulo, "MENU PRINCIPAL");
  kiss_label_new(&labelTitulo, &window, titulo, window.rect.w/2 - strlen(titulo) * kiss_textfont.advance/2, 50);
  labelTitulo.textcolor.r = 255;

  kiss_label_new(&label_cadastraPaciente, &window, "Agendar consulta", 50, 100);
  kiss_label_new(&label_acessaAgenda, &window, "Acessar agenda", 50, 150);
  kiss_label_new(&label_mostraOcorrencias, &window, "Listar ocorrências", 50, 200);
  kiss_label_new(&label_mostraPacientes, &window, "Listar pacientes", 50, 250);
  kiss_label_new(&label_opcaoSobre, &window, "Sobre", 50, 350);
  kiss_label_new(&label_opcaoSair, &window, "Sair", 50, 400);

  kiss_button_new(&button_cadastraPaciente, &window, "->", 250, 100);
  kiss_button_new(&button_acessaAgenda, &window, "->", 250, 150);
  kiss_button_new(&button_mostraOcorrencias, &window, "->", 250, 200);
  kiss_button_new(&button_mostraPacientes, &window, "->", 250, 250);
  kiss_button_new(&button_opcaoSobre, &window, "->", 250, 350);
  kiss_button_new(&button_opcaoSair, &window, "->", 250, 400);

  window.visible = 1;

  while (!quit) {
    SDL_Delay(10);
    while (SDL_PollEvent(&e)) {

      if (e.type == SDL_QUIT) quit = 1;
      kiss_window_event(&window, &e, &draw);
      button_event_cadastraPaciente(&button_cadastraPaciente, &e, &draw, &lp);
      button_event_acessaAgenda(&button_acessaAgenda, &e, &draw, lp);
      // button_event_mostraOcorrencias(&button_mostraPacientes, &e, &draw, lp);
      button_event_mostraPacientes(&button_mostraPacientes, &e, &draw, lp);
      button_event_opcaoSobre(&button_opcaoSobre, &e, &draw);
      button_event_opcaoSair(&button_opcaoSair, &e, &draw, &quit);
    }

    if (!draw) continue;
    SDL_RenderClear(renderer);
    kiss_window_draw(&window, renderer);
    kiss_label_draw(&labelTitulo, renderer);

    kiss_label_draw(&label_cadastraPaciente, renderer);
    kiss_label_draw(&label_acessaAgenda, renderer);
    kiss_label_draw(&label_mostraOcorrencias, renderer);
    kiss_label_draw(&label_mostraPacientes, renderer);
    kiss_label_draw(&label_opcaoSobre, renderer);
    kiss_label_draw(&label_opcaoSair, renderer);

    kiss_button_draw(&button_cadastraPaciente, renderer);
    kiss_button_draw(&button_acessaAgenda, renderer);
    kiss_button_draw(&button_mostraOcorrencias, renderer);
    kiss_button_draw(&button_mostraPacientes, renderer);
    kiss_button_draw(&button_opcaoSobre, renderer);
    kiss_button_draw(&button_opcaoSair, renderer);

    SDL_RenderPresent(renderer);
    draw = 0;
  }
  kiss_clean(&objects);

  return 0;
}



void button_event_cadastraPaciente(kiss_button *button, SDL_Event *e, int *draw, listaPaciente *lp)
{
  if (kiss_button_event(button, e, draw)){
    CLEAR_SCREEN;
    telaInicial();
    cadastraPaciente(lp);
    CLEAR_SCREEN;
    telaInicial();
    printf("\n\nConsulta marcada com sucesso!\n\n");
  }
}

void button_event_acessaAgenda(kiss_button *button, SDL_Event *e, int *draw, listaPaciente lp)
{
  if (kiss_button_event(button, e, draw)){
    CLEAR_SCREEN;
    telaInicial();
    acessaAgenda(lp);
  }
}

void button_event_mostraPacientes(kiss_button *button, SDL_Event *e, int *draw, listaPaciente lp)
{
  if (kiss_button_event(button, e, draw)){
    CLEAR_SCREEN;
    telaInicial();
    mostraPacientes(lp);
  }
}

void button_event_opcaoSobre(kiss_button *button, SDL_Event *e, int *draw)
{
  if (kiss_button_event(button, e, draw)){
    CLEAR_SCREEN;
    telaInicial();
    opcaoSobre();
  }
}

void button_event_opcaoSair(kiss_button *button, SDL_Event *e, int *draw, int *quit)
{
  if (kiss_button_event(button, e, draw)){
    CLEAR_SCREEN;
    red();
    printf("\nPrograma encerrado... Até logo!!! (∗ ･‿･)ﾉ゛\n\n");
    *quit = 1;
  }
}
