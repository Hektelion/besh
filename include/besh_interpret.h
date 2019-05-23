#ifndef __INTERPRET_H__
#define __INTERPRET_H__

char* besh_readCommand();
char **besh_separateCommand(char *, const char *);
int besh_executeCommand(char **);
void besh_interpretLoop();

void besh_clean_interpret();

#endif //__INTERPRET_H__
