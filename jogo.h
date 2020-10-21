#ifndef JOGO_H
#define JOGO_H

//includes
#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#include "fila.h"
#include "itens.h"

//funções
FILA *enfilera_ataque(ListaH *hero, ListaM *mob);
void batalha(ListaH *hero, ListaM *mob);
void partida(ListaH *hero, ListaM *mob, FILA *a);

#endif