#include "shell.h"
int lsh_exit(char **args);
int lsh_ctrld(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);


/*
 *LIST OF BUILT IN COMMANDS, FoLLowed by Their corresponding Functions..
 */
char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&lsh_cd, &lsh_help, &lsh_exit, &lsh_ctrld};

/**
 * lsh_num_builtins - SIZE
 * RETURN: size
 */

int lsh_num_builtins(void)

{
	return (sizeof(builtin_str) / sizeof(char *));
}

/*
 *BUILTIN FUNCTION Implementations..
*/

/**
 * lsh_cd - Builtin TO change Dirs..
 * @args: List of args.  args[0] is "cd".  args[1] is the DIRECTORY..
 * RETURN: 1 on success
 */
int lsh_cd(char **args)

{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * lsh_help - PRINTS THE HELP OF THE SHELL..
 * @args: List of args.  NOT EXAMINED..
 * Return: ALWAYS RETURNS 1, to continue Executing..
 */
int lsh_help(char **args)

{
	int z;

	printf("Oscar Bedat and Andres Henderson\n");
	printf("If you need help, call 1-800-help\n");
	(void)args;
	for (z = 0; z < lsh_num_builtins(); z++)
	{
		printf("  %s\n", builtin_str[z]);
	}

	return (1);
}

/**
 * lsh_exit - BUILTIN TO exit the shell..
 * @args: List of args.  NOT EXAMINED..
 * RETURN: ALWAYS returns 0, to TERMINATE execution..
 */
int lsh_exit(char **args)

{
	(void)args;
	free(args);
	return (200);
}

/**
 * lsh_ctrld - BUILTIN to handle "^D" CALL..
 * @args: List of args.  Not examined.
 * RETURN: ALWAYS RETURNS 0, to terminate Execution..
 */
int lsh_ctrld(char **args)

{
	(void)args;
	free(args);
	return (200);
}

/**
 *_fork_fun - foo THAT CREATE A FORK..
 *@arg: COMMAND AND VALUES path.
 *@av: HAS THE NAME of our program..
 *@env: THE Environment
 *@lineptr: COMMAND LINE for the user.
 *@np: ID of proces.
 *@c: CHECKER add new test..
 *RETURN: 0 success
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)

{

	pid_t child;
	int status, z = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (z = 0; z < lsh_num_builtins(); z++)
	{
		if (strcmp(arg[0], builtin_str[z]) == 0)
			return (builtin_func[z](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
