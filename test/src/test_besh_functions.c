#include "../include/test_besh_functions.h"
#include "../../include/besh_functions.h"

#include <string.h>
#include <CUnit/Basic.h>

void test_replace_str()
{
	char chaine[1000];

	//printf("test\n\n\n");

	//CAS REDIRECTION DROITE >
	strcpy(chaine, "test> test");
	replace_str(chaine, "> ", ">");
	CU_ASSERT( strcmp(chaine, "test>test") == 0 );

	strcpy(chaine, "test >test");
	replace_str(chaine, " >", ">");
	CU_ASSERT( strcmp(chaine, "test>test") == 0 );

	strcpy(chaine, "test>test");
	replace_str(chaine, ">", " > ");
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );




	//CAS REDIRECTION GAUCHE <
	strcpy(chaine, "test< test");
	replace_str(chaine, "< ", "<");
	CU_ASSERT( strcmp(chaine, "test<test") == 0 );

	strcpy(chaine, "test <test");
	replace_str(chaine, " <", "<");
	CU_ASSERT( strcmp(chaine, "test<test") == 0 );

	strcpy(chaine, "test<test");
	replace_str(chaine, "<", " < ");
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );





	//CAS DOUBLE REDIRECTION DROITE >>
	strcpy(chaine, "test>> test");
	replace_str(chaine, ">> ", ">>");
	CU_ASSERT( strcmp(chaine, "test>>test") == 0 );

	strcpy(chaine, "test >>test");
	replace_str(chaine, " >>", ">>");
	CU_ASSERT( strcmp(chaine, "test>>test") == 0 );

	strcpy(chaine, "test>>test");
	replace_str(chaine, ">>", " >> ");
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );





	//CAS DOUBLE REDIRECTION GAUCHE <<
	strcpy(chaine, "test<< test");
	replace_str(chaine, "<< ", "<<");
	CU_ASSERT( strcmp(chaine, "test<<test") == 0 );

	strcpy(chaine, "test <<test");
	replace_str(chaine, " <<", "<<");
	CU_ASSERT( strcmp(chaine, "test<<test") == 0 );

	strcpy(chaine, "test<<test");
	replace_str(chaine, "<<", " << ");
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );





	//CAS PIPE
	strcpy(chaine, "test| test");
	replace_str(chaine, "| ", "|");
	CU_ASSERT( strcmp(chaine, "test|test") == 0 );

	strcpy(chaine, "test |test");
	replace_str(chaine, " |", "|");
	CU_ASSERT( strcmp(chaine, "test|test") == 0 );

	strcpy(chaine, "test|test");
	replace_str(chaine, "|", " | ");
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );
}

void test_format_str()
{
	char chaine[1000];

	//CAS REDIRECTION DROITE >
	strcpy(chaine, "test> test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );

	strcpy(chaine, "test >test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );

	strcpy(chaine, "test>test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );




	//CAS REDIRECTION GAUCHE <
	strcpy(chaine, "test< test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );

	strcpy(chaine, "test <test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );

	strcpy(chaine, "test<test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );




	//CAS DOUBLE REDIRECTION DROITE >>
	strcpy(chaine, "test>> test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );

	strcpy(chaine, "test >>test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );

	strcpy(chaine, "test>>test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );



	//CAS DOUBLE REDIRECTION GAUCHE <<
	strcpy(chaine, "test<< test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );

	strcpy(chaine, "test <<test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );

	strcpy(chaine, "test<<test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );



	//CAS PIPE
	strcpy(chaine, "test| test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );

	strcpy(chaine, "test |test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );

	strcpy(chaine, "test|test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );
}

void test_sup_space()
{
	char chaine[1000];

	//AUCUN ESPACE SUPPLEMENTAIRE
	strcpy(chaine, "test test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE AVANT
	strcpy(chaine, " test test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE MILLIEU
	strcpy(chaine, "test  test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE APRES
	strcpy(chaine, "test test ");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE AVANT ET APRES
	strcpy(chaine, " test test ");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE MILLIEU ET APRES
	strcpy(chaine, "test  test ");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE AVANT ET MILIEU
	strcpy(chaine, " test  test");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );

	//ESPACE SUPPLEMENTAIRE AVANT ET MILIEU ET APRES
	strcpy(chaine, " test  test ");
	format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test test") == 0 );
}
