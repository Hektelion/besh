#include "../include/besh_internal_command.h"
#include "../include/besh_constant.h"

#include <stdio.h> //printf()
#include <stdlib.h>	//EXIT_FAILURE, EXIT_FAILURE et NULL

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_help(char **args)
{
	fprintf(stderr, "NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_exit(char **args)
{
	return 0;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_cd(char **args)
{
	fprintf(stderr, "NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_pwd(char **args)
{
	fprintf(stderr, "NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_alias(char **args)
{
	fprintf(stderr, "NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_echo(char **args)
{
	int position = 1;

	while (args[position] != NULL) {
		if(args[position][0] != '$')
		{
			fprintf(stdout, "%s ", args[position]);
		}
		else
		{
			fprintf(stderr, "FONCTIONNALITE NON IMPLEMENTEE\n");
			return 1;
		}
		position++;
	}
	fprintf(stdout, "\n");

	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_type(char **args)
{
	fprintf(stderr, "NON IMPLEMENTEE\n");
	return 1;
}
