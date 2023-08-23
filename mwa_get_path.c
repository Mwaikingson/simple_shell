#include "shell.h"
/**
 * _get_path - get VARIABLE PATH.
 * @env: ENVIROMENTE local..
 * RETURN: value of THE PATH..
 */

char *_get_path(char **env)

{
	size_t z = 0, var = 0, count = 5;
	char *path = NULL;

	for (z = 0; _strncmp(env[z], "PATH=", 5); z++)
		;
	if (env[z] == NULL)
		return (NULL);

	for (count = 5; env[z][var]; var++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[z][var]; var++, count++)
		path[count] = env[z][var];

	path[count] = '\0';
	return (path);
}
