#pragma once
#include "User.h"

struct UserRepository {

    int (*createUser)(struct User*);
    struct User*(*getAllUsers)();
    struct User*(*getUser)(int);

};
