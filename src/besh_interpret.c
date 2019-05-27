#include "../include/besh_interpret.h"
#include "../include/besh_constant.h"

#include "../include/besh_internal_command.h" //Toutes les commandes interne
#include "../include/besh_initialization.h" //besh_get_cwd()

#include <stdio.h> //stderr, printf() et EOF
#include <stdlib.h>	//EXIT_FAILURE et NULL
#include <string.h>	//strtok() et strcmp()

/* Entrées    : -
* Sorties    : la commande entrer par l'utilisateur
* Variables  : command(chaine de caracteres), buffer_command_size(entier),
position(entier), c(caractere)
* Traitement : Récupere la commande taper au clavier par l'utilisateur et
la retourne
* Erreur	  : allocation command, reallocation command
*/
char* besh_readCommand()
{
	char *command = NULL;
	int buffer_command_size = BESH_COMMAND_BUFFER_SIZE;
	int position = 0;
	char c;

	command = malloc(sizeof(char) * buffer_command_size);
	if(command == NULL)
	{
		fprintf(stderr, "erreur : allocation command\n");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		c = getc(stdin);

		command[position] = c;
		position++;

		if(c == '\n' || c == EOF)
		{
			if(DEBUG) printf("command :%s", command);
			return command;
		}

		if(buffer_command_size <= position)
		{
			buffer_command_size += BESH_COMMAND_BUFFER_SIZE;
			command = realloc(command, sizeof(char) * buffer_command_size);

			if(command == NULL)
			{
				fprintf(stderr, "erreur : reallocation command\n");
				exit(EXIT_FAILURE);
			}
		}

	}
}

/* Entrées    : la commande entrer par l'utilisateur et la liste des délimiteur
* Sorties    : le nom de la commande et ces parametres
* Variables  : arg(chaine de caracteres), args(un tableau de chaine de caracteres),
buffer_arg_size(entier), position(entier)
* Traitement : a partir de la commande et des delimiteurs cette fonction sépare la buffer_command_size
mot par mot et renvoi le tout dans un tableau
* Erreur	  : allocation args, reallocation args
*/
char **besh_separateCommand(char *command, const char *delimiters)
{
	char *arg = NULL;
	char **args = NULL;
	int buffer_arg_size = BESH_ARGS_BUFFER_SIZE;
	int position = 0;

	args = malloc(sizeof(char*) * buffer_arg_size);
	if(args == NULL)
	{
		fprintf(stderr, "erreur : allocation args\n");
		exit(EXIT_FAILURE);
	}

	arg = strtok(command, delimiters);

	while(arg != NULL)
	{
		if(DEBUG) printf("arg[%d] :%s\n", position, arg);

		args[position] = arg;
		position++;

		if(buffer_arg_size <= position)
		{
			buffer_arg_size += BESH_ARGS_BUFFER_SIZE;
			args = realloc(args, sizeof(char*) * buffer_arg_size);

			if(args == NULL)
			{
				fprintf(stderr, "erreur : reallocation args\n");
				exit(EXIT_FAILURE);
			}
		}

		arg = strtok(NULL, delimiters);
	}

	return args;
}

/* Entrées    : Le nom de la commande suivi de ces parametres si il y'en a
* Sorties    : un signal envoyer au shell
* Variables  : statut(entier)
* Traitement : Elle cherche dans les commandes internes la commande et l'execute si correspondance
Sinon elle cherche dans les dossier de binaires cités dans la variable PATH
Sinon elle affiche un message d'erreur
* Erreur	  : 1er argument NULL
*/
int besh_executeCommand(char **args)
{
	int statut = 1;

	if(args[0] != NULL)
	{
		if(strcmp(args[0], "help") == 0)
		{
			statut = besh_help(args);
		}
		else if(strcmp(args[0], "exit") == 0)
		{
			statut = besh_exit(args);
		}
		else if(strcmp(args[0], "cd") == 0)
		{
			statut = besh_cd(args);
		}
		else if(strcmp(args[0], "pwd") == 0)
		{
			statut = besh_pwd(args);
		}
		else if(strcmp(args[0], "alias") == 0)
		{
			statut = besh_alias(args);
		}
		else if(strcmp(args[0], "echo") == 0)
		{
			statut = besh_echo(args);
		}
		else if(strcmp(args[0], "type") == 0)
		{
			statut = besh_type(args);
		}
		else if(strcmp(args[0], "printenv") == 0)
		{
			statut = besh_type(args);
		}
		else
		{
			if(DEBUG) printf("%s n'est pas une commande interne\n", args[0]);
		}
	}
	else
	{
		fprintf(stderr, "erreur : nom de commande null\n");
	}

	return statut;
}

/* Entrées    : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur	  : -
*/
void besh_interpretLoop()
{
	int statut;
	char *command;
	char **args;

	do {
		fprintf(stdout, ">");

		command = besh_readCommand();
		args = besh_separateCommand(command, BESH_SEPARATOR);
		statut = besh_executeCommand(args);

		besh_clean_interpret(command, args);

	} while(statut);

}

/* Entrées    : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur	  : -
*/
void besh_clean_interpret(char *command, char **args)
{

	if(command != NULL)
	{
		if(DEBUG) fprintf(stdout, "libération de command\n");
		free(command);
		command = NULL;
	}

	if(args != NULL)
	{
		if(DEBUG) fprintf(stdout, "libération de args\n");
		free(args);
		args = NULL;
	}
}
