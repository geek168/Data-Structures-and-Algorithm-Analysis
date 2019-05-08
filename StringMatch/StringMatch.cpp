// StringMatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KMP.h"

int main()
{
	char buffer[MAX_LEN], pattern[MAX_LEN];
	int next[MAX_LEN];
	scanf("%s%s", buffer, pattern);
	get_next(pattern, next);
	int location = find(buffer, pattern, next);
	if (location != -1) {
		printf("match success, location is %d\n", location);
	}
	else {
		printf("match failed!\n");
	}
    return 0;
}

