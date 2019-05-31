#include "../include/test_besh_functions.h"
#include "../../include/besh_functions.h"

#include <string.h>
#include <CUnit/Basic.h>

void test_besh_replace_str()
{
	char chaine[1000];

	//printf("test\n\n\n");

	//CAS REDIRECTION DROITE >
	strcpy(chaine, "test> test");
	besh_replace_str(chaine, "> ", ">");
	CU_ASSERT( strcmp(chaine, "test>test") == 0 );

	strcpy(chaine, "test >test");
	besh_replace_str(chaine, " >", ">");
	CU_ASSERT( strcmp(chaine, "test>test") == 0 );

	strcpy(chaine, "test>test");
	besh_replace_str(chaine, ">", " > ");
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );




	//CAS REDIRECTION GAUCHE <
	strcpy(chaine, "test< test");
	besh_replace_str(chaine, "< ", "<");
	CU_ASSERT( strcmp(chaine, "test<test") == 0 );

	strcpy(chaine, "test <test");
	besh_replace_str(chaine, " <", "<");
	CU_ASSERT( strcmp(chaine, "test<test") == 0 );

	strcpy(chaine, "test<test");
	besh_replace_str(chaine, "<", " < ");
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );





	//CAS DOUBLE REDIRECTION DROITE >>
	strcpy(chaine, "test>> test");
	besh_replace_str(chaine, ">> ", ">>");
	CU_ASSERT( strcmp(chaine, "test>>test") == 0 );

	strcpy(chaine, "test >>test");
	besh_replace_str(chaine, " >>", ">>");
	CU_ASSERT( strcmp(chaine, "test>>test") == 0 );

	strcpy(chaine, "test>>test");
	besh_replace_str(chaine, ">>", " >> ");
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );





	//CAS DOUBLE REDIRECTION GAUCHE <<
	strcpy(chaine, "test<< test");
	besh_replace_str(chaine, "<< ", "<<");
	CU_ASSERT( strcmp(chaine, "test<<test") == 0 );

	strcpy(chaine, "test <<test");
	besh_replace_str(chaine, " <<", "<<");
	CU_ASSERT( strcmp(chaine, "test<<test") == 0 );

	strcpy(chaine, "test<<test");
	besh_replace_str(chaine, "<<", " << ");
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );





	//CAS PIPE
	strcpy(chaine, "test| test");
	besh_replace_str(chaine, "| ", "|");
	CU_ASSERT( strcmp(chaine, "test|test") == 0 );

	strcpy(chaine, "test |test");
	besh_replace_str(chaine, " |", "|");
	CU_ASSERT( strcmp(chaine, "test|test") == 0 );

	strcpy(chaine, "test|test");
	besh_replace_str(chaine, "|", " | ");
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );
}

void test_besh_format_str()
{
	char chaine[1000];

	//CAS REDIRECTION DROITE >
	strcpy(chaine, "test> test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );

	strcpy(chaine, "test >test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );

	strcpy(chaine, "test>test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test > test") == 0 );




	//CAS REDIRECTION GAUCHE <
	strcpy(chaine, "test< test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );

	strcpy(chaine, "test <test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );

	strcpy(chaine, "test<test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test < test") == 0 );




	//CAS DOUBLE REDIRECTION DROITE >>
	strcpy(chaine, "test>> test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );

	strcpy(chaine, "test >>test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );

	strcpy(chaine, "test>>test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test >> test") == 0 );



	//CAS DOUBLE REDIRECTION GAUCHE <<
	strcpy(chaine, "test<< test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );

	strcpy(chaine, "test <<test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );

	strcpy(chaine, "test<<test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test << test") == 0 );



	//CAS PIPE
	strcpy(chaine, "test| test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );

	strcpy(chaine, "test |test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );

	strcpy(chaine, "test|test");
	besh_format_str(chaine);
	CU_ASSERT( strcmp(chaine, "test | test") == 0 );
}
