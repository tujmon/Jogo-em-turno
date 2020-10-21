#include "mob.h"

ListaM *alocaMOB(ListaM *lst)
{
    Personagem *p = (Personagem *)malloc(sizeof(Personagem));
    ListaM *l = (ListaM *)malloc(sizeof(ListaM));

    strcpy(p->nomePersonagem, "Lobo-Guará");
    p->pontoForca = 10;
    p->pontoDefesa = 0;
    p->pontoVelocidade = rand() % 5;
    p->pontoVida = 100;

    l->info = p;
    l->prox = lst;

    return l;
}

void imprimeMOB(ListaM *l)
{
    ListaM *p;
    ListaM *q = l;
    puts("");
    for (p = l, q = l; p != NULL; p = p->prox, q = q->prox)
    {
        printf("| %s |", q->info->nomePersonagem);
        printf(" Defesa: %d | Força: %d | Velocidade: %d | Vida: %d |", q->info->pontoDefesa, q->info->pontoForca, q->info->pontoVelocidade, q->info->pontoVida);
        puts("\n");
    }
}
ListaM *inicializaM(void)
{
    return NULL;
}