#include "shell.h"
/**
 * env - interact with env variables
 * Return: nothing
 */
void env(void)
{
	int ma;

	char newl = '\n';

	for (ma = 0; environ[ma] != NULL; ma++)
	{
		write(1, environ[ma], strlen(environ[ma]));
		write(1, &newl, 1);
	}
}
