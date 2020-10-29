#include "personagem.h"

ListaH *alocaPersonagem(ListaH *lst, char *nick)
{
    Personagem *p = (Personagem *)malloc(sizeof(Personagem));
    ListaH *l = (ListaH *)malloc(sizeof(ListaH));

    strcpy(p->nomePersonagem, nick);
    p->pontoForca = 5;
    p->pontoDefesa = 5;
    p->pontoVelocidade = 3;
    p->pontoVida = 100;

    l->info = p;
    l->prox = lst;

    return l;
}

void imprimePersonagem(ListaH *l)
{
    ListaH *p;
    ListaH *q = l;
    puts("");
    for (p = l, q = l; p != NULL; p = p->prox, q = q->prox)
    {
        printf("| %s |", q->info->nomePersonagem);
        printf(" Defesa: %d | Força: %d | Velocidade: %d | Vida: %d |", q->info->pontoDefesa, q->info->pontoForca, q->info->pontoVelocidade, q->info->pontoVida);
        puts("\n");
    }
}

ListaH *inicializaH(void)
{
    return NULL;
}
