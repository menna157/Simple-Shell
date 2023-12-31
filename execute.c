#include "shell.h"

/**
 * execute - executes commands entered by users
 * @cp: command
 * @cmd:vector array of pointers to commands
 * Return: 0
 */
void execute(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;
/* fork function */
	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
