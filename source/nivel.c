#include "nivel.h"

void sobe_nivel(Personagem *a)
{
    a->pontoDefesa += 10;
    a->pontoForca += 5;
    a->pontoVelocidade += 2;
    a->pontoVida += 20;
}