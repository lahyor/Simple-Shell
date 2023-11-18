#include "shell.h"

/**
 * execute - Handle command lines with arguments
 * @argv: The argument vector
 * Return: The status of the executed commands
 */

int execute(char *argv[])
{
	pid_t sh;
	int stats = 0;
	char *path, *envs[2];

	if (argv == NULL || *argv == NULL)
		return (stats);
	if (check_for_builtin(argv))
		return (stats);

	sh = fork();
	if (sh < 0)
	{
		_puterrors("fork");
		return (1);
	}
	if (sh == -1)
		perror(argv[0]), free_tokens(argv), free_last_insert();
	if (sh == 0)
	{
		envs[0] = get_path();
		envs[1] = NULL;
		path = NULL;
		if (argv[0][0] != '/')
			path = find_in_path(argv[0]);
		if (path == NULL)
			path = argv[0];
		if (execve(path, argv, envs) == -1)
		{
			perror(argv[0]), free_tokens(argv), free_last_insert();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(sh, &stats, WUNTRACED);
		} while (!WIFEXITED(stats) && !WIFSIGNALED(stats));
	}
	return (stats);
}
