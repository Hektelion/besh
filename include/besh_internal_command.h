#ifndef __INTERNAL_COMMAND_H__
#define __INTERNAL_COMMAND_H__

int besh_help(char **);
int besh_exit();
int besh_cd(char **);
int besh_pwd();
int besh_alias(char **);
int besh_echo(char **);
int besh_type(char **);
int besh_printenv();
int besh_getenv(char **);
int besh_putenv(char **);

#endif //__INTERNAL_COMMAND_H__
