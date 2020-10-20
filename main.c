#include "jogo.h"
<<<<<<< HEAD
    /*
=======
/*
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2
                            *** BATALHA DE RPG DE TURNOS ***
    REFÊNCIA: https://www.youtube.com/watch?v=xFdGrHBAawY&list=PL4OAe-tL47sZaHoNOFzW4Nu2cDYIZ4EmQ&index=23 *
    
        - Batalha de turnos, onde a ação será "dinâmica" (Realiza o turno quem for mais rápido);
        - Características dos personagens: herois/inimigos;
            - Atributos:
                * Nome do Personagem (dado pelo usuário)(MÁX. 2 Personagens);
                * Pontos de vida (padrão: 100);
                * Pontos de força (padrão: 5);
                * Pontos de Defesa (padrão: 5);
                * Pontos de Velocidade (padrão: 3).
                
        - Inventário dos personagens (talvez);
<<<<<<< HEAD
        - Uma série de batalhas;
        - Experiências, níveis, etc (talvez).
    */

int main(void){
    Lista* p;
    char nick[20];
    int i;
    p = inicializa();
    for(i = 0; i < 2; i++){
        do{
            puts("Digite o nome do personagem(MÁX. 20 Caracteres): ");
            scanf("%[^\n]s", nick);
            getchar();
            if(strlen(nick) > 20){
                puts("Nome inválido! Máximo de caracteres: 20\n");
            }
        }while(strlen(nick) > 20);
        p = alocaPersonagem(p, nick);
    }
    imprimePersonagem(p);

    free(p);

=======
            - Se for fazer isto temos que adicionar drops nos monstros, ou uma espécie de bau
        - Uma série de batalhas;
            - criar varios mobs, talvez dividilos em lugares
        - Experiências, níveis, etc (talvez).
            - Podemos colocar diversos itens baseados no nível do personagem, teremos que colocar um exp para cada caso,
                por exemplo dividir xp por 3 ou quem der o last hit ganha o xp 
    */

int main(void)
{
    //declaração de variaveis
    Lista *p;
    char nick[20];
    int i, numPersonagem;

    p = inicializa();

    //aqui pegamos quantas pessoas irão jogar o jogo
    puts("Digite a quantidade de jogadores:");
    scanf("%d", &numPersonagem);
    getchar();

    //fazemos o for e o while para pegar os nomes
    for (i = 0; i < numPersonagem; i++)
    {
        do
        {
            puts("Digite o nome do personagem(MÁX. 20 Caracteres): ");
            scanf("%[^\n]s", nick);
            getchar();
            if (strlen(nick) > 20)
            {
                puts("Nome inválido! Máximo de caracteres: 20\n");
            }
        } while (strlen(nick) > 20);
        p = alocaPersonagem(p, nick); // alocamos o nome do personagem dentro da lista de personagens
    }
    imprimePersonagem(p); //imprimimos os personagens
    //fazer uma introdução ao que aconteceu para eles se encontrarem juntos
    //fazer uma luta inicial, explicando como funciona o jogo(podemos perguntar se eles ja jogaram o jogo anteriormente)
    //criar varios monstros e uma narrativa
    free(p);
>>>>>>> 95360af190d17c18003774eb3e0e296bdbe490f2
    return 0;
}