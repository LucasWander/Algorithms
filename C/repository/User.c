#include <stdlib.h>
#include "User.h"

struct User{
    char *name;
    char *birthDate;
    float weight;
    float height;
};


struct User* createUserEntity(){
    return (struct User*) malloc(sizeof(struct User));
}

struct User* createManyUsers(int numberOfUsers) {
    return (struct User*) malloc(sizeof(struct User) * 5);
}
