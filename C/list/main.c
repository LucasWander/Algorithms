#include <stdio.h>
#include "list.h"

int main() {

	ListItem *a;

	a = listInsertStart(a,1);
	a = listInsertStart(a,2);
	a = listInsertStart(a,3);
	a = listInsertStart(a,4);

	listPrint(a);

	return 0;
}