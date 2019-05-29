#ifndef __INTERNAL_COMMAND_H__
#define __INTERNAL_COMMAND_H__

#include "besh_constant.h"

int besh_help(char **);
int besh_exit(char **);
int besh_cd(char **);
int besh_pwd(char **);
int besh_alias(char **);
int besh_echo(char **);
int besh_type(char **);


extern char *internal_commands_names[NB_INTERNAL_COMMANDS] = {
	"help",
	"exit",
	"cd",
	"pwd",
	"alias",
	"echo",
	"type"
};

extern int (*internal_commands_functions[NB_INTERNAL_COMMANDS]) (char **) = {
	&besh_help,
	&besh_exit,
	&besh_cd,
	&besh_pwd,
	&besh_alias,
	&besh_echo,
	&besh_type
};

#endif //__INTERNAL_COMMAND_H__
