#include "shell.h"

/**
 * handle_sigint - handle signal for SIGINT
 * @sign: number of signal
 * Return: Nothing
 */

void handle_sigint(int sign)
{
	(void) sign;
	_putchars('\n');
	prompt();
}

/**
 * handle_sigquit - handle signal for SIGQUIT
 * @sign: number of signal
 * Return: Nothing
 */

void handle_sigquit(int sign)
{
	(void) sign;
	_puterrors("Quit (core is dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigtstp - handle signal for SIGTSTP
 * @sign: number of signal
 * Return: Nothing
 */

void handle_sigtstp(int sign)
{
	(void) sign;
	_puts("\n");
	prompt();
}
