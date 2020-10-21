#include "fila.h"

void insere_Fila(FILA *a, int b)
{
    if (incrementa(a->fim) == a->ini)
    {
        printf("Capacidade da fila estourou.\n");
        exit(1);
    }
    a->vet[a->fim] = b;
    a->fim = incrementa(a->fim);
}

int retira_Fila(FILA *a)
{
    int v;
    if (vazia(a))
    {
        printf("Fila vazia.\n");
        exit(1);
    }
    v = a->vet[a->ini];
    a->ini = incrementa(a->ini);
    return v;
}

FILA *inicializa_Fila(void)
{
    FILA *f = (FILA *)malloc(sizeof(FILA));
    f->ini = f->fim = 0;
    return f;
}

int incrementa(int i)
{
    return (i + 1) % N;
}

int vazia(FILA *a)
{
    return (a->ini == a->fim);
}