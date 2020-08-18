# Binary search #

**Binary search** on integer array with testing using [Catch2](https://github.com/catchorg/Catch2)

```c
int binarySearch(float *arr, int size, float value) {

	int middle;

	int start = 0;
	int end = size-1;

	while(start <= end) {

		middle = (start + end) / 2;

		if(arr[middle] == value) {
			return middle;
		}

		if(arr[middle] > value) {
			end = middle - 1;
		}

		if(arr[middle] < value) {
			start = middle + 1;
		}

	}


	return -1;
}
```


# Usage

## Command to run the example

```bash
make
./build/BINARY_SEARCH
```

Or you can run this command but need to have bash instaled

```bash
./run-project.sh
```

## Command to run the tests

```bash
make --file=testing/makefile
./testing/build/BINARY_SEARCH_TEST
```

Or you can run this command but need to have bash instaled

```bash
./run-tests.sh
```

## TODOs

- [ ] Force folder creation
