#ifndef SHELL_H
#define SHELL_H


#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


size_t _strncmp(char *string7, char *string8, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);
int lsh_ctrld(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
extern char **environ;
int lsh_exit(char **args);
int _strcmp(char *string7, char *string8);


void _exit_command(char **args, char *lineptr, int _exit);
int _fork_fun(char **arg, char **av, char **env,
char *liNptr, int np, int c);
char *_get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **tokenize(char *lineptr);

#endif /* SHELL_H */
