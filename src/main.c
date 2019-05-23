#include <stdlib.h>	//EXIT_SUCCESS et EXIT_FAILURE

#include "../include/besh_initialization.h"
#include "../include/besh_interpret.h"
#include "../include/besh_terminate.h"
//#include "../include/besh_internal_command.h"

int main(){

	//CONFIGURATION
	besh_initialize();

	//INTERPRETATION
	besh_interpretLoop();

	//TERMINAISON
	besh_cleanup();

	return EXIT_SUCCESS;
}
