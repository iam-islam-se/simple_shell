#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

#define P_COMB7RISL 3
#define D_NDB7RISL -1
#define L_CB7RISL 2
#define EL_COB7RISL 1


typedef struct mapp
{
	char *ba7r;
	void (*ff)(char **lals);
} f_m;

extern int statusB7RISL;
extern char **ba7rwithislam;
extern char *lsaffe;
extern char *shell_nameB7RISL;
extern char **environ;

void remove_newlineB7RISL(char *);
void printB7RISL(char *, int);
int _strlenB7RISL(char *);
char **tokenizerB7RISL(char *, char *);
void _strcpyB7RISL(char *, char *);

int _strcspnB7RISL(char *, char *);
int _strcmpB7RISL(char *, char *);
int _strspnB7RISL(char *, char *);
char *_strchrB7RISL(char *, char);
char *_strcatB7RISL(char *, char *);

int _atoiB7RISL(char *);
void remove_commentB7RISL(char *);
char *_strtok_rB7RISL(char *, char *, char **);
void ctrl_c_handlerB7RISL(int);
void *_reallocB7RISL(void *ptr, unsigned int old_size, unsigned int new_size);

void execute_commandB7RISL(char **, int);
char *_getenvB7RISL(char *);
void (*get_funcB7RISL(char *))(char **);
int parse_commandB7RISL(char *);
char *check_pathB7RISL(char *);

void quitB7RISL(char **);
void env(char **);

extern void non_interactiveB7RISL(void);
extern void initializerB7RISL(char **current_command, int type_command);

#endif
