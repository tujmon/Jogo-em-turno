#include "jogo.h"

Lista *inicializa(void)
{
    return NULL;
}

void Batalha(Lista *a, Lista *b)
{
    int ponto_total1 = a->info->pontoVida * a->info->pontoDefesa;
    int ponto_total2 = b->info->pontoVida * b->info->pontoDefesa;
    if (a->info->pontoVelocidade > b->info->pontoVelocidade)
    {
        // a ataca primeiro
    }
    else
    {
        // b ataca primeiro
    }
}