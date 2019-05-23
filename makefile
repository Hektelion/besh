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

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

#obj/main.o	: $(OBJ_CLASS) $(OBJ)

obj/%.o : src/%.c
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

####################################################

.PHONY	: clean mrproper

clean	:
	rm -f obj/*.o

mrproper: clean
	rm -rf $(EXEC)

print-%  : ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet besh ######################################
####################################################
