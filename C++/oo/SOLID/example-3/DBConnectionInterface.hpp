#include "User.hpp"
#pragma once

class DBConnectionInterface {

    public:
        virtual void connect() = 0;
        virtual void desconnect() = 0;

        virtual void createUserTable() = 0;
        virtual void insertUser(User *user) = 0;
};
