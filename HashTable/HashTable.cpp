// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hashtable.h"


int main()
{
	HashTable *hashtable = (HashTable*)malloc(sizeof(HashTable));
	init(hashtable, 2000);
	char buffer[1000];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", buffer);
		int ans = insert(hashtable, buffer);
		if (ans == 0) 
		{
			printf("recreate while insert!\n");
		}
		else if (ans == 1) 
		{
			printf("insert success!\n");
		}
		else if (ans == 2) 
		{
			printf("It already exists!\n");
		}
	}
	int temp_pos, temp_times;
	scanf("%s", buffer);
	if (search(hashtable, buffer, &temp_pos, &temp_times)) 
	{
		printf("search success!\n");
	}
	else 
	{
		printf("search failed!\n");
	}
	clear(hashtable);

    return 0;
}

