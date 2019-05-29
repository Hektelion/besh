#ifndef __INITIALIZATION_H__
#define __INITIALIZATION_H__

char *besh_getenv(char *);
int besh_putenv(char *);
int besh_setenv(char *, const char *, int);
int besh_unsetenv(const char *);

int besh_initenvironement();

#endif //__INITIALIZATION_H__
