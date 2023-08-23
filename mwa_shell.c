#include "shell.h"
/**
 * main - MAIN ARGUMENTS FUNCTIONS..
 * @ac: COUNT OF ARGUMENTS..
 * @av: ARGUMENTS..
 * @env: Environment
 * RETURN: _exit = 0.
 */
int main(int ac, char **av, char **env)

{
	int paTval = 0, status = 0, is_path = 0;
	char *line = NULL, /**ptr to INPT*/ **commands = NULL; /**the tokenized commands*/
	(void)ac;
	while (1)/* LOOP until EXIT */
	{
		errno = 0;
		line = _getline_command();/** READS user input*/
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			paTval++;
			commands = tokenize(line);/** TOKENIZES or parse user input*/
			if (!commands)
				free(line);
			if (!_strcmp(commands[0], "env"))/**CHECKS if user wrote env"*/
				_getenv(env);
			else
			{
				is_path = _values_path(&commands[0], env);/** tokenizes PATH*/
				status = _fork_fun(commands, av, env, line, paTval, is_path);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands); /*FREE up memory*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);/** Writes to standard output*/
			exit(status);
		}
		free(line);
	}
	return (status);
}
