#include "../include/besh_initialization.h"
#include "../include/besh_constant.h"

#include "../include/environement.h"

//#include <stdio.h> //stderr, printf() et EOF
//#include <stdlib.h>	//EXIT_FAILURE et NULL
#include <unistd.h> //environ

/* Entrées    : -
* Sorties    : -
* Variables  : -
* Traitement : -
* Erreur	  : -
*/
void init_environement()
{
	for (size_t i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}
