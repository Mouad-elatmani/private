#include "shell.h"
/**
 * main - Main function to run the SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: Exit status
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	if (is_terminal(STDIN_FILENO) == 0)
		run_non_interactive_mode(argv);
	else
		run_interactive_shell(argv);
	return (0);
}