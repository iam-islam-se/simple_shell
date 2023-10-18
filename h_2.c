#include "shell.h"


char *_strtok_rB7RISL(char *Ba7r, char *ISlam, char **s_p)
{
	char *h;

	if (Ba7r == NULL)
	{
		Ba7r = *s_p;
	}

	if (*Ba7r == '\0')
	{
		*s_p = Ba7r;
		return (NULL);
	}

	Ba7r += _strspnB7RISL(Ba7r, ISlam);

	if (*Ba7r == '\0')
	{
		*s_p = Ba7r;
		return (NULL);
	}

	h = Ba7r + _strcspnB7RISL(Ba7r, ISlam);

	if (*h == '\0')
	{
		*s_p = h;
		return (Ba7r);
	}

	*h = '\0';
	*s_p = h + 1;
	return (Ba7r);
}


int _atoiB7RISL(char *as)
{
	unsigned int y = 0;

	do {
		if (*as == '-')
		{
			return (-1);
		}
		else if ((*as < '0' || *as > '9') && *as != '\0')
		{
			return (-1);
		}
		else if (*as >= '0'  && *as <= '9')
		{
			y = (y * 10) + (*as - '0');
		}
		else if (y > 0)
		{
			break;
		}
	} while (*as++);
	return (y);
}


void *_reallocB7RISL(void *ac, unsigned int de, unsigned int n_ze)
{
	void *ba7r;
	unsigned int b;

	if (ac == NULL)
	{
		ba7r = malloc(n_ze);
		return (ba7r);
	}
	else if (n_ze == de)
	{
		return (ac);
	}
	else if (n_ze == 0 && ac != NULL)
	{
		free(ac);
		return (NULL);
	}
	else
	{
		ba7r = malloc(n_ze);
		if (ba7r != NULL)
		{
			for (b = 0; b < min(de, n_ze); b++)
			{
				*((char *)ba7r + b) = *((char *)ac + b);
			}
			free(ac);
			return (ba7r);
		}
		else
		{
			return (NULL);
		}
	}
}



void ctrl_c_handlerB7RISL(int ba7r)
{
	if (ba7r == SIGINT)
		printB7RISL("\n($) ", STDIN_FILENO);
}


void remove_commentB7RISL(char *islam)
{
	int t = 0;

	if (islam[t] == '#')
	{
		islam[t] = '\0';
	}
	while (islam[t] != '\0')
	{
		if (islam[t] == '#' && islam[t - 1] == ' ')
		{
			break;
		}
		t++;
	}
	islam[t] = '\0';
}
