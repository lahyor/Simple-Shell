#include "shell.h"

/**
 * _puts - Prints a string
 * @str: The string to print
 * Return: Void
 */

void _puts(char *str)
{
	size_t line;
	ssize_t num;

	line = _strlen(str);
	num = write(STDOUT_FILENO, str, line);
	if (num == -1)
	{
		perror("write");
	}
}

/**
 * _puterrors - Prints an error message
 * @err: The error message to print
 * Return: Void
 */

void _puterrors(char *err)
{
	size_t line;
	ssize_t num;

	line = _strlen(err);
	num = write(STDERR_FILENO, err, line);
	if (num == -1)
	{
		perror("write");
	}
}
