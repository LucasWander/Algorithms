#include <stdlib.h>
#include <stdio.h>
#include "User.h"
#include "UserRepositoryMongo.h"


struct UserRepositoryMongo {
    int (*createUser)(struct User*);
    struct User*(*getAllUsers)();
    struct User*(*getUser)(int);

    char *name;
};

int createUserMongo(struct User *user) {
    printf("User Mongo\n");
}

struct User* getAllUsersMongo(){

    printf("User Mongo\n");
    return createManyUsers(6);
}

struct User* getUserMongo(int id){
    printf("User Mongo\n");
    return createUserEntity();
}

char* getUserRepositoryMongoName(struct UserRepositoryMongo *repositoryMongodb) {
    return repositoryMongodb->name;
}

void setUserRepositoryMongoName(struct UserRepositoryMongo *repositoryMongodb, char *name) {
    repositoryMongodb->name = name;
}

struct UserRepositoryMongo* createUserRepositoryMongo(char *name) {
    struct UserRepositoryMongo *userRepoMongo = malloc(sizeof(struct UserRepositoryMongo));

    userRepoMongo->createUser = createUserMongo;
    userRepoMongo->getAllUsers = getAllUsersMongo;
    userRepoMongo->getUser = getUserMongo;
    userRepoMongo->name = name;

    return userRepoMongo;
}
