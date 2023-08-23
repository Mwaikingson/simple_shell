#include "shell.h"
/**
 * tokenize - TOKENIZES a stirng..
 * @lineptr: what THE USER INPUTED..
 * Return: a PTR to ARR of PTRS
 */

char **tokenize(char *lineptr)

{
	char **user_command = NULL;
	char *token = NULL;
	size_t o = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (o = 0; lineptr[o]; o++)
	{
		if (lineptr[o] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = strtok(lineptr, " \n\t\r");

	for (o = 0; token != NULL; o++)
	{
		user_command[o] = token;
		token = strtok(NULL, " \n\t\r");
	}
	user_command[o] = NULL;
	return (user_command);
}
