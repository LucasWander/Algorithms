#include "catch.hpp"
#include "../SinglyLinkedList.hpp"
#include "../User.hpp"

TEST_CASE("Should create a singly linked list", "[list]") {

    SinglyLinkedList *list = new SinglyLinkedList();

    SECTION("Should the list be empty") {

        REQUIRE(list->isEmpty() == true);
    }


    SECTION("Should the list not be empty after insert on the start") {

        User *user = new User();

        list->insertAtTheBeginning(user);

        REQUIRE(list->isEmpty() == false);
    }

    SECTION("Should throw a exception if try to remove from a empty list") {



        REQUIRE_THROWS_MATCHES(list->removeAtTheBeginning(), std::underflow_error, Catch::Matchers::Message("You can't remove from a empty list"));
    }

    SECTION("Should be empty after a insert and a remove at the beginning") {
        User *user = new User();

        list->insertAtTheBeginning(user);

        list->removeAtTheBeginning();

        REQUIRE(list->isEmpty() == true);
    }

    SECTION("Should get the head element of the list") {

        User *user = new User(1);
        list->insertAtTheBeginning(user);
        User *headUser = list->getHead();

        REQUIRE(headUser->id == 1);

        delete user;

        user = new User(2);
        list->insertAtTheBeginning(user);
        headUser = list->getHead();

        REQUIRE(headUser->id == 2);

    }


    SECTION("Should throw a exception if trying to get the head element on a empty list") {

        REQUIRE_THROWS_MATCHES(list->getHead(), std::underflow_error, Catch::Matchers::Message("You can't get the head element on a emptylist"));
    }

    SECTION("Should throw a exception if trying to get the tail element on a empty list") {
        REQUIRE_THROWS_MATCHES(list->getTail(), std::underflow_error, Catch::Matchers::Message("You can't get the tail element on a emptylist"));
    }

    SECTION("Should get the tail element of the list") {

        User *user = new User(1);
        list->insertAtTheBeginning(user);
        User *userTail = list->getTail();

        REQUIRE(userTail->id == 1);
    }

    SECTION("Should get the head element after two inserts and one remove at the beginning") {
        User *user = new User(1);
        User *user2 = new User(2);
        list->insertAtTheBeginning(user);
        list->insertAtTheBeginning(user2);

        list->removeAtTheBeginning();

        User *userHead = list->getHead();

        REQUIRE(userHead->id == 1);

    }
}
