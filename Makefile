# Nome do projeto
PROJ_NAME=JOGO-EM-TURNO

# arquivos .c
C_SOURCE=$(wildcard ./source/*.c)

# arquivos .h
H_SOURCE=$(wildcard ./source/*.h)

# arquivos .o
OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

# Compilador
CC=gcc

# opções do compilador
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic

# comando usado para limpar
RM = rm -rf

# Compilando

all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./source/%.c ./source/%.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./source/main.c $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean