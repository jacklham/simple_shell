#include "shell.h"
/**
 * _child - gets the child process
 * @args: double pointer
 * Return: nothing
 */
void _child(char **args)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("./hsh");
	}
	else
	{
		wait(&status);
	}
}
