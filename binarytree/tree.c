#include "tree.h"

node* findmin(node* parentnode);

node init(node* parent) {
	node parentnode = { 0 };
	parentnode.parent = parent;
	return parentnode;
}

void* memalloc(int size) {
	void* mem = malloc(size);
	if (!mem) {
		printf("error mem alloc");
		return 0;
	}
	return mem;
}

int addel(node* parentnode, int data) {
	if (!parentnode->data) {
		parentnode->data = memalloc(sizeof(int));
		if (!parentnode->data)return 0;
		*(parentnode->data) = data;
		return 1;
	}
	else if (*parentnode->data >= data) {
		if (!parentnode->left) {
			parentnode->left = memalloc(sizeof(node));
			if (!parentnode->left)return 0;
			*parentnode->left = init(parentnode);
		}
		return addel(parentnode->left, data);
	}
	else if (*parentnode->data < data) {
		if (!parentnode->right) {
			parentnode->right = memalloc(sizeof(node));
			if (!parentnode->right)return 0;
			*parentnode->right = init(parentnode);
		}
		return addel(parentnode->right, data);
	}
	else return 0;
}

node* findel(node* parentnode, int data) {
	if (*parentnode->data == data) {
		return parentnode;
	}
	else if (*parentnode->data > data) {
		if (!parentnode->left)return 0;
		return findel(parentnode->left, data);
	}
	else if (*parentnode->data < data) {
		if (!parentnode->right)return 0;
		return findel(parentnode->right, data);
	}
	else return 0;
}

int deleteFunc(node* parentnode, int data) {


	node* MyNode = findel(parentnode, data);
	if (!MyNode->left && !MyNode->right) {
		free(MyNode->data);
		if (MyNode == MyNode->parent->left)MyNode->parent->left = 0;
		if (MyNode == MyNode->parent->right)MyNode->parent->right = 0;
		return 1;
	}
	else {
		node* min = findmin(MyNode->right);
		*MyNode->data = *min->data;
		return deleteFunc(min, *min->data);
	}


}

node* findmin(node* parentnode) {

	if (!parentnode->left) {
		return parentnode;
	}
	else {
		return findmin(parentnode->left);
	}
}

int printDerevo(node* derevo) {
	if (!derevo) {
		return 0;
	}
	else printf("%d", *derevo->data);
	printDerevo(derevo->left);
	printDerevo(derevo->right);
}

