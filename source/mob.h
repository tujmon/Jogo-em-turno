#ifndef MOB_H
#define MOB_H

#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

struct lstM
{
    Personagem *info;
    struct lstM *prox;
};
typedef struct lstM ListaM;

void imprimeMOB(ListaM *l);
ListaM *alocaMOB(ListaM *lst);
ListaM *inicializaM(void);

#endif