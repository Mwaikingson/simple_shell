#include "shell.h"
/**
 * _getline_command -  IT GEts THE inputs..
 * RETURN: THE Input..
 */

char *_getline_command(void)

{
	char *liNptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&liNptr, &charter_user, stdin) == -1)
	{
		free(liNptr);
		return (NULL);
	}

	return (liNptr);
}
