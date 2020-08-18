# Testing

Testing example using [Catch2](https://github.com/catchorg/Catch2)

# Usage


## Command to run the tests

```bash
g++ test/main-test.cpp -c -o test/main-test.o

g++ factorial.c -c

g++ test/main-test.o factorial.o test/test-factorial.cpp -o tests.out

./tests.out -r compact
```
