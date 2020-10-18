#include "jogo.h"

Lista *alocaPersonagem(Lista *lst, char *nick)
{
    Personagem *p = (Personagem *)malloc(sizeof(Personagem));
    Lista *l = (Lista *)malloc(sizeof(Lista));

    strcpy(p->nomePersonagem, nick);
    p->pontoForca = 5;
    p->pontoDefesa = 5;
    p->pontoVelocidade = 3;
    p->pontoVida = 100;

    l->info = p;
    l->prox = lst;

    return l;
}

void imprimePersonagem(Lista *l)
{
    Lista *p;
    while (p != NULL)
    {
        printf("Nome do Personagem: %s\nDefesa: %d\nForça: %d\nVelocidade: %d\nVida: %d", l->info->nomePersonagem, l->info->pontoDefesa, l->info->pontoForca, l->info->pontoVelocidade, l->info->pontoVida);
        puts("\n");
        p = p->prox;
        l = l->prox;
    }
}