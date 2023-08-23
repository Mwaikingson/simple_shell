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

/* Custom STRING COMPARISON function */

size_t _strncmp(char *string7, char *string8, size_t n) {
    size_t z;

    for (z = 0; z < n; z++) {
        if (string7[z] != string8[z]) {
            return (unsigned char)string7[z] - (unsigned char)string8[z];
        }
        if (string7[z] == '\0') {
            return 0;  /* Reached the END of string7 */
        }
    }
    return 0;  /*STRINGS are equal up to n chars */
}
