#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 6

typedef struct User{
    char *name;
    int age;
}User;

void printArray(int *array, int arraySize) {

    int count;

    for(count = 0; count < arraySize; ++count) {
        printf("%d ", array[count]);
    }

    printf("\n");
}

int comparation(const void *a, const void *b) {

    int num1 = *(const int*) a;
    int num2 = *(const int*) b;

    if(num1 < num2) return -1;
    if(num1 > num2) return 1;

    return 0;
}

int comparationAge(const void *a, const void *b) {

    const User *userA = (const User *) a;
    const User *userB = (const User *) b;

    int ageA = userA->age;
    int ageB = userB->age;

    if(ageA < ageB) return -1;
    if(ageA > ageB) return 1;

    return 0;
}

void sortIntArrayExample() {
    int array[ARRAY_SIZE] = {6,4,5,2,1,3};
    printArray(array, ARRAY_SIZE);
    qsort(array, ARRAY_SIZE, sizeof(int), comparation);
    printArray(array, ARRAY_SIZE);
}

User* newUsers(int size) {
    return (User *) malloc(sizeof(User) * size);
}

User* createUser() {
    return newUsers(1);
}

User* createUserList(int size) {

    return newUsers(size);
}

int generateRandomAge() {
    return (rand() % 110) + 1;
}

void setRandomAge(User *user) {
    user->age = generateRandomAge();
}

void setRandomAgeList(User *users, int size) {

    int count;

    for(count = 0; count < size; ++count) {
        setRandomAge(&users[count]);
    }
}

void printfUserArray(User *users, int size) {
    int count;

    for(count = 0; count < size; ++count) {
        printf("%d ", users[count].age);
    }

    printf("\n");
}

void sortStructArrayExample() {

    int count;
    int numberOfUsers = 50;

    User *array = createUserList(numberOfUsers);

    setRandomAgeList(array, numberOfUsers);
    printfUserArray(array, numberOfUsers);
    qsort(array, numberOfUsers, sizeof(User), comparationAge);
    printfUserArray(array, numberOfUsers);
}

int main() {

    srand(time(NULL));

    sortIntArrayExample();
    sortStructArrayExample();

    return 0;
}
