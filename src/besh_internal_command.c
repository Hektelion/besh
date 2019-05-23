#include "../include/besh_internal_command.h"
#include "../include/besh_constant.h"

#include "../include/besh_initialization.h" //besh_get_cwd()

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
	printf("NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_exit()
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
	printf("NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : Les arguments de la fonction
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_pwd()
{
	printf("%s\n", besh_get_cwd());
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
	printf("NON IMPLEMENTEE\n");
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
	printf("NON IMPLEMENTEE\n");
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
	printf("NON IMPLEMENTEE\n");
	return 1;
}

/* Entrées    : -
 * Sorties    : -
 * Variables  : -
 * Traitement : -
 * Erreur	  : -
 */
int besh_printenv()
{
	printf("NON IMPLEMENTEE\n");
	return 1;
}
