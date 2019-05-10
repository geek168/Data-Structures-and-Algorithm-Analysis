// StringMatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KMP.h"
#include "trietree.h"

int main()
{
	//char buffer[MAX_LEN], pattern[MAX_LEN];
	//int next[MAX_LEN];
	//scanf("%s%s", buffer, pattern);
	//get_next(pattern, next);
	//int location = find(buffer, pattern, next);
	//if (location != -1) {
	//	printf("match success, location is %d\n", location);
	//}
	//else {
	//	printf("match failed!\n");
	//}

	Trie root = new_node();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char pattern[100];
		scanf("%s", pattern);
		insert(root, pattern);
	}
	char buffer[100];
	scanf("%s", buffer);
	if (find(root, buffer)) {
		printf("String is found.\n");
	}
	else {
		printf("String is not found.\n");
	}
	clear(root);

    return 0;
}

