#include <stdio.h>
#include <stdlib.h>

typedef struct SBTNode
{
	int data, size;
	struct SBTNode *lchild, *rchild, *father;
} SBTNode;

#define ERROR 0
#define OK 1

void init_NIL();

SBTNode* init(int data, int size, SBTNode *father);

SBTNode * left_rotate(SBTNode * node);

SBTNode * right_rotate(SBTNode * node);

SBTNode* insert_tree(SBTNode *node, int data);

int delete_tree(SBTNode *node, int data);

SBTNode* search(SBTNode *node, int data);

SBTNode* predecessor(SBTNode *node);

SBTNode* successor(SBTNode *node);

SBTNode * maintain(SBTNode * node, int flag);

void remove_node(SBTNode *delete_node);

SBTNode* add_node(SBTNode *node, int data);

void clear(SBTNode *node);

void output(SBTNode *node);
