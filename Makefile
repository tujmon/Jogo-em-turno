
cc=gcc
all: main

main: jogo.o personagem.o fila.o mob.o
	$(cc) main.c jogo.o personagem.o fila.o mob.o -Wall -o main

jogo.o:
	$(cc) -c jogo.c

personagem.o:
	$(cc) -c personagem.c

fila.o:
	$(cc) -c fila.c

mob.o:
	$(cc) -c mob.c

rm:
	rm *.o