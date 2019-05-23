#include "../include/besh_terminate.h"
#include "../include/besh_constant.h"

void besh_cleanup()
{
	besh_clean_configuration();
	besh_clean_interpret();
}
