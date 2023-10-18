#include "main.h"

/**
 * main - main function
 * Return: nothing
 */
int main(void);
int main(void)
{
	int ma = 0;
	char *input_line = NULL;
	size_t inputbuffsize = 0;
	size_t byteread = 0;
	char *parsedtoken = NULL;
	int interactive_mode = 1;
	char **args = malloc(10 * sizeof(char *));

	while (1)
	{
		interactive_mode = isatty(STDIN_FILENO);

		if (interactive_mode != 0)
			write(1, "$ ", 2);
		ma = 0;
		byteread = getline(&input_line, &inputbuffsize, stdin);
		parsedtoken = strtok(input_line, " \n\t\r");
		while (parsedtoken != NULL)
		{
			args[ma] = malloc(sizeof(char) * (strlen(parsedtoken) + 1));
			strcpy(args[ma], parsedtoken);
			ma++;
			parsedtoken = strtok(NULL, " \n\t\r");
		}
		if (ma == 0)
		{
			free(args);
			continue;
		}
		args[ma] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			freemem(args);
			break;
		}
		if (strcmp(args[0], "env") == 0)
		{
			env();
			freemem(args);
			continue;
		}
		if (interactive_mode == 0)
			break;
		_child(args);
		if (byteread > 1)
		{
			if (args[0] != NULL)
			{
				freemem(args);
			}
		}
	}
	if (input_line != NULL)
		free(input_line);
	return (0);
}
