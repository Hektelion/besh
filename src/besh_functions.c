#include "../include/besh_functions.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void besh_replace_str(char *command, char *sym_search, char *sym_remplace)
{
	int occurencies = 0;
	char *copy_command = command;

	//Recherche la premiere occurence du symbole dans la chaine
	char *tmp = strstr(copy_command, sym_search);
	//Tant qu'il y a des occurence dans la chaine
	while (tmp!=NULL)
    {
		//Incrémentation du nombre d'occurences
        occurencies++;
		//Ont déplace le pointeur en sautant l'occurence
        copy_command = tmp + strlen(sym_search);
		//Ont cherche l'occurence suivante
        tmp=strstr(copy_command, sym_search);

    }

	if(occurencies > 0)
	{
		//Taille commande - (taille recherche * occurence) + (taille remplacement * occurence) + caractere de fin de chaine
		char *result=malloc( strlen(command) - (strlen(sym_search) * occurencies ) + ( strlen(sym_remplace) * occurencies) + 1);
		//Ont place le caractere de fin de chaine
        result[0] = '\0';
		//Ont effectue une nouvelle copie de la commande
        char *copy_command = command;

		//On cherche la premiere occurence
        char *tmp = strstr(copy_command, sym_search);
		//Tant qu'il reste des occurences
        while(tmp != NULL)
        {
			//Concatene la partie valide de la chaine
            strncat(result, copy_command, tmp - copy_command);
			//Concatene le symbole remplacé
            strcat(result, sym_remplace);
			//Saute le symbole dans la chaine
            copy_command = tmp + strlen(sym_search);
			//Recherche la prochaine occurence
            tmp = strstr(copy_command, sym_search);
        }
		//Concatene la chaine valide dans la chaine result
        strcat(result, copy_command);
		//Copie la chaine result dans la commande
        strcpy(command, result);
		//Libere la chaine result
        free(result);
	}

}

void besh_format_str(char *command)
{
	//REDIRECTION DROITE >
	besh_replace_str(command," >",">");
	besh_replace_str(command,"> ",">");
	besh_replace_str(command,">"," > ");

	//REDIRECTION GAUCHE <
	besh_replace_str(command," <","<");
	besh_replace_str(command,"< ","<");
	besh_replace_str(command,"<"," < ");

	//DOUBLE REDIRECTION DROITE >>
	besh_replace_str(command," >  > "," >> ");

	//DOUBLE REDIRECTION GAUCHE <<
	besh_replace_str(command," <  < "," << ");

	//PIPE
	besh_replace_str(command," |","|");
	besh_replace_str(command,"| ","|");
	besh_replace_str(command,"|"," | ");

}
