#ifndef ITENS_H
#define ITENS_H
#include <stdio.h>
#include "jogo.h"

typedef struct itens
{
    int dano;
    int armadura;
    int velocidade;
    int vida;
} ITENS;

typedef struct lstI
{
    ITENS *info;
    struct lstH *prox;
} ListaI;

#endif