#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personagem
{
    char nomePersonagem[21];
    int pontoVida;
    int pontoForca;
    int pontoDefesa;
    int pontoVelocidade;
};

typedef struct personagem Personagem;

struct lstH
{
    Personagem *info;
    struct lstH *prox;
};

typedef struct lstH ListaH;

void entradaPersonagem(ListaH *p);
ListaH *alocaPersonagem(ListaH *l, char *nick);
void imprimePersonagem(ListaH *l);
ListaH *inicializaH(void);

#endif