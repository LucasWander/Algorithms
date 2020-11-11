#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "UserRepository.h"


struct UserRepositorySql {
    int (*createUser)(struct User*);
    struct User*(*getAllUsers)();
    struct User*(*getUser)(int);

    int description;
};


int createUserMysql(struct User *user) {
    printf("User sql\n");
}

struct User* getAllUsersMysql(){
    printf("User sql\n");
    return createManyUsers(5);
}

struct User* getAllUserMysql(int id){
    printf("User sql\n");
    return createUserEntity();
}

struct UserRepositorySql* createUserRepositoryMysql() {
    struct UserRepositorySql *userRepoMysql = malloc(sizeof(struct UserRepositorySql));

    userRepoMysql->createUser = createUserMysql;
    userRepoMysql->getAllUsers = getAllUsersMysql;
    userRepoMysql->getUser = getAllUserMysql;

    return userRepoMysql;
}
