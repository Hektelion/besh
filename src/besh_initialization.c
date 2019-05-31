#include "../include/besh_initialization.h"
#include "../include/besh_constant.h"

#include "../include/environement.h"

#include <stdio.h> //stderr, printf() et EOF
#include <stdlib.h>	//EXIT_FAILURE et NULL
#include <unistd.h> //environ
#include <string.h>
#include <fcntl.h>

char **besh_environement;
int besh_nb_var_environement;

/* Entrées   : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur     : -
*/
char *besh_getenv(char *name)
{

}

/* Entrées   : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur     : -
*/
int besh_putenv(char *name_equal_val)
{

}

/* Entrées   : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur     : -
*/
int besh_setenv(char *name, const char *value, int overwrite)
{

}

/* Entrées   : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur     : -
*/
int besh_unsetenv(const char *name)
{

}



/* Entrées   : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur     : -
*/
/*
int besh_initenvironement()
{
	char *path_profile = NULL;
	char c;
	int profile_fd;

	path_profile = getcwd(path_profile, 0);
	strcat(path_profile, "/profile");

	if( (profile_fd = open(path_profile, O_RDONLY)) == -1 )
	{
		//AJOUTER LA GESTION DE ERRNO ET PERROR
		fprintf(stderr, "ERREUR : open()\n");
		free(path_profile);
		exit(EXIT_FAILURE);
	}

	//TRAITEMENT

	if(close(profile_fd) == -1)
	{
		//AJOUTER LA GESTION DE ERRNO ET PERROR
		fprintf(stderr, "ERREUR : close()\n");
	}

	free(path_profile);
}
*/

/* Entrées   : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur     : -
*/
int besh_initenvironement()
{
	char *path_profile = NULL;
	char c;
	FILE *profile = NULL;
	int i = 0;
	int ret;

	besh_nb_var_environement = 1;
	besh_environement = NULL;

	besh_environement = malloc(besh_nb_var_environement * sizeof(char*));

	if(besh_environement == NULL)
	{
		fprintf(stderr, "Erreur pendant l'allocation de : besh_environement\n");
		exit(EXIT_FAILURE);
	}

	path_profile = getcwd(path_profile, 0);
	strcat(path_profile, "/profile");

	//OUVERTURE DE PROFILE
	profile = fopen(path_profile, "r");

	if(profile == NULL)
	{
		fprintf(stderr, "Erreur pendant l'ouverture de : %s\n", path_profile);
		exit(EXIT_FAILURE);
	}

	//TRAITEMENT
	while( (ret = fscanf(profile, "%s\n", besh_environement[i])) != EOF && ret != 0)
	{
		printf("%s\n", besh_environement[i]);
		besh_nb_var_environement ++;
		besh_environement = realloc(besh_environement, besh_nb_var_environement * sizeof(char*));
		if(besh_environement == NULL)
		{
			fprintf(stderr, "Erreur pendant la réallocation de : besh_environement\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}

	printf("OK\n");

	//FERMETURE DE PROFILE
	fclose(profile);

	free(path_profile);

	return 0;
}
