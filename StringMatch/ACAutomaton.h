#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char BASE_auomaton = 'a';
const int SIZE_auomaton = 26;
const int MAX_N = 20;
const int MAX_LEN_auomaton = 100000;

typedef struct Automaton
{
	int count;
	struct Automaton **childs;
	struct Automaton *fail;
} Auomaton;

Auomaton* new_auomaton_node();

void insert_auomaton(Auomaton* at, char *pattern);

void clear_auomaton(Auomaton* at);

void build_automaton(Automaton* root);

int match_count(Automaton* root, const char *buffer);