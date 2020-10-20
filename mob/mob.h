#include <stdio.h>
#include "../jogo/jogo.h"
#ifndef MOB_H
#define MOB_H

struct lstM
{
    Personagem *info;
    struct lstM *prox;
};
typedef struct lstM ListaM;

void imprimeMOB(ListaM *l);
ListaM *alocaMOB(ListaM *lst);
ListaH *inicializaM(void);
#endif