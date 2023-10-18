#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;
void _child(char **args);
void freemem(char **args);
void env(void);

#endif
