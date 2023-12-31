#include "shel.h"
/**
 * _exit - Function to exit the program.
 * @line: User input.
 * @status: Pointer to process status.
 * @count: Count of commands.
 * @prog_name: Program name.
 * @message: Line message.
 * Return: Exit status.
 */
int cu_exit(char *line, int *status, int count, char *prog_name, char *message)
{
	int exit_status = 0, valide = 1, i, len;
	char *status_str, *line_copy;

	line_copy = _strdup(line);
	line_copy = _string_tokenize(line_copy, " ");
	status_str = _string_tokenize(NULL, " ");
	if (!status_str)
	{
		free(message);
		free(line_copy);
		exit(*status);
	}
	len = _strlen(status_str);
	if (status_str != NULL)
	{
		if (status_str[0] == '-')
			valid = 0;
		for (int i = 0; i < len; i++)
		{
			if (!(status_str[i] >= '0' && status_str[i] <= '9'))
			{
				valid = 0;
				break;
			}
		}
		if (valid)
		{
			exit_status = _atoi(status_str);
			free(line);
			free(line_copy);
			exit(exit_status);
		}
		else
		{
			*status = 2;
			print_cu_error(prog_name, count, *status, message);
			free(line_copy);
		}
		return (exit_status);
	}
}
