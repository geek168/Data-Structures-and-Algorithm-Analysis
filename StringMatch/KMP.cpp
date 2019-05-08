#include "KMP.h"


void get_next(char *pattern, int *next)
{
	next[0] = -1;
	for (int i = 1, match = -1; i < strlen(pattern); i++)
	{
		if (match >= 0 && pattern[match + 1] != pattern[i])
		{
			match = next[match];
		}
		if (pattern[match + 1] == pattern[i])
		{
			match++;
		}
		next[i] = match;
	}
}

int find(char *buffer, char *pattern, int *next)
{
	for (int i = 0, match = -1; i < strlen(buffer); i++)
	{
		if (match >= 0 && buffer[i] != pattern[match + 1])
		{
			match = next[match];
		}
		if (pattern[match + 1] == buffer[i])
		{
			match++;
		}
		if (match == strlen(pattern) - 1)
		{
			return i - match;
		}
	}
	return -1;
}