#include "shell.h"

#define PROMPT "simple_shell$"

/**
 * interp - Entry point
 * @argc: Number of artguments
 * @argv: Array of argumentss
 * Return: Always 0 (success)
 */

int interp(int args, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	char **args;

	while (1)
	{
		printf("%s", PROMPT);
		ssize_t bytes_read = getline(&line, &len, stdin);

		if (bytes_read == -1)
		{
			printf("\n");
			exit(0);
		}

		line[strlen(line) - 1] = '\0';
		args = tokenize(line);

		if (args[0] != NULL)
		{
			if (exec_command(args) == -1)
			{
				perror("simple_shell");
				printf("%s", PROMPT);
				continue;
			}
		}

		free(args);
		free(line);
		line = NULL;
	}

	return (0);
}

/**
 * tokenize - Tokenize input line
 * @line: Input line
 *
 * Return: Array of tokens
 */

char **tokenize(char *line)
{
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(line, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return(args);
}

/**
 * exec_command - Execute the command
 * @args: Array of command
 *
 * Return: Always 0 (success)
 */

int exec_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
	} else if (pid < 0)
	{
		perror("fork");
		return (-1);
	} else
	{
		wait(NULL);
	}

	return (0);
}
