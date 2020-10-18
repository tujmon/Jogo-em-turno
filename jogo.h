#ifndef JOGO_H
#define JOGO_H

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

struct lst
{
    Personagem *info;
    struct lst *prox;
};

typedef struct lst Lista;

Lista *inicializa(void);
void entradaPersonagem(Lista *p);
Lista *alocaPersonagem(Lista *l, char *nick);
void imprimePersonagem(Lista *l);

#endif