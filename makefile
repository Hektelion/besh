####################################################
################ MAKEFILE PRINCIPAL ################
####################################################

#EXECUTION
CC = gcc
LDFLAGS =
CFLAGS = -W -Wall
EXEC = besh

INCLUDE = $(wildcard ./include/*.h)
SRC = $(wildcard ./src/*.c)
OBJ = $(SRC:./src/%.c=./obj/%.o)

TEST = all

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ) $(TEST)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

#obj/main.o	:

obj/%.o : src/%.c
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

$(TEST): test
	@echo "Création de l'executable des tests unitaire"
	make -C test all

####################################################

.PHONY	: clean mrproper

.IGNORE: clean

clean	:
	rm -f obj/*.o

mrproper: clean
	rm -rf $(EXEC)

print-%  : ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet besh ######################################
####################################################
