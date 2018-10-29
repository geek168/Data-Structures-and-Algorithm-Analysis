#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable
{
	char **elem;
	int size;
} HashTable;

void init(HashTable *h, int size);
int hash(HashTable *h, char value[]);
int search(HashTable *h, char value[], int *pos, int *times);
void recreate(HashTable *h);
int insert(HashTable *h, char value[]);
void clear(HashTable *h);
