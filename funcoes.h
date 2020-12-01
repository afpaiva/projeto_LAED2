#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"
#include "cores.h"

int incrementaIDpaciente(listaPaciente lp);
int insereListaFake(listaPaciente *lp, int a);
int validaData(int, int, int);
int validaHorario(int, int);
int retornaInt(char *);
int comparaHorarios(int dia, int mes, int ano,
                    int hora, int minuto, int gravidade ,listaPaciente lp, int id);

void pausar()
{
    pink();
    printf("\nTecle enter para continuar...\n");
    getchar();
}

void cria(listaPaciente *lp)
{
    lp->inicio = NULL;
    lp->fim = NULL;
    return;
};

int  cadastraPaciente(listaPaciente *lp)
{
  struct no *aux;
  int valida = 0;
  char validaInt[10];
  int opc = 0;
  for (int i = 0; i < 10; i++) validaInt[i] = 'x';

  aux = (struct no*) malloc(sizeof(struct no));

  if (aux == NULL) return 0;

  blue();
  printf("\nMarcar Consulta\n");
  reset_cores();

  if (lp->inicio == NULL)
  {   
      aux->p.IDpaciente = 1;
      blue();
      printf("\nNome: ");reset_cores();
      scanf(" %30[^\n]",aux->p.Nome_paciente);
      getchar();

      /*
      a função retornaInt() recebe um vetor-char e
      retorna um INT com os valores. Para caso o usuário
      escape um caracter na digitação        
      */

      blue();
      printf("\nIdade: ");
      reset_cores();
      scanf(" %10[^\n]",validaInt);
      aux->p.Idade = retornaInt(validaInt);
      
      blue();
      printf("\nTelefone 1: ");reset_cores();
      scanf(" %20[^\n]",aux->p.Telefone);
      getchar();
      
      blue();
      printf("\nCep: ");reset_cores();
      scanf(" %10[^\n]",aux->p.Cep);

      blue();
      printf("\nNumero: ");
      reset_cores();
      scanf(" %10[^\n]", validaInt);
      aux->p.Numero_casa = retornaInt(validaInt);

      blue();
      printf("\nResumo: ");reset_cores();
      scanf(" %150[^\n]",aux->p.Resumo);
      getchar();

      do{ 
        blue();
        printf("\nGravidade [1, 2 ou 3]: ");
        reset_cores();red();
        scanf("%d",&aux->p.Gravidade);
        if (aux->p.Gravidade == 1 ||
            aux->p.Gravidade == 2 ||
            aux->p.Gravidade == 3 )
            valida = 1;
        red();
        if (!valida) printf ("\nA gravidadade deve ser 1, 2 ou 3");
        reset_cores();
      } while (!valida);
      
      blue();
      printf("\nTelefone para contato de emergencia: ");
      reset_cores();
      scanf(" %20[^\n]",aux->p.Contato_emergencia);
      getchar();

      blue();
      printf("\nNome do contato de emergencia: ");
      reset_cores();
      scanf(" %30[^\n]",aux->p.Nome_contato_emergencia);
      getchar();

      do {
        blue();
        printf("\nData do Atendimento [dd/mm/aaaa] :");
        reset_cores();
        scanf("%d/%d/%d",&aux->p.Dia,&aux->p.Mes,&aux->p.Ano);
        valida = validaData(aux->p.Dia,aux->p.Mes,aux->p.Ano);
      } while (!valida);
      
      do {
        do { 
          blue();
          printf("\nHora do atendimento [00:00] :");
          reset_cores();
          scanf("%d:%d",&aux->p.Hora, &aux->p.Minuto);
          valida = validaHorario(aux->p.Hora,aux->p.Minuto);
        } while (!valida);

        if (aux->p.Minuto < 30 && aux->p.Minuto > 0) aux->p.Minuto = 0;
        else if (aux->p.Minuto >  30) aux->p.Minuto = 30;
        else opc = 1;

        if (opc != 1)
        {
          blue();
          printf("\nPoderia ser às %d:%d? [1: aceitar] [0: novo horário] :", aux->p.Hora, aux->p.Minuto);
          reset_cores();
          scanf("%d", &opc);
          blue();
        }

      } while (opc != 1);

      lp->inicio = aux;
      lp->fim = aux;
      aux->proximo = lp->inicio;
      aux->anterior = lp->fim;
      return 1;
  }

  aux->p.IDpaciente = incrementaIDpaciente(*lp);

  blue();
  printf("\nNome: ");
  reset_cores();
  scanf(" %30[^\n]",aux->p.Nome_paciente);
  getchar();

  blue();
  printf("\nIdade: ");
  reset_cores();
  scanf(" %10[^\n]",validaInt);
  aux->p.Idade = retornaInt(validaInt);

  blue();
  printf("\nTelefone 1: ");
  reset_cores();
  scanf(" %20[^\n]",aux->p.Telefone);
  getchar();

  blue();
  printf("\nCep: ");
  reset_cores();
  scanf(" %10[^\n]",aux->p.Cep);

  blue();
  printf("\nNumero: ");
  reset_cores();
  scanf(" %10[^\n]", validaInt);
  aux->p.Numero_casa = retornaInt(validaInt);

  blue();
  printf("\nResumo: ");
  reset_cores();
  scanf(" %150[^\n]",aux->p.Resumo);
  getchar();

  do{ 
  blue();
    printf("\nGravidade [1, 2 ou 3]: ");
  reset_cores();
    scanf("%d",&aux->p.Gravidade);
    if (aux->p.Gravidade == 1 ||
        aux->p.Gravidade == 2 ||
        aux->p.Gravidade == 3 )
        valida = 1;
    red();
    if (!valida) printf ("\nA gravidadade deve ser 1, 2 ou 3");
    reset_cores();
  } while (!valida);

  blue();
  printf("\nTelefone para contato de emergencia: ");
  reset_cores();
  scanf(" %20[^\n]",aux->p.Contato_emergencia);
  getchar();
  
  blue();
  printf("\nNome do contato de emergencia: ");
  reset_cores();
  scanf(" %30[^\n]",aux->p.Nome_contato_emergencia);
  getchar();

  do { 
    blue();
    printf("\nData do Atendimento [dd/mm/aaaa] :");
    reset_cores();
    scanf("%d/%d/%d",&aux->p.Dia,&aux->p.Mes,&aux->p.Ano);
    valida = validaData(aux->p.Dia,aux->p.Mes,aux->p.Ano);
  } while (!valida);
      
  do {
    do { 
      blue();
      printf("\nHora do atendimento [00:00] :");
      reset_cores();
      scanf("%d:%d",&aux->p.Hora, &aux->p.Minuto);
      valida = validaHorario(aux->p.Hora,aux->p.Minuto);
    } while (!valida);
    if (aux->p.Minuto < 30 && aux->p.Minuto > 0) aux->p.Minuto = 0;
    else if (aux->p.Minuto >  30) aux->p.Minuto = 30;
    else opc = 1;

    if (!comparaHorarios(aux->p.Dia,
      aux->p.Mes, aux->p.Ano,
      aux->p.Hora,aux->p.Minuto,
      aux->p.Gravidade, *lp, -1)){
        red();
        printf("\nJá temos um paciente com gravidade alta neste horário!");
        printf("\nFavor entrar com outro horário...");
        reset_cores();
        continue;
    }
    if (comparaHorarios(aux->p.Dia,
      aux->p.Mes, aux->p.Ano,
      aux->p.Hora,aux->p.Minuto,
      aux->p.Gravidade, *lp, -1)){
        red();
        printf("\nSabemos que seu atendimento é urgente!");
        printf("\nPor isso reagendamos outro paciente");
        reset_cores();
        opc = 1;
    }

    if (opc != 1)
    {
      blue();
      printf("\nPoderia ser às %d:%d? [1: aceitar] [0: novo horário] :", aux->p.Hora, aux->p.Minuto);
      reset_cores();
      scanf("%d", &opc);
      blue();
    }
  } while (opc != 1);

  printf("\n..............................\n");

  if(aux->p.Mes < lp->inicio->p.Mes)
  {
    aux->anterior = lp->fim;
    lp->fim->proximo = aux;
    aux->proximo = lp->inicio;
    lp->inicio->anterior = aux;
    lp->inicio = aux;
  }
  else if(aux->p.Mes > lp->inicio->p.Mes)
  {
    aux->anterior = lp->fim;
    lp->fim->proximo = aux;
    aux->proximo = lp->inicio;
    lp->inicio->anterior = aux;
    lp->fim = aux;
  }
  else if(aux->p.Mes == lp->inicio->p.Mes)
  {
    if(aux->p.Dia > lp->inicio->p.Dia)
    {
      aux->anterior = lp->fim;
      lp->fim->proximo = aux;
      aux->proximo = lp->inicio;
      lp->inicio->anterior = aux;
      lp->fim = aux;
    }
    else if(aux->p.Dia < lp->inicio->p.Dia)
    {
      aux->anterior = lp->fim;
      lp->fim->proximo = aux;
      aux->proximo = lp->inicio;
      lp->inicio->anterior = aux;
      lp->inicio = aux;
    }
    else if(aux->p.Dia == lp->inicio->p.Dia)
    {
      if(aux->p.Hora < lp->inicio->p.Hora)
      {
        aux->anterior = lp->fim;
        lp->fim->proximo = aux;
        aux->proximo = lp->inicio;
        lp->inicio->anterior = aux;
        lp->inicio = aux;
      }
      else if(aux->p.Hora > lp->inicio->p.Hora)
      {
        aux->anterior = lp->fim;
        lp->fim->proximo = aux;
        aux->proximo = lp->inicio;
        lp->inicio->anterior = aux;
        lp->fim = aux;
      }
      else if(aux->p.Hora == lp->inicio->p.Hora)
      {
        if(aux->p.Minuto < lp->inicio->p.Minuto)
        {
          aux->anterior = lp->fim;
          lp->fim->proximo = aux;
          aux->proximo = lp->inicio;
          lp->inicio->anterior = aux;
          lp->inicio = aux;
        }
        else if(aux->p.Minuto > lp->inicio->p.Minuto)
        {
          aux->anterior = lp->fim;
          lp->fim->proximo = aux;
          aux->proximo = lp->inicio;
          lp->inicio->anterior = aux;
          lp->fim = aux;
        }
      }
    }
  }
  return 1;
}

