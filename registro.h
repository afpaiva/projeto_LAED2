//TRABALHO C
//REGISTRO
//18/10
//DEBORAH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LISTA DE PACIENTES

typedef struct
{
    char Nome_paciente[30];
    int Idade;
    int Telefone;
    int Cep;
    int Numero_casa;
    char Resumo[150];
    int Gravidade;
    int Contato_emergencia;
    char Nome_contato_emergencia[30];
    int Dia;
    int Mes;
    int Ano;
    int Hora;
    int Minuto;

} Paciente;

struct no
{
    struct no *anterior;
    Paciente p;
    struct no *proximo;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;

} listaPaciente;

// PILHA DE OCORRÊNCIAS

struct noPOcorrencia
{
    int dado;
    struct noPOcorrencia *proximo;
};

typedef struct
{
    struct noPOcorrencia *topo;
} pilhaOcorrencia;
