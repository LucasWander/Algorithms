# Linked list

Linked list example width testing using [Catch2](https://github.com/catchorg/Catch2)


```c
typedef struct ListItem {
	int value;
	struct ListItem *next;
} ListItem;
```


# Usage

## Command to run the example

```bash
make
```

## Command to run the tests

```bash
make --file=testing/makefile
```


# TODOs

- [ x ] Insert at linked list start
- [ x ] Print all items
- [ x ] Test for empty list
- [ x ] Linear search
- [ x ] Free the memory
- [ x ] Get linked list last value
- [ x ] Remove item by value from linked list
- [ x ] Insert at end
- [ x ] Insert sorted

