#include "catch.hpp"
#include "../list.h"




TEST_CASE("List functions", "[List]") {

	ListItem *a = listCreate();


	SECTION("Testing tests","[list]") {

		ListItem a;

		a.value = 45;

		REQUIRE(a.value == 45);
	}

	SECTION("Create empty list","[list]") {

		REQUIRE(a == NULL);
	}

	SECTION("INSERT ON LIST START","[]") {

		a = listInsertStart(a,45);

		REQUIRE(a->value == 45);
	}



	SECTION("INSERT two items ON LIST START") {


		a = listInsertStart(a,45);
		a = listInsertStart(a,78);

		REQUIRE(a->value == 78);
		REQUIRE(a->next->value == 45);
	}


	SECTION("Insert three itens") {

		a = listInsertStart(a,45);
		a = listInsertStart(a,78);
		a = listInsertStart(a,-96);

		REQUIRE(a->value == -96);
		REQUIRE(a->next->value == 78);
		REQUIRE(a->next->next->value == 45);
	}

	SECTION("Test empty list") {
		REQUIRE(listEmpty(a)==1);
	}

	SECTION("Test not empty list") {

		a = listInsertStart(a,45);

		REQUIRE(listEmpty(a)==0);
	}

	SECTION("Should find value")  {
		a = listInsertStart(a, 78);
		a = listInsertStart(a, 89);
		a = listInsertStart(a, 656);
		a = listInsertStart(a, 66);

		SECTION("first value") {

			ListItem *search = listSearch(a, 66);

			REQUIRE(search != NULL);
			REQUIRE(search->value == 66);
		}

		SECTION("last value") {
			ListItem *search = listSearch(a, 78);

			REQUIRE(search != NULL);
			REQUIRE(search->value == 78);
		}

		SECTION("Dont have the value") {
			ListItem *search = listSearch(a,500);

			REQUIRE(search == NULL);
		}

	}

	SECTION("Shoudl have a free list ") {
		a = listInsertStart(a, 78);
		a = listInsertStart(a, 89);
		a = listInsertStart(a, 656);
		a = listInsertStart(a, 66);

		listFree(a);

		REQUIRE(a->value != 66);
	}

	SECTION("should test lastvalue function") {
		a = listInsertStart(a, 78);
		a = listInsertStart(a, 89);
		a = listInsertStart(a, 656);
		a = listInsertStart(a, 2);
		a = listInsertStart(a, 66);

		REQUIRE(listLastValue(a) == 78);
	}

	SECTION("Should test remove function") {
		a = listInsertStart(a, 78);
		a = listInsertStart(a, 89);
		a = listInsertStart(a, 656);
		a = listInsertStart(a, 2);
		a = listInsertStart(a, 66);

		SECTION("Remove start list") {
			a = listRemove(a,66);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 2);
		}

		SECTION("Remove end list") {
			a = listRemove(a,78);

			REQUIRE(a != NULL);
			REQUIRE(listLastValue(a) == 89);
		}

		SECTION("Remove in the middle") {
			a = listRemove(a,656);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 66);
			a = a->next;
			REQUIRE(a->value == 2);
			a = a->next;
			REQUIRE(a->value == 89);
			a = a->next;
			REQUIRE(a->value == 78);
		}

		SECTION("Don't remove") {
			a = listRemove(a,0);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 66);
			a = a->next;
			REQUIRE(a->value == 2);
			a = a->next;
			REQUIRE(a->value == 656);
			a = a->next;
			REQUIRE(a->value == 89);
			a = a->next;
			REQUIRE(a->value == 78);
		}
	}

	SECTION("Should insert at end of the list") {

		SECTION("empty list") {

			a = listInsertEnd(a, 3);

			REQUIRE(a != NULL);
			REQUIRE(a->next == NULL);
			REQUIRE(a->value == 3);
		}

		SECTION("insert 2 elements at end") {
			a = listInsertEnd(a,2);
			a = listInsertEnd(a,34);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 2);
			REQUIRE(a->next != NULL);
			REQUIRE(a->next->value == 34);
			REQUIRE(a->next->next == NULL);
		}

		SECTION("insert 10 itens") {
			a = listInsertEnd(a,2);
			a = listInsertEnd(a,3);
			a = listInsertEnd(a,4);
			a = listInsertEnd(a,5);
			a = listInsertEnd(a,6);
			a = listInsertEnd(a,7);
			a = listInsertEnd(a,8);
			a = listInsertEnd(a,9);
			a = listInsertEnd(a,10);
			a = listInsertEnd(a,11);

			REQUIRE(a != NULL);
			REQUIRE(listLastValue(a) == 11);
		}
	}

	SECTION("Should insert sorted") {

		SECTION("Insert one value") {
			a = listInsertSorted(a, 10);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 10);
			REQUIRE(a->next == NULL);
		}

		SECTION("Insert two values ,second bigger") {
			a = listInsertSorted(a, 2);
			a = listInsertSorted(a, 10);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 2);
			REQUIRE(a->next != NULL);
			REQUIRE(a->next->value == 10);
			REQUIRE(a->next->next == NULL);
		}

		SECTION("Insert two values ,second smaller") {
			a = listInsertSorted(a, 10);
			a = listInsertSorted(a, 2);

			REQUIRE(a != NULL);
			REQUIRE(a->value == 2);
			REQUIRE(a->next != NULL);
			REQUIRE(a->next->value == 10);
			REQUIRE(a->next->next == NULL);
		}

		SECTION("Insert 10 value") {
			a = listInsertSorted(a, 2);
			a = listInsertSorted(a, -65);
			a = listInsertSorted(a, -89);
			a = listInsertSorted(a, 12);
			a = listInsertSorted(a, 96);

			a = listInsertSorted(a, -9465);
			a = listInsertSorted(a, 987);
			a = listInsertSorted(a, 0);
			a = listInsertSorted(a, 0);
			a = listInsertSorted(a, -1);

			REQUIRE(a != NULL);
			REQUIRE(a->value == -9465);
			REQUIRE(a->next != NULL);
			REQUIRE(listLastValue(a) == 987);
		}

	}
}