void mostraPacientes(listaPaciente lp)
{
    struct no *aux;

    blue();
    printf("\nLista de Pacientes\n");
    reset_cores();

    if (lp.inicio == NULL)
    {
        red();
        printf("\nLista vazia...\n");
        reset_cores();
    }

    else{
        aux = lp.inicio;

        do
        {
          printf("\n--ID: %d", aux->p.IDpaciente);
          if (aux->p.Gravidade == 1){
            red();
            printf("\nNome: %s *", aux->p.Nome_paciente);
            reset_cores();
          }
          else if (aux->p.Gravidade == 2){
            yellow();
            printf("\nNome: %s **", aux->p.Nome_paciente);
            reset_cores();
          }
          else{
            green();
            printf("\nNome: %s ***", aux->p.Nome_paciente);
            reset_cores();
          }

          printf("\nIdade:      %d", aux->p.Idade);
          printf("\nTelefone:   %s", aux->p.Telefone);
          printf("\nCep:        %s", aux->p.Cep);
          printf("\nNumero:     %d", aux->p.Numero_casa);
          printf("\nResumo:     %s", aux->p.Resumo);
          printf("\nContato de emergencia: %s", aux->p.Contato_emergencia);
          printf("\nNome do contato de emergencia: %s", aux->p.Nome_contato_emergencia);
          aux = aux->proximo;
          printf("\n.........................................\n");
        } while (aux != lp.inicio);
    }
}

