#include "catch.hpp"
#include "../Stack.hpp"

TEST_CASE( "Should create a stack", "[Stack]" ) {

   Stack *myStack = new Stack();

   SECTION("Is new stack empty") {
      REQUIRE(myStack->isEmpty() == true);
   }

   SECTION("Stack should not be empty after a insert") {

      myStack->push(45);

      REQUIRE(myStack->isEmpty() == false);
   }

   SECTION("Should throw an underflow exception if the stack is empty") {

      REQUIRE_THROWS_MATCHES(myStack->pop(),std::underflow_error, Catch::Matchers::Message("You can't pop a empty stack"));
   }

   SECTION("Stack should be empty a push and a pop") {
      myStack->push(45);
      myStack->pop();

      REQUIRE(myStack->isEmpty() == true);
   }

   SECTION("Stack should not be empty after two pushs and one pop") {
      myStack->push(45);
      myStack->push(42);
      myStack->pop();

      REQUIRE(myStack->isEmpty() == false);
   }

   SECTION("Should poped element be equal to the last pushed element") {
      myStack->push(42);
      REQUIRE(myStack->pop() == 42);
      myStack->push(48);
      REQUIRE(myStack->pop() == 48);
   }

   SECTION("After pus x and y should pop y and x") {
      myStack->push(42);
      myStack->push(48);
      REQUIRE(myStack->pop() == 48);
      REQUIRE(myStack->pop() == 42);
   }

   SECTION("Should get the land pushed element") {
      myStack->push(42);

      REQUIRE(myStack->top() == 42);

      myStack->push(52);

      REQUIRE(myStack->top() == 52);
   }

   SECTION("After push x and y, pop y should x be the top element") {

      myStack->push(42);
      myStack->push(48);
      myStack->pop();

      REQUIRE(myStack->top() == 42);
   }

   SECTION("Should throw an exception if top is called on a empty stack") {
      REQUIRE_THROWS_MATCHES(myStack->top(),std::underflow_error, Catch::Matchers::Message("You can't get the top element on a empty stack"));
   }

   SECTION("Max elements should be 50") {
      int size = Stack::MAX_SIZE;
      REQUIRE(size == 50);
   }


   SECTION("After push 50 elements, should throw an exception if try push again") {

      for(int i = 0; i < 50; i++)
         myStack->push(50);

      REQUIRE_THROWS_MATCHES(myStack->push(50),std::overflow_error, Catch::Matchers::Message("You can't stack more than 50 elements"));
   }

   SECTION("Should not be full if insert an element and should be full if insert 50 elements") {
      myStack->push(50);

      REQUIRE(myStack->isFull() == false);

      for(int i = 0; i < 49; i++)
         myStack->push(50);

      REQUIRE(myStack->isFull() == true);
   }
}
