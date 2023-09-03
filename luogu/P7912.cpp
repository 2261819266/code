#include <cstdio>

struct Block {
	int l, r;
};

struct Node {
	Block a;
	Node *next, *last;
} head;

