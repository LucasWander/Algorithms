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
}