#include "jogo.h"

<<<<<<< HEAD


Lista* alocaPersonagem(Lista* lst, char* nick){
    Personagem* p = (Personagem*) malloc(sizeof(Personagem));
    Lista* l = (Lista*) malloc(sizeof(Lista));

    strcpy(p->nomePersonagem, nick);
    p->pontoForca = 5; 
    p->pontoDefesa = 5;
    p->pontoVelocidade = 3;
    p->pontoVida = 100;   
=======
Lista *alocaPersonagem(Lista *lst, char *nick)
{
    Personagem *p = (Personagem *)malloc(sizeof(Personagem));
    Lista *l = (Lista *)malloc(sizeof(Lista));

    strcpy(p->nomePersonagem, nick);
    p->pontoForca = 5;
    p->pontoDefesa = 5;
    p->pontoVelocidade = 3;
    p->pontoVida = 100;
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2

    l->info = p;
    l->prox = lst;

    return l;
}

<<<<<<< HEAD


void imprimePersonagem(Lista* l){
    Lista* p;
    while(p != NULL){
        printf("Nome do Personagem: %s\nDefesa: %d\nForça: %d\nVelocidade: %d\nVida: %d", l->info->nomePersonagem, l->info->pontoDefesa, l->info->pontoForca, l->info->pontoVelocidade, l->info->pontoVida);
=======
void imprimePersonagem(Lista *l)
{
    Lista *p;
    while (p != NULL)
    {
        printf("Nome do Personagem: %s\n"
               "Defesa: %d\n"
               "Força: %d\n"
               "Velocidade: %d\n"
               "Vida: %d",
               l->info->nomePersonagem, l->info->pontoDefesa, l->info->pontoForca, l->info->pontoVelocidade, l->info->pontoVida);
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2
        puts("\n");
        p = p->prox;
        l = l->prox;
    }
}