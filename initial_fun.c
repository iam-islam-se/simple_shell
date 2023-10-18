#include "shell.h"


void initializerB7RISL(char **t_a, int e_cd)
{
	pid_t PIDB7R;

	if (e_cd == EL_COB7RISL || e_cd == P_COMB7RISL)
	{
		PIDB7R = fork();
		if (PIDB7R == 0)
		{
			execute_commandB7RISL(t_a, e_cd);
		}
		else
		{
			waitpid(PIDB7R, &statusB7RISL, 0);
			statusB7RISL >>= 8;
		}
	}
	else
	{
		execute_commandB7RISL(t_a, e_cd);
	}
}
