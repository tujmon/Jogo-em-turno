#include "jogo.h"

void batalha(ListaH *hero, ListaM *mob)
{
    int a;
    while (hero != NULL)
    {
        puts("escolha:");
        puts("1 - ataque");
        puts("2 - fugir");
        puts("3 - defesa");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if (hero->info->pontoVida <= 0)
            {
                hero = hero->prox;
            }
            if (mob->info->pontoVida <= 0)
            {
                return;
            }
            FILA *a = enfilera_ataque(hero, mob);
            partida(hero, mob, a);
            break;
        case 2:
            // fazer uma chance para fugir;
            if (rand() % 100 >= 70)
            {
                puts("você conseguiu escapar");
            }
            else
            {
                hero->info->pontoVida -= mob->info->pontoForca;
            }
            break;
        case 3:

            hero->info->pontoDefesa += (int)(rand() % 25);
            printf("novo ponto de defesa: %d", hero->info->pontoDefesa); /*fazer algo baseado na sorte para adiquirir defesa*/
            break;

        default:
            puts("valor digitado incorreto, digite novamente:");
            break;
        }
    }
}

FILA *enfilera_ataque(ListaH *hero, ListaM *mob)
{
    FILA *a = inicializa_Fila();
    if (hero->info->pontoVelocidade > mob->info->pontoVelocidade)
    {

        insere_Fila(a, hero->info->pontoForca);
        insere_Fila(a, mob->info->pontoForca);
    }
    else
    {
        insere_Fila(a, mob->info->pontoForca);
        insere_Fila(a, hero->info->pontoForca);
    }
    return a;
}

void partida(ListaH *hero, ListaM *mob, FILA *a)
{
    int vida_total = hero->info->pontoVida + hero->info->pontoDefesa;
    int vida_total2 = hero->info->pontoVida + hero->info->pontoDefesa;
    if (hero->info->pontoVelocidade > mob->info->pontoVelocidade && mob->info->pontoDefesa > 0)
    {
        vida_total2 -= retira_Fila(a);
        if (vida_total2 >= mob->info->pontoVida)
        {
            mob->info->pontoDefesa = (vida_total2 - mob->info->pontoVida);
        }
        else if (vida_total2 <= mob->info->pontoVida)
        {
            mob->info->pontoVida = vida_total2;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
        vida_total -= retira_Fila(a);
        if (vida_total2 >= hero->info->pontoVida)
        {
            hero->info->pontoDefesa = (vida_total2 - hero->info->pontoVida);
        }
        else if (vida_total2 <= hero->info->pontoVida)
        {
            hero->info->pontoVida = vida_total2;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
    }
    else
    {
        vida_total -= retira_Fila(a);
        if (vida_total2 >= hero->info->pontoVida)
        {
            hero->info->pontoDefesa = (vida_total2 - hero->info->pontoVida);
        }
        else if (vida_total2 <= hero->info->pontoVida)
        {
            hero->info->pontoVida = vida_total2;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
        vida_total2 -= retira_Fila(a);
        if (vida_total2 >= mob->info->pontoVida)
        {
            mob->info->pontoDefesa = (vida_total2 - mob->info->pontoVida);
        }
        else if (vida_total2 <= mob->info->pontoVida)
        {
            mob->info->pontoVida = vida_total2;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
    }
}
//imprime mob
//mover função de inicialização para os lugares corretos