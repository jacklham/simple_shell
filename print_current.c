#include "shell.h"

/**
 * main - main function
 * Return: nothing
 */
int main(void);
int main(void)
{
	int m = 0;
	char *input_line = NULL;
	size_t inputbuffsize = 0;
	size_t byteread = 0;
	char *parsedtoken = NULL;
	int interactive = 1;
	char **args = malloc(10 * sizeof(char *));

	while (1)
	{
		interactive = isatty(STDIN_FILENO);

		if (interactive != 0)
			write(1, "$ ", 2);
		m = 0;
		byteread = getline(&input_line, &inputbuffsize, stdin);
		parsedtoken = strtok(input_line, " \n\t\r");
		while (parsedtoken != NULL)
		{
			args[m] = malloc(sizeof(char) * (strlen(parsedtoken) + 1));
			strcpy(args[m], parsedtoken);
			m++;
			parsedtoken = strtok(NULL, " \n\t\r");
		}
		if (m == 0)
		{
			/*free(args);*/
			continue;
		}
		args[m] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			free(input_line);
			input_line = NULL;
			for (m = 0; args[m]; m++)
				free(args[m]);
			free(args);
			args = NULL;
			exit(1);
		}
		if (strcmp(args[0], "env") == 0)
		{
			env();
			/*free(args);*/
			continue;
		}
		_child(args);
		if (interactive == 0)
			break;
		if (byteread > 1)
		{
			if (args[0] != NULL)
			{
				/*free(args);*/
			}
		}
	}
	if (input_line != NULL)
		free(input_line);
	return (0);
}
