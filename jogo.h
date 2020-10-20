<<<<<<< HEAD
#ifndef JOGO_H
#define JOGO_H

=======
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
struct personagem{
=======
#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct personagem
{
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2
    char nomePersonagem[21];
    int pontoVida;
    int pontoForca;
    int pontoDefesa;
    int pontoVelocidade;
<<<<<<< HEAD
};

typedef struct personagem Personagem;

struct lst{
    Personagem* info;
    struct lst* prox;
};

typedef struct lst Lista;

Lista* inicializa (void);
void entradaPersonagem(Lista* p);
Lista* alocaPersonagem(Lista* l, char* nick);
void imprimePersonagem(Lista* l);
=======
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
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2

#endif