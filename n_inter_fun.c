#include "shell.h"


void non_interactiveB7RISL(void)
{
	char **t_cand = NULL;
	int z, te_co = 0;
	size_t l = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&lsaffe, &l, stdin) != -1)
		{
			remove_newlineB7RISL(lsaffe);
			remove_commentB7RISL(lsaffe);
			ba7rwithislam = tokenizerB7RISL(lsaffe, ";");
			for (z = 0; ba7rwithislam[z] != NULL; z++)
			{
				t_cand = tokenizerB7RISL(ba7rwithislam[z], " ");
				if (t_cand[0] == NULL)
				{
					free(t_cand);
					break;
				}
				te_co = parse_commandB7RISL(t_cand[0]);
				initializerB7RISL(t_cand, te_co);
				free(t_cand);
			}
			free(ba7rwithislam);
		}
		free(lsaffe);
		exit(statusB7RISL);
	}
}
