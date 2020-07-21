#include "DBConnectionInterface.hpp"
#pragma once


class Store {

    private:
        DBConnectionInterface *dbConnection;

    public:
        Store(DBConnectionInterface *connection);

        void storeUser(User *user);

};
