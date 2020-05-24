typedef struct ListItem {

	int value;
	struct ListItem *next;
} ListItem;

void printListItem(ListItem item);
ListItem* listCreate();

ListItem* listInsertStart(ListItem *item, int value);

void listPrint(ListItem *item);

int listEmpty(ListItem *item);

ListItem* listSearch(ListItem * item, int value);

void listFree(ListItem *item);

int listLastValue(ListItem *item);

ListItem* listRemove(ListItem *item, int value);

