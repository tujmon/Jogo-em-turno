#include "jogo.h"

void batalha(ListaH *hero, ListaM *mob)
{
    int a;
    while (hero != NULL)
    {
        puts("escolha:");
        puts("1 - Ataque");
        puts("2 - Fugir");
        puts("3 - Defesa");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {
            if (hero->info->pontoVida <= 0)
            {
                hero = hero->prox;
            }
            if (mob->info->pontoVida <= 0)
            {
                exit(1);
            }
            FILA *a = enfilera_ataque(hero, mob);
            partida(hero, mob, a);
            break;
        }
        case 2:
            // [0,1)
            if (rand() % 2 == 1)
            {
                puts("Você conseguiu escapar 'HEROI'. UFA!");
                exit(1);
            }
            else
            {
                //segmentation fault
                hero->info->pontoVida -= mob->info->pontoForca;
                printf("Você falhou em fugir. TOMA ESSA!!\n-%d de Vida", mob->info->pontoForca);

                imprimePersonagem(hero);
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
    int vida_total_heroi = hero->info->pontoVida + hero->info->pontoDefesa;
    int vida_total_mob = mob->info->pontoVida + mob->info->pontoDefesa;
    if (hero->info->pontoVelocidade > mob->info->pontoVelocidade)
    {
        vida_total_mob -= retira_Fila(a);
        if (vida_total_mob >= mob->info->pontoVida)
        {
            mob->info->pontoDefesa = (vida_total_mob - mob->info->pontoVida);
        }
        else if (vida_total_mob <= mob->info->pontoVida)
        {
            mob->info->pontoVida = vida_total_mob;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
        printf("to aqui1");
        vida_total_heroi -= retira_Fila(a);
        if (vida_total_heroi >= hero->info->pontoVida)
        {
            hero->info->pontoDefesa = (vida_total_heroi - hero->info->pontoVida);
        }
        else if (vida_total_heroi <= hero->info->pontoVida)
        {
            hero->info->pontoVida = vida_total_heroi;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
        printf("to aqui2");
    }
    else
    {
        vida_total_heroi -= retira_Fila(a);

        if (vida_total_heroi >= hero->info->pontoVida)
        {
            hero->info->pontoDefesa = (vida_total_heroi - hero->info->pontoVida);
        }
        else if (vida_total_heroi <= hero->info->pontoVida)
        {
            hero->info->pontoVida = vida_total_heroi;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
        printf("to aqui3");
        vida_total_mob -= retira_Fila(a);
        if (vida_total_mob >= mob->info->pontoVida)
        {
            mob->info->pontoDefesa = (vida_total_mob - mob->info->pontoVida);
        }
        else if (vida_total_mob <= mob->info->pontoVida)
        {
            mob->info->pontoVida = vida_total_mob;
        }
        imprimePersonagem(hero);
        imprimeMOB(mob);
        printf("to aqui4");
    }
}
//imprime mob
//mover função de inicialização para os lugares corretos