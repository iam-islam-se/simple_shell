#include "shell.h"


int _strcmpB7RISL(char *islam, char *ba7r)
{
	int p = 0;

	while (islam[p] != '\0')
	{
		if (islam[p] != ba7r[p])
		{
			break;
		}
		p++;
	}
	return (islam[p] - ba7r[p]);
}


char *_strcatB7RISL(char *dion, char *ue)
{
	char *w_sg =  NULL;
	int len_dest = _strlenB7RISL(dion), n_e = _strlenB7RISL(ue);

	w_sg = malloc(sizeof(*w_sg) * (len_dest + n_e + 1));

	_strcpyB7RISL(dion, w_sg);

	_strcpyB7RISL(ue, w_sg + len_dest);

	w_sg[len_dest + n_e] = '\0';

	return (w_sg);
}


int _strspnB7RISL(char *ilas, char *vaa)
{
	int m = 0;
	int avs = 0;

	while (ilas[m] != '\0')
	{
		if (_strchrB7RISL(vaa, ilas[m]) == NULL)
		{
			break;
		}
		avs++;
		m++;
	}
	return (avs);
}


int _strcspnB7RISL(char *ba7r, char *islam)
{
	int lacd = 0, s;

	for (s = 0; ba7r[s] != '\0'; s++)
	{
		if (_strchrB7RISL(islam, ba7r[s]) != NULL)
		{
			break;
		}
		lacd++;
	}
	return (lacd);
}













/**
 *_strchrB7RISL - locates a char in a string
 *@s: string to be searched
 *@c: char to be checked
 *
 *Return: pointer to the first occurence of c in s
 */

char *_strchrB7RISL(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
