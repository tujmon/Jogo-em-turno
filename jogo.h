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

/*typedef struct mob
{
    char nomeMob[21];
    int pontoVida;
    int pontoForca;
    int pontoDefesa;
    int pontoVelocidade;

} MOB;*/
void imprimePersonagem(Lista *l);
Lista *alocaPersonagem(Lista *l, char *nick);
Lista *inicializa(void);

#endif