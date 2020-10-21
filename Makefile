all: main

main: jogo.o personagem.o fila.o mob.o
	gcc main.c jogo.o personagem.o fila.o mob.o -o main

jogo.o:
	gcc -c jogo.c

personagem.o:
	gcc -c personagem.c

fila.o:
	gcc -c fila.c

mob.o:
	gcc -c mob.c

rm:
	rm *.o