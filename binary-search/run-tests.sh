#/bin/bash

mkdir testing/build
make --file=testing/makefile
./testing/build/BINARY_SEARCH_TEST
