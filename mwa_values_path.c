#include "shell.h"
/**
 * _values_path - SEPARATE THE PATH in new strings..
 * @arg: COMMAND Input of USER..
 * @env: Enviroment..
 * Return: POINTER to strings..
 */
int _values_path(char **arg, char **env)

{
	char *tok = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, len;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rela = _get_path(env);/** GETS THE content of "PATH="*/
	if (!path_rela)
		return (-1);
	tok = strtok(path_rela, ":"); /**TOKENIZES the content of "PATH="*/
	len = _strlen(*arg); /**gets length of arg*/
	while (tok)
	{
		value_path = _strlen(tok);
		path_absol = malloc(sizeof(char) * (value_path + len + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = strcpy(path_absol, tok);
		_strcat(path_absol, "/");
		_strcat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		tok = strtok(NULL, ":");
	}
	tok = '\0';
	free(path_rela);
	return (-1);
}
