#include <stdio.h>
#include <CUnit/Basic.h>

#include "../include/test_besh_functions.h"
#include "../include/test_besh_initialization.h"
#include "../include/test_besh_internal_command.h"
#include "../include/test_besh_interpret.h"
#include "../include/test_besh_terminate.h"

int main(){
	CU_pSuite pSuite = NULL;

	/****************************************************
	***************** TEST FONCTIONS *******************
	****************************************************
	*/

	printf("\nTEST FUNCTIONS\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_replace_str()", test_besh_replace_str) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_sup_space()", test_besh_sup_space) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_1", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_format_str()", test_besh_format_str ) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	/****************************************************
	*************** TEST INITIALISATION ****************
	****************************************************
	*/

	printf("\nTEST INITIALIZATION\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_getenv()", test_besh_getenv) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_putenv()", test_besh_putenv) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_setenv()", test_besh_setenv) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_unsetenv()", test_besh_unsetenv) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_1", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_initenvironement()", test_besh_initenvironement) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	/****************************************************
	************* TEST INTERNAL COMMAND ****************
	****************************************************
	*/

	printf("\nTEST INTERNAL COMMAND\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_help()", test_besh_help) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_exit()", test_besh_exit) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_cd()", test_besh_cd) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_pwd()", test_besh_pwd) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_alias()", test_besh_alias) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_echo()", test_besh_echo) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_type()", test_besh_type) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	/****************************************************
	***************** TEST INTERPRET *******************
	****************************************************
	*/

	printf("\nTEST INTERPRET\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_readCommand()", test_besh_readCommand) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_separateCommand()", test_besh_separateCommand) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_executeCommand()", test_besh_executeCommand) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_1", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_interpretLoop()", test_besh_interpretLoop) ) == NULL ||
	( CU_add_test(pSuite, "test of besh_clean_interpret()", test_besh_clean_interpret) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	/****************************************************
	***************** TEST TERMINATE *******************
	****************************************************
	*/

	printf("\nTEST TERMINATE\n");

	//Initialise le registre de test de CUnit
	if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	//Ajoute la suite au registre
	pSuite = CU_add_suite("Layer_0", 0, 0);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Ajoute les tests de la couche 0 à la suite
	if ( ( CU_add_test(pSuite, "test of besh_cleanup()", test_besh_cleanup) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}
