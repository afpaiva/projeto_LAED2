#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LISTA DE PACIENTES */

typedef struct
{
    char Nome_paciente[30];
    int Idade;
    char Telefone[20];
    char Cep[10];
    int Numero_casa;
    char Resumo[150];
    int Gravidade;
    char Contato_emergencia[20];
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
