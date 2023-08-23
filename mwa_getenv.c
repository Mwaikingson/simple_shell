#include "shell.h"


/**
 * _getenv - PRINTS ENVIRONMENT TO STANDARD OUTPUT..
 *
 * @env: ENVIRONMENT..
 *
 */

void _getenv(char **env)

{
	size_t z = 0;

	while (env[z])
	{
		write(STDOUT_FILENO, env[z], _strlen(env[z]));
		write(STDOUT_FILENO, "\n", 1);
		z++;
	}
}
