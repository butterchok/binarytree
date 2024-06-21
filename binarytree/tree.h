#pragma once
#include <stdlib.h>
#include <stdio.h>



typedef struct Nodest {
	int* data;
	struct Nodest* left;
	struct Nodest* right;
	struct Nodest* parent;
}node;

node init(node* parent);
int addel(node* parentnode, int data);
node* findel(node* parentnode, int data);
int deleteFunc(node* parentnode, int data);
int printDerevo(node* derevo);


