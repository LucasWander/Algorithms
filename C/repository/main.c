#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "UserRepository.h"
#include "UserRepositoryMongo.h"
#include "UserRepositorySql.h"


void createUser(struct UserRepository *userRepo) {
    userRepo->createUser(createUserEntity());
}



int main() {

    struct UserRepositoryMongo *repositoryMongodb = createUserRepositoryMongo("Hello");

    struct UserRepositorySql *repositoryMysql = createUserRepositoryMysql();


    printf("%s\n", getUserRepositoryMongoName(repositoryMongodb));

    setUserRepositoryMongoName(repositoryMongodb,"Ola");

    printf("%s\n", getUserRepositoryMongoName(repositoryMongodb));

    createUser((struct UserRepository*) repositoryMongodb);
    createUser((struct UserRepository*) repositoryMysql);

    return 0;
}
