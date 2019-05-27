#include <stdio.h>
#include <CUnit/Basic.h>

#include "../include/test_besh_functions.h"
#include "../include/test_besh_initialization.h"
#include "../include/test_besh_internal_command.h"
#include "../include/test_besh_interpret.h"
#include "../include/test_besh_terminate.h"

int main(){
	CU_pSuite pSuite = NULL;

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
	if ( ( CU_add_test(pSuite, "test of replace_str()", test_replace_str) ) == NULL ||
		 ( CU_add_test(pSuite, "test of format_str()", test_format_str ) ) == NULL ||
		 ( CU_add_test(pSuite, "test of sup_space()", test_sup_space) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

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
	if ( ( CU_add_test(pSuite, "test of nothing()", test_replace_str) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

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
	if ( ( CU_add_test(pSuite, "test of nothing()", test_replace_str) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

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
	if ( ( CU_add_test(pSuite, "test of nothing()", test_replace_str) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

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
	if ( ( CU_add_test(pSuite, "test of nothing()", test_replace_str) ) == NULL ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Lance tout les tests en utilisant l'interface basique de CUnit
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}
