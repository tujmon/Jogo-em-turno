#ifndef MOB_H
#define MOB_H

//funções
#include <stdio.h>
#include "jogo.h"

//struct
struct lstM
{
    Personagem *info;
    struct lstM *prox;
};
typedef struct lstM ListaM;

//funções
void imprimeMOB(ListaM *l);
ListaM *alocaMOB(ListaM *lst);
ListaM *inicializaM(void);

#endif