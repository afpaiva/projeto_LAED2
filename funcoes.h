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

int validaData(int, int, int);
int validaHorario(int, int);

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

        printf("\nIdade: ");
        scanf("%d",&aux->p.Idade);

        printf("\nTelefone 1: ");
        scanf(" %20[^\n]",aux->p.Telefone);
        getchar();

        printf("\nCep: ");
        scanf("%d",&aux->p.Cep);

        printf("\nNumero: ");
        scanf("%d",&aux->p.Numero_casa);

        printf("\nResumo: ");
        scanf(" %150[^\n]",aux->p.Resumo);
        getchar();

        printf("\nGravidade: ");
        scanf("%d",&aux->p.Gravidade);

        printf("\nTelefone para contato de emergencia: ");
        scanf(" %20[^\n]",aux->p.Contato_emergencia);
        getchar();

        printf("\nNome do contato de emergencia: ");
        scanf(" %30[^\n]",aux->p.Nome_contato_emergencia);
        getchar();

        do { // ANDRE: validacao de data - ver funcao validaData()
          printf("\nData do Atendimento [dd/mm/aaaa] :");
          scanf("%d/%d/%d",&aux->p.Dia,&aux->p.Mes,&aux->p.Ano);
          valida = validaData(aux->p.Dia,aux->p.Mes,aux->p.Ano);
        } while (!valida);
        
        do {
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
    scanf("%d",&aux->p.Idade);

    printf("\nTelefone 1: ");
    scanf(" %20[^\n]",aux->p.Telefone);
    getchar();

    printf("\nCep: ");
    scanf("%d",&aux->p.Cep);

    printf("\nNumero: ");
    scanf("%d",&aux->p.Numero_casa);

    printf("\nResumo: ");
    scanf(" %150[^\n]",aux->p.Resumo);
    getchar();

    printf("\nGravidade: ");
    scanf("%d",&aux->p.Gravidade);

    printf("\nTelefone para contato de emergencia: ");
    scanf(" %20[^\n]",aux->p.Contato_emergencia);
    getchar();
    
    printf("\nNome do contato de emergencia: ");
    scanf(" %30[^\n]",aux->p.Nome_contato_emergencia);
    getchar();

    printf("\nData do Atendimento [dd/mm/aaaa] :");
    scanf("%d/%d/%d",&aux->p.Dia,&aux->p.Mes,&aux->p.Ano);

    printf("\nHora do atendimento [00:00] :");
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
            printf("\nCep:        %d", aux->p.Cep);
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
  printf ("Data inválida");
  return 0;
}

int validaHorario(int hora, int minuto){
  
}