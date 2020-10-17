all: main

main: jogo.o personagem.o
	gcc main.c jogo.o personagem.o -o main

jogo.o:
	gcc -c jogo.c

personagem.o:
	gcc -c personagem.c

rm:
	rm *.o