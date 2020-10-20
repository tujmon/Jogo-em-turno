#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include <stdlib.h>
#include "../personagem/personagem.h"
#include "../fila/fila.h"
#include "../mob/mob.h"

FILA *enfilera_ataque(ListaH *hero, ListaM *mob);
void batalha(ListaH *hero, ListaM *mob);
void partida(ListaH *hero, ListaM *mob, FILA *a);
#endif