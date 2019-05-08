#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void get_next(char *pattern, int *next);

int find(char *buffer, char *pattern, int *next);
