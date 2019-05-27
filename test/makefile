####################################################
################## MAKEFILE TEST ###################
####################################################

#EXECUTION
CC = gcc
LDFLAGS = -lcunit
CFLAGS = -W -Wall
EXEC = ../test_besh

INCLUDE = $(wildcard ./include/*.h)
SRC = $(wildcard ./src/*.c)
OBJ = $(SRC:./src/%.c=./obj/%.o)

LINK = ../obj/besh_functions.o ../obj/besh_internal_command.o ../obj/besh_terminate.o ../obj/besh_initialization.o ../obj/besh_interpret.o
#$(wildcard ../obj/*.o)

####################################################

all: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ) $(LINK)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

#obj/main.o	:

obj/%.o : src/%.c
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

####################################################

.PHONY: clean mrproper

.IGNORE: clean

clean:
	rm -f obj/*.o

mrproper: clean
	rm -rf $(EXEC)

print-%: ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet besh ######################################
####################################################
