#include "shell.h"

#define PROMPT "simple_shell$ "

/**
 * interp - Entry point
 * @argc: Number of argumets
 * @argv: Array of argumets
 * Return: Always 0 (success)
 */

int interp(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	char **args;

	while (1)
	{
		printf("%s", PROMPT);
		ssize_t bytes_read = getline(&line, *len, stdin);

		if (bytes_read == -1)
		{
			printf("\n");
			exit(0);
		}

		line[strlen(line) - 1] = '\0';
		args = strtok(line, " ");

		if (args[0] != NULL)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("simple_shell");
				printg("%s", PROMPT);
				continue;
			}
		}

		free(line);
		line = NULL;
	}

	return (0);
}
