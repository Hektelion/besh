#include "../include/besh_initialization.h"
#include "../include/besh_constant.h"

#include <stdio.h> //stderr, printf() et EOF
#include <stdlib.h>	//EXIT_FAILURE et NULL
#include <unistd.h> //getcwd

static char *cwd = NULL;

char* besh_get_cwd()
{
	cwd = malloc(sizeof(char) * BESH_CWD_BUFFER_SIZE);

	if(cwd == NULL)
	{
		fprintf(stderr, "erreur : allocation cwd\n");
		exit(EXIT_FAILURE);
	}

	getcwd(cwd, BESH_CWD_BUFFER_SIZE);
	if(DEBUG) printf("cwd :%s\n", cwd);

	return cwd;
}

void besh_initialize()
{
	besh_get_cwd();
}

void besh_clean_configuration()
{
	if(cwd != NULL)
	{
		if(DEBUG) fprintf(stdout, "libération de cwd\n");
		free(cwd);
		cwd = NULL;
	}
}
