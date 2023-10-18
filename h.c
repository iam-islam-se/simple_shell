#include "shell.h"


char **tokenizerB7RISL(char *i_s, char *Ba7r)
{
	int n_d = 0;
	char **lac = NULL;
	char *en = NULL;
	char *e_p = NULL;

	en = _strtok_rB7RISL(i_s, Ba7r, &e_p);

	while (en != NULL)
	{
		lac = _reallocB7RISL(lac, sizeof(*lac) * n_d, sizeof(*lac) * (n_d + 1));
		lac[n_d] = en;
		en = _strtok_rB7RISL(NULL, Ba7r, &e_p);
		n_d++;
	}

	lac = _reallocB7RISL(lac, sizeof(*lac) * n_d, sizeof(*lac) * (n_d + 1));

	lac[n_d] = NULL;

	return (lac);
}


void printB7RISL(char *g, int sm)
{
	int o = 0;

	for (; g[o] != '\0'; o++)
	{
		write(sm, &g[o], 1);
	}
}

void remove_newlineB7RISL(char *r)
{
	int q = 0;

	while (r[q] != '\0')
	{
		if (r[q] == '\n')
		{
			break;
		}
		q++;
	}
	r[q] = '\0';
}



void _strcpyB7RISL(char *se, char *islamBa7r)
{
	int n = 0;

	for (; se[n] != '\0'; n++)
	{
		islamBa7r[n] = se[n];
	}
	islamBa7r[n] = '\0';
}



int _strlenB7RISL(char *ba7r)
{
	int islam = 0;

	if (ba7r == NULL)
		return (islam);
	for (; ba7r[islam] != '\0'; islam++)
		;
	return (islam);
}
