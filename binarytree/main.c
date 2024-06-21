#include "tree.h"

int main() {
	node maintree = init(NULL);
	addel(&maintree, 10);
	addel(&maintree, 5);
	addel(&maintree, 6);
	addel(&maintree, 1);
	addel(&maintree, 4);
	addel(&maintree, 7);
	printDerevo(&maintree);
	deleteFunc(&maintree, 5);
	printf("\n");
	printDerevo(&maintree);


	return 0;
}


