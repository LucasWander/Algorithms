# Binary search # 

## Testing

    g++ search.c -c
    g++ testing/main-test.o search.o testing/search.test.cpp -o tests.out
    ./tests.out -r compact