void acessaAgenda(listaPaciente lp)
{
    struct no *aux;
    char Nome_mes[12][10] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    int i, ano;

    blue();
    printf("\nAgenda\n");
    reset_cores();

    if (lp.inicio == NULL)
    {
        blue();
        printf("\nAgenda vazia...\n");
        reset_cores();
    }

    else
    {
      printf("\nDigite o ano desejado [aaaa]: ");
      scanf("%d",&ano);

        for(i=0;i<12;i++)
        {
          aux = lp.inicio;
          if (aux->p.Ano == ano)
          {
            blue();
            printf("\n%s:\n",Nome_mes[i]);
            reset_cores();
            printf("\n.........................................\n");
            do
            {
                if(aux->p.Mes==i+1)
                {
                    printf("\nPaciente:    %s", aux->p.Nome_paciente);
                    printf("\nGravidade:   %d", aux->p.Gravidade);
                    printf("\nDia:         %d", aux->p.Dia);
                    printf("\nHorário:     %d:%d", aux->p.Hora, aux->p.Minuto);
                    printf("\nResumo:      %s", aux->p.Resumo);
                    printf("\n.........................................\n");
                }
                aux = aux->proximo;
            }while(aux!=lp.inicio);
          }
        }
    }
}

void mostraOcorrencias(listaPaciente lp){

    struct no *aux;
    int i;

    blue();
    printf("\nOcorrências\n");
    reset_cores();

    if (lp.inicio == NULL)
    {
        blue();
        printf("\nNão há ocorrências...\n");
        reset_cores();
    }

    else
    {
        for(i=1;i<=3;i++)
        {
          aux = lp.inicio;
          blue();
          if (i == 1) printf("\nGravidade Alta [Sem possibilidade de remarcação]:\n");
          if (i == 2) printf("\nGravidade Média [Pode ser remarcado diante da gravidade alta]\n");
          if (i == 3) printf("\nGravidade Baixa [Pode ser remarcado diante de qualquer incidente maior]\n");
          printf("\n.........................................\n");
          reset_cores();
            do
            {
                if(aux->p.Gravidade==i)
                {
                  if (i == 1) red();
                  if (i == 2) yellow();
                  if (i == 3) green();
                  printf("\nPaciente:    %s", aux->p.Nome_paciente);
                  printf("\nData:        %d/%d/%d", aux->p.Dia, aux->p.Mes, aux->p.Ano);
                  printf("\nHorário:     %d:%d", aux->p.Hora, aux->p.Minuto);
                  printf("\nResumo:      %s", aux->p.Resumo);
                  reset_cores();
                  printf("\n.........................................\n");
                }
                aux = aux->proximo;
            }while(aux!=lp.inicio);
        }
    }
}

