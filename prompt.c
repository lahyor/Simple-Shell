#include "shell.h"

/**
 * prompt - print the stream of shell to stdin
 * Return: Nothing
 */

void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
