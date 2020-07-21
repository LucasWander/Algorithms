#include "Store.hpp"

Store::Store(DBConnectionInterface *connection)
{
    this->dbConnection = connection;
    this->dbConnection->connect();
    this->dbConnection->createUserTable();
}


void Store::storeUser(User *user) {
    this->dbConnection->insertUser(user);
}