int validaData(int dia, int mes, int ano){

  if (ano > 2019 && ano < 2024)
    if (mes < 13 && mes > 0){
      if (mes == 1  ||
          mes == 3  ||
          mes == 5  ||
          mes == 7  ||
          mes == 8  ||
          mes == 10 ||
          mes == 12){
        if (dia > 0 && dia < 32)
          return 1;
      }
      if (mes == 2 ||
          mes == 4 ||
          mes == 6 ||
          mes == 9 ||
          mes == 11){
        if (mes == 2 && (dia > 0 && dia < 30))
          return 1;
        if (dia > 0 && dia < 31)
          return 1;
      }
    }
  red();
  printf ("Data inválida! Digite novamente.");
  reset_cores();
  return 0;
}

int validaHorario(int hora, int minuto){

  if ((hora > 7 && hora < 12) || (hora > 12 && hora < 19))
    if (minuto > -1 && minuto < 60)
    {
      return 1;
    }

  red();
  printf ("Infelizmente não atendemos neste horário!\nEntre com um outro horário.");
  reset_cores();
  return 0;
}

int retornaInt(char *validaInt){

  int i, a = 1, result = 0, ok = 0;

  for (i = 0; i < 10; i++){
    if (validaInt[9-i] == '0'){
      result = result + (a * 0);
      ok = 1;
    }
    if (validaInt[9-i] == '1'){
      result = result + (a * 1);
      ok = 1;
    }
    if (validaInt[9-i] == '2'){
      result = result + (a * 2);
      ok = 1;
    }
    if (validaInt[9-i] == '3'){
      result = result + (a * 3);
      ok = 1;
    }
    if (validaInt[9-i] == '4'){
      result = result + (a * 4);
      ok = 1;
    }
    if (validaInt[9-i] == '5'){
      result = result + (a * 5);
      ok = 1;
    }
    if (validaInt[9-i] == '6'){
      result = result + (a * 6);
      ok = 1;
    }
    if (validaInt[9-i] == '7'){
      result = result + (a * 7);
      ok = 1;
    }
    if (validaInt[9-i] == '8'){
      result = result + (a * 8);
      ok = 1;
    }
    if (validaInt[9-i] == '9'){
      result = result + (a * 9);
      ok = 1;
    }
    if (ok){
       a = a * 10;
       if (a == 1) a = 0;
    }
    ok = 0;
  }
  return result;
}

void telaInicial()
{
system("clear");
red();
printf("      |________________________________\n");
printf("|-----|'''''|''''|''''|''''|''''|''''|'##\\|__\n");
printf("|- - -|  cc 6    5    4    3    2    1 ### __]==------------\n");
printf("|-----|________________________________##/|\n");
printf("      |''''''''''''''''''''''''''''''''''''\n");
red();
printf("\n      +  AGENDA MEDICA ELETRONICA  +\n");reset_cores();
}

