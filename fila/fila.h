#include <stdio.h>
#include "../jogo/jogo.h"

#ifndef FILA_H
#define FILA_H

#define N 20

typedef struct fila
{
    int ini, fim;
    float vet[N];
} FILA;

int retira_Fila(FILA *a);
int incrementa(int i);
FILA *inicializa_Fila(void);
void insere_Fila(FILA *a, int b);
int vazia(FILA *a);

#endif