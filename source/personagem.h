#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personagem
{
    int nivel;
    char nomePersonagem[21];
    int pontoVida;
    int pontoForca;
    int pontoDefesa;
    int pontoVelocidade;
} Personagem;

typedef struct lstH
{
    Personagem *info;
    struct lstH *prox;
} ListaH;

void entradaPersonagem(ListaH *p);
ListaH *alocaPersonagem(ListaH *l, char *nick);
void imprimePersonagem(ListaH *l);
ListaH *inicializaH(void);

#endif