void opcaoSobre()
{
  char *devs[] = {"André Fonseca de Paiva",
                  "Deborah Dalonso Frederico",
                  "Fernando Thales Pereira",
                  "Lucas Omar Andrade Leal"};
  
  char *profs[] = {"Joao Benedito",
                   "Claudio Correa"};
  pink();
  printf("Desenvolvido por\n"); reset_cores();
  for (int i = 0; i < 4; i++)
  { white();
    printf(" - %s\n",devs[i]);
  }

  printf("\n");

  pink();
  printf("Orientado por\n"); reset_cores();
  for (int i = 0; i < 4; i++)
  { white();
    printf(" - %s\n",profs[i]);
  }

  printf("\n");

  pink();
  printf("O projeto\n"); reset_cores();
  printf("  Projeto final referente à criação de uma aplicação\n  voltada ao cenário automatizado de agendamento de consultas\n  tendo como base a gravidade e necessidade de atendimento ao paciente\n\n");
}

int incrementaIDpaciente(listaPaciente lp){

  struct no *aux;
  aux = lp.inicio;
  int id = 1;

  do
  {
    aux = aux->proximo;
    id++;
  } while (aux != lp.inicio);

  return id;
}

int comparaHorarios(int dia, int mes, int ano,
                    int hora, int minuto, int gravidade, listaPaciente lp, int id)
{

  struct no *aux;
  int auxId;

  aux = lp.inicio;
  do
  {
      if(dia    == aux->p.Dia &&
         mes    == aux->p.Mes &&
         ano    == aux->p.Ano &&
         hora   == aux->p.Hora &&
         minuto == aux->p.Minuto)
      {
        auxId = aux->p.IDpaciente;

        if (aux->p.Gravidade <= gravidade){
          return 0;
        }
        if (aux->p.Gravidade > gravidade){
          
          do {

            if (auxId != id){
              if (aux->p.Minuto == 30){
                aux->p.Minuto = 0;
                aux->p.Hora++;
              }
              else if (aux->p.Minuto == 0) aux->p.Minuto = 30;
              comparaHorarios(aux->p.Dia, aux->p.Mes, aux->p.Ano,
                    aux->p.Hora, aux->p.Minuto, aux->p.Gravidade,
                    lp, aux->p.IDpaciente);
            }
            aux = aux->proximo;
          } while (aux!=lp.inicio);

          return 1;
        }

      }
      aux = aux->proximo;
      
  }while(aux!=lp.inicio);

  return -1;

}

