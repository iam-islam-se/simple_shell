#include "shell.h"


int parse_commandB7RISL(char *com)
{
	int k;
	char *l_com[] = {"env", "exit", NULL}, *pa = NULL;

	for (k = 0; com[k] != '\0'; k++)
	{
		if (com[k] == '/')
		{
			return (EL_COB7RISL);
		}
	}

	for (k = 0; l_com[k] != NULL; k++)
	{
		if (_strcmpB7RISL(com, l_com[k]) == 0)
		{
			return (L_CB7RISL);
		}
	}

	pa = check_pathB7RISL(com);

	if (pa != NULL)
	{
		free(pa);
		return (P_COMB7RISL);
	}

	return (D_NDB7RISL);
}



void execute_commandB7RISL(char **d_cd, int co_e)
{
	void (*ff)(char **lals);

	if (co_e == EL_COB7RISL)
	{
		if (execve(d_cd[0], d_cd, NULL) == -1)
		{
			perror(_getenvB7RISL("PWD"));
			exit(2);
		}
	}

	if (co_e == P_COMB7RISL)
	{
		if (execve(check_pathB7RISL(d_cd[0]), d_cd, NULL) == -1)
		{
			perror(_getenvB7RISL("PWD"));
			exit(2);
		}
	}

	if (co_e == L_CB7RISL)
	{
		ff = get_funcB7RISL(d_cd[0]);
		ff(d_cd);
	}
	if (co_e == D_NDB7RISL)
	{
		printB7RISL(shell_nameB7RISL, STDERR_FILENO);
		printB7RISL(": 1: ", STDERR_FILENO);
		printB7RISL(d_cd[0], STDERR_FILENO);
		printB7RISL(": not found\n", STDERR_FILENO);
		statusB7RISL = 127;
	}
}



char *check_pathB7RISL(char *c)
{
	char **p_ar = NULL;
	char *p, *p2, *p_cy;
	char *th = _getenvB7RISL("PATH");
	int s;

	if (th == NULL || _strlenB7RISL(th) == 0)
	{
		return (NULL);
	}

	p_cy = malloc(sizeof(*p_cy) * (_strlenB7RISL(th) + 1));

	_strcpyB7RISL(th, p_cy);

	p_ar = tokenizerB7RISL(p_cy, ":");

	for (s = 0; p_ar[s] != NULL; s++)
	{
		p2 = _strcatB7RISL(p_ar[s], "/");
		p = _strcatB7RISL(p2, c);

		if (access(p, F_OK) == 0)
		{
			free(p2);
			free(p_ar);
			free(p_cy);
			return (p);
		}
		free(p);
		free(p2);
	}
	free(p_cy);
	free(p_ar);
	return (NULL);
}


void (*get_funcB7RISL(char *n))(char **)
{
	int a;
	f_m mapping[] = {
		{"env", env}, {"exit", quitB7RISL}
	};

	for (a = 0; a < 2; a++)
	{
		if (_strcmpB7RISL(n, mapping[a].ba7r) == 0)
			return (mapping[a].ff);
	}
	return (NULL);
}

char *_getenvB7RISL(char *ne)
{
	char **m_en;
	char *p_p;
	char *n_c;

	for (m_en = environ; *m_en != NULL; m_en++)
	{
		for (p_p = *m_en, n_c = ne; *p_p == *n_c; p_p++, n_c++)
		{
			if (*p_p == '=')
			{
				break;
			}
		}
		if ((*p_p == '=') && (*n_c == '\0'))
		{
			return (p_p + 1);
		}
	}
	return (NULL);
}
