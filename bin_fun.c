#include "shell.h"

void env(char **tokenized_command __attribute__((unused)))
{
	int w;

	for (w = 0; environ[w] != NULL; w++)
	{
		printB7RISL(environ[w], STDOUT_FILENO);

		printB7RISL("\n", STDOUT_FILENO);
	}
}


void quitB7RISL(char **id_cd)
{
	int m_n = 0, acc;

	for (; id_cd[m_n] != NULL; m_n++)
		;
	if (m_n == 1)
	{
		free(id_cd);
		free(lsaffe);
		free(ba7rwithislam);
		exit(statusB7RISL);
	}
	else if (m_n == 2)
	{
		acc = _atoiB7RISL(id_cd[1]);
		if (acc == -1)
		{
			printB7RISL(shell_nameB7RISL, STDERR_FILENO);
			printB7RISL(": 1: exit: Illegal number: ", STDERR_FILENO);
			printB7RISL(id_cd[1], STDERR_FILENO);
			printB7RISL("\n", STDERR_FILENO);
			statusB7RISL = 2;
		}
		else
		{
			free(lsaffe);
			free(id_cd);
			free(ba7rwithislam);
			exit(acc);
		}
	}
	else
	{
		printB7RISL("$: exit doesn't take more than one argument\n", STDERR_FILENO);
	}
}