int insereListaFake(listaPaciente *lp, int a){
  
  struct no *aux;
  aux = (struct no*) malloc(sizeof(struct no));
  if (aux == NULL) return 0;

  if (lp->inicio == NULL)
  {   
    aux->p.IDpaciente = 1;
    strcpy(aux->p.Nome_paciente, "José da Silva");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 1;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Maria da Silva");
    aux->p.Dia = 15;
    aux->p.Mes = 12;
    aux->p.Ano = 2021;
    aux->p.Hora = 8;
    aux->p.Minuto = 0;

    lp->inicio = aux;
    lp->fim = aux;
    aux->proximo = lp->inicio;
    aux->anterior = lp->fim;
    return 1;
  }

  if (a == 1){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Lyana Lameira Peixoto");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 2;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Adriana Damasceno Pureza");
    aux->p.Dia = 15;
    aux->p.Mes = 10;
    aux->p.Ano = 2021;
    aux->p.Hora = 8;
    aux->p.Minuto = 30;
  }
  else if (a == 2){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Lueji Moreira Amoedo");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 3;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Petra Robalo Belém");
    aux->p.Dia = 15;
    aux->p.Mes = 9;
    aux->p.Ano = 2021;
    aux->p.Hora = 9;
    aux->p.Minuto = 30;
  }
  else if (a == 3){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Anita Antas Carvalhoso");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 1;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Stéphanie Sequeira Quirino");
    aux->p.Dia = 15;
    aux->p.Mes = 7;
    aux->p.Ano = 2021;
    aux->p.Hora = 9;
    aux->p.Minuto = 30;
  }
  else if (a == 4){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Caetano Cerqueira Ferrão");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 2;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Daniela Carrasco Faia");
    aux->p.Dia = 15;
    aux->p.Mes = 7;
    aux->p.Ano = 2021;
    aux->p.Hora = 10;
    aux->p.Minuto = 0;
  }
  else if (a == 5){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Santhiago Onofre Lins");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 3;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Camilo Vides Mascarenhas");
    aux->p.Dia = 15;
    aux->p.Mes = 5;
    aux->p.Ano = 2021;
    aux->p.Hora = 9;
    aux->p.Minuto = 30;
  }
  else if (a == 6){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Dominique Alvim Pontes");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 1;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Brayan Breia Quinteiro");
    aux->p.Dia = 15;
    aux->p.Mes = 4;
    aux->p.Ano = 2021;
    aux->p.Hora = 9;
    aux->p.Minuto = 30;
  }
  else if (a == 7){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Aline Vieira");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 2;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Mirian Estrela Boga");
    aux->p.Dia = 15;
    aux->p.Mes = 3;
    aux->p.Ano = 2021;
    aux->p.Hora = 9;
    aux->p.Minuto = 30;
  }
  else if (a == 8){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Afonso Bivar Adão");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 3;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Liany Novais Ferraço");
    aux->p.Dia = 15;
    aux->p.Mes = 3;
    aux->p.Ano = 2021;
    aux->p.Hora = 10;
    aux->p.Minuto = 0;
  }
  else if (a == 9){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Dilnura Escobar Barrocas");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 2;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Breno Campos Salomão");
    aux->p.Dia = 15;
    aux->p.Mes = 3;
    aux->p.Ano = 2021;
    aux->p.Hora = 10;
    aux->p.Minuto = 30;
  }
  else if (a == 10){
    aux->p.IDpaciente = incrementaIDpaciente(*lp);
    strcpy(aux->p.Nome_paciente, "Amira Camilo Garrido");
    aux->p.Idade = 20;
    strcpy(aux->p.Telefone,"(35) 1234-5678");
    strcpy(aux->p.Cep,"37701-000");
    aux->p.Numero_casa = 20;
    strcpy(aux->p.Resumo, "Encontra-se enfermo");
    aux->p.Gravidade = 2;
    strcpy(aux->p.Contato_emergencia,"(35) 1234-5678");
    strcpy(aux->p.Nome_contato_emergencia, "Gelson Casado Portugal");
    aux->p.Dia = 15;
    aux->p.Mes = 2;
    aux->p.Ano = 2021;
    aux->p.Hora = 9;
    aux->p.Minuto = 30;
  }

  if(aux->p.Mes < lp->inicio->p.Mes)
  {
    aux->anterior = lp->fim;
    lp->fim->proximo = aux;
    aux->proximo = lp->inicio;
    lp->inicio->anterior = aux;
    lp->inicio = aux;
  }
  else if(aux->p.Mes > lp->inicio->p.Mes)
  {
    aux->anterior = lp->fim;
    lp->fim->proximo = aux;
    aux->proximo = lp->inicio;
    lp->inicio->anterior = aux;
    lp->fim = aux;
  }
  else if(aux->p.Mes == lp->inicio->p.Mes)
  {
    if(aux->p.Dia > lp->inicio->p.Dia)
    {
      aux->anterior = lp->fim;
      lp->fim->proximo = aux;
      aux->proximo = lp->inicio;
      lp->inicio->anterior = aux;
      lp->fim = aux;
    }
    else if(aux->p.Dia < lp->inicio->p.Dia)
    {
      aux->anterior = lp->fim;
      lp->fim->proximo = aux;
      aux->proximo = lp->inicio;
      lp->inicio->anterior = aux;
      lp->inicio = aux;
    }
    else if(aux->p.Dia == lp->inicio->p.Dia)
    {
      if(aux->p.Hora < lp->inicio->p.Hora)
      {
        aux->anterior = lp->fim;
        lp->fim->proximo = aux;
        aux->proximo = lp->inicio;
        lp->inicio->anterior = aux;
        lp->inicio = aux;
      }
      else if(aux->p.Hora > lp->inicio->p.Hora)
      {
        aux->anterior = lp->fim;
        lp->fim->proximo = aux;
        aux->proximo = lp->inicio;
        lp->inicio->anterior = aux;
        lp->fim = aux;
      }
      else if(aux->p.Hora == lp->inicio->p.Hora)
      {
        if(aux->p.Minuto < lp->inicio->p.Minuto)
        {
          aux->anterior = lp->fim;
          lp->fim->proximo = aux;
          aux->proximo = lp->inicio;
          lp->inicio->anterior = aux;
          lp->inicio = aux;
        }
        else if(aux->p.Minuto > lp->inicio->p.Minuto)
        {
          aux->anterior = lp->fim;
          lp->fim->proximo = aux;
          aux->proximo = lp->inicio;
          lp->inicio->anterior = aux;
          lp->fim = aux;
        }
      }
    }
  }
  

  return 1;
}