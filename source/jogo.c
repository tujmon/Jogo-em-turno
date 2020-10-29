#include "jogo.h"
#include <time.h>
#include <unistd.h>

void batalha(ListaH *hero, ListaM *mob)
{
    int a;
    while (hero != NULL)
    {
        puts("Escolha:\n"
             "1 - Ataque\n"
             "2 - Fugir\n"
             "3 - Defesa\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {

            FILA *a = enfilera_ataque(hero, mob);
            partida(hero, mob, a);
            if (hero->info->pontoVida <= 0)
            {
                hero = hero->prox;
            }
            if (hero == NULL)
            {
                puts("GAME OVER!");
                exit(1);
            }
            if (mob->info->pontoVida <= 0)
            {
                puts("você ganhou a batalha!");
                puts("Novos status:");
                sobe_nivel(hero->info);
                imprimePersonagem(hero);
                sleep(5);
                if (mob->prox != NULL)
                {
                    batalha(hero, mob->prox);
                }
                else
                {
                    puts("Parabéns por concluir o jogo!");
                    exit(0);
                }
            }
            break;
        }
        case 2:
            if (rand() % 2 == 1)
            {
                puts("Você conseguiu escapar 'HEROI'. UFA!");
                if (mob != NULL)
                {
                    mob = mob->prox;
                }
                else
                {
                    exit(0);
                }
            }
            else
            {
                hero->info->pontoVida -= mob->info->pontoForca;
                printf("Você falhou em fugir. TOMA ESSA!!\n-%d de Vida", mob->info->pontoForca);

                imprimePersonagem(hero);
            }
            break;
        case 3:
            hero->info->pontoDefesa += (int)(rand() % 25);
            hero->info->pontoVida -= mob->info->pontoForca;
            printf("Você incrementou defesa mas foi atacado!");
            imprimePersonagem(hero);
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
        system("clear");
        printf("Ataque do Heroi:\n");
        imprimePersonagem(hero);
        imprimeMOB(mob);
        sleep(5);

        vida_total_heroi -= retira_Fila(a);
        if (vida_total_heroi >= hero->info->pontoVida)
        {
            hero->info->pontoDefesa = (vida_total_heroi - hero->info->pontoVida);
        }
        else if (vida_total_heroi <= hero->info->pontoVida)
        {
            hero->info->pontoVida = vida_total_heroi;
        }
        system("clear");
        printf("Ataque do Monstro:\n");
        imprimePersonagem(hero);
        imprimeMOB(mob);
        sleep(5);
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
        system("clear");
        printf("Ataque do Monstro:\n");
        imprimePersonagem(hero);
        imprimeMOB(mob);
        sleep(5);
        if (vida_total_heroi <= 0)
        {
            return;
        }
        vida_total_mob -= retira_Fila(a);
        if (vida_total_mob >= mob->info->pontoVida)
        {
            mob->info->pontoDefesa = (vida_total_mob - mob->info->pontoVida);
        }
        else if (vida_total_mob <= mob->info->pontoVida)
        {
            mob->info->pontoVida = vida_total_mob;
        }
        system("clear");
        printf("Ataque do Heroi:\n");
        imprimePersonagem(hero);
        imprimeMOB(mob);
        sleep(5);
    }
}