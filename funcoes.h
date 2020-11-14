//TRABALHO C
//FUNÇÕES
//18/10
//DEBORAH
//10/11
//DEBORAH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"
#include "cores.h"

int validaData(int, int, int);
int validaHorario(int, int);
int retornaInt(char *);

void pause()
{
    printf("\nTecle enter para continuar....\n");
    getchar(); getchar();
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
    for (int i = 0; i < 10; i++) validaInt[i] = 'x';

    aux = (struct no*) malloc(sizeof(struct no));

    if (aux == NULL) return 0;

    printf("\n..............................\n");
    printf("\n\tMarcar Consulta\n");
    printf("\n..............................\n");

    if (lp->inicio == NULL)
    {
        printf("\nNome: ");
        scanf(" %30[^\n]",aux->p.Nome_paciente);
        getchar();

        /* a função retornaInt recebe um vetor e
        retorna um INT com os valores. Para caso o usuário
        escape um caracter na digitação        
        */
        printf("\nIdade: "); // ANDRE: validação de entrada de INT
        scanf(" %10[^\n]",validaInt);
        aux->p.Idade = retornaInt(validaInt);

        printf("\nTelefone 1: ");
        scanf(" %20[^\n]",aux->p.Telefone);
        getchar();

        printf("\nCep: ");
        scanf(" %10[^\n]",aux->p.Cep);

        printf("\nNumero: "); // ANDRE: validação de entrada de INT
        scanf(" %10[^\n]", validaInt);
        aux->p.Numero_casa = retornaInt(validaInt);

        printf("\nResumo: ");
        scanf(" %150[^\n]",aux->p.Resumo);
        getchar();

        do{ // ANDRE: validação
          printf("\nGravidade [1, 2 ou 3]: ");
          scanf("%d",&aux->p.Gravidade);
          if (aux->p.Gravidade == 1 ||
              aux->p.Gravidade == 2 ||
              aux->p.Gravidade == 3 )
              valida = 1;
          red();
          if (!valida) printf ("\nA gravidadade deve ser 1, 2 ou 3");
          reset_cores();
        } while (!valida);

        printf("\nTelefone para contato de emergencia: ");
        scanf(" %20[^\n]",aux->p.Contato_emergencia);
        getchar();

        printf("\nNome do contato de emergencia: ");
        scanf(" %30[^\n]",aux->p.Nome_contato_emergencia);
        getchar();

        do { // ANDRE: validacao da entrada - ver funcao validaData()
          printf("\nData do Atendimento [dd/mm/aaaa] :");
          scanf("%d/%d/%d",&aux->p.Dia,&aux->p.Mes,&aux->p.Ano);
          valida = validaData(aux->p.Dia,aux->p.Mes,aux->p.Ano);
        } while (!valida);
        
        do { // ANDRE: validacao da entrada - ver funcao validaHorario()
          printf("\nHora do atendimento [00:00] :");
          scanf("%d:%d",&aux->p.Hora, &aux->p.Minuto);
          valida = validaHorario(aux->p.Hora,aux->p.Minuto);
        } while (!valida);
        printf("\n..............................\n");

        lp->inicio = aux;
        lp->fim = aux;
        aux->proximo = lp->inicio;
        aux->anterior = lp->fim;
        return 1;
    }
    printf("\nNome: ");
    scanf(" %30[^\n]",aux->p.Nome_paciente);
    getchar();

    printf("\nIdade: ");
    scanf(" %10[^\n]",validaInt);
    aux->p.Idade = retornaInt(validaInt);

    printf("\nTelefone 1: ");
    scanf(" %20[^\n]",aux->p.Telefone);
    getchar();

    printf("\nCep: ");
    scanf(" %10[^\n]",aux->p.Cep);

    printf("\nNumero: ");
    scanf(" %10[^\n]", validaInt);
    aux->p.Numero_casa = retornaInt(validaInt);

    printf("\nResumo: ");
    scanf(" %150[^\n]",aux->p.Resumo);
    getchar();

    do{ // ANDRE: validação
      printf("\nGravidade [1, 2 ou 3]: ");
      scanf("%d",&aux->p.Gravidade);
      if (aux->p.Gravidade == 1 ||
          aux->p.Gravidade == 2 ||
          aux->p.Gravidade == 3 )
          valida = 1;
      red();
      if (!valida) printf ("\nA gravidadade deve ser 1, 2 ou 3");
      reset_cores();
    } while (!valida);

    printf("\nTelefone para contato de emergencia: ");
    scanf(" %20[^\n]",aux->p.Contato_emergencia);
    getchar();
    
    printf("\nNome do contato de emergencia: ");
    scanf(" %30[^\n]",aux->p.Nome_contato_emergencia);
    getchar();

    printf("\nData do Atendimento [dd/mm/aaaa]: ");
    scanf("%d/%d/%d",&aux->p.Dia,&aux->p.Mes,&aux->p.Ano);

    printf("\nHora do atendimento [00:00]: ");
    scanf("%d:%d",&aux->p.Hora, &aux->p.Minuto);
    printf("\n..............................\n");

    //POR DEBORAH: esta ordenando por data... foi mexer para ordenar pelo grau também
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
                printf("\nHorario ja ocupado, marque outro queridinho\n");
            }
        }
    }

    return 1;
}

void mostraPacientes(listaPaciente lp)
{
    struct no *aux;

    printf("\n..............................\n");
    printf("\n\tLista de Pacientes\n");
    printf("\n..............................\n");

    if (lp.inicio == NULL)
    {
        printf("\nLista vazia...\n");
        printf("\n..............................\n");
    }

    else{
        aux = lp.inicio;

        do
        {
            if (aux->p.Gravidade == 1) printf("\nNome: %s *", aux->p.Nome_paciente);
            else if (aux->p.Gravidade == 2) printf("\nNome: %s **", aux->p.Nome_paciente);
            else printf("\nNome: %s ***", aux->p.Nome_paciente);
            printf("\nIdade:      %d", aux->p.Idade);
            printf("\nTelefone:   %s", aux->p.Telefone);
            printf("\nCep:        %s", aux->p.Cep);
            printf("\nNumero:     %d", aux->p.Numero_casa);
            printf("\nResumo: %s", aux->p.Resumo);
            //printf("\nGravidade:  %d", aux->p.Gravidade); para teste
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
    int i;

    printf("\n..............................\n");
    printf("\n\tAgenda\n");
    printf("\n..............................\n");

    if (lp.inicio == NULL)
    {
        printf("\nAgenda vazia...\n");
        printf("\n..............................\n");
    }

    //POR DEBORAH: vou mexer depois nos meses que não tem nada marcado
    else
    {
        for(i=0;i<12;i++)
        {
            aux = lp.inicio;
            printf("\n%s:\n",Nome_mes[i]);
            printf("\n.........................................\n");
                do
                {
                    if(aux->p.Mes==i+1)
                    {
                        printf("\nPaciente:    %s", aux->p.Nome_paciente);
                        printf("\nGravidade:   %d", aux->p.Gravidade);
                        printf("\nData:        %d/%d/%d", aux->p.Dia, aux->p.Mes, aux->p.Ano);
                        printf("\nHorário:     %d:%d", aux->p.Hora, aux->p.Minuto);
                        printf("\nResumo: %s", aux->p.Resumo);
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
  printf ("Data inválida, se liga colega, digite novamente");
  reset_cores();
  return 0;
}

int validaHorario(int hora, int minuto){

  if (hora > -1 && hora < 24)
    if (minuto > -1 && minuto < 60)
      return 1;

  red();
  printf ("Horário inválido, com atenção você consegue");
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