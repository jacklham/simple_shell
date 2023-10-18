#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * freemem - frees memory
 * Return: nothing
 */
void freemem(void)
{
	int *ptr = malloc(10 * sizeof(int));

	if (ptr == NULL)
	{
		write(1, "Memory not allocated.\n", strlen("Memory not allocated.\n"));
		exit(0);
	}
	else
	{
		write(1, "Memory successfully allocated using malloc.\n",
				strlen("Memory successfully allocated using malloc.\n"));

		free(ptr);
		write(1, "Malloc Memory successfully freed.\n",
				strlen("Malloc Memory successfully freed.\n"));
	}
}
