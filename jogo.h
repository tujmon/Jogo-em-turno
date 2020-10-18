#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct personagem
{
    char nomePersonagem[21];
    int pontoVida;
    int pontoForca;
    int pontoDefesa;
    int pontoVelocidade;
} Personagem;

typedef struct lst
{
    Personagem *info;
    struct lst *prox;
} Lista;

void entradaPersonagem(Lista *p);
void imprimePersonagem(Lista *l);
Lista *alocaPersonagem(Lista *l, char *nick);
Lista *inicializa(void);

#endif