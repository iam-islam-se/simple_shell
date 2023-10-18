#include "shell.h"


	char **ba7rwithislam = NULL;
	char *lsaffe = NULL;
	char *shell_nameB7RISL = NULL;
	int statusB7RISL = 0;



int main(int argc __attribute__((unused)), char **axx)
{
	char **cu_co = NULL;
	int t, e_d = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handlerB7RISL);

	shell_nameB7RISL = axx[0];

	while (1)
	{
		non_interactiveB7RISL();

		printB7RISL(" ($) ", STDOUT_FILENO);

		if (getline(&lsaffe, &n, stdin) == -1)
		{
			free(lsaffe);
			exit(statusB7RISL);
		}
			remove_newlineB7RISL(lsaffe);
			remove_commentB7RISL(lsaffe);
			ba7rwithislam = tokenizerB7RISL(lsaffe, ";");

		for (t = 0; ba7rwithislam[t] != NULL; t++)
		{
			cu_co = tokenizerB7RISL(ba7rwithislam[t], " ");
			if (cu_co[0] == NULL)
			{
				free(cu_co);
				break;
			}
			e_d = parse_commandB7RISL(cu_co[0]);


			initializerB7RISL(cu_co, e_d);
			free(cu_co);
		}
		free(ba7rwithislam);
	}
	free(lsaffe);

	return (statusB7RISL);
}
