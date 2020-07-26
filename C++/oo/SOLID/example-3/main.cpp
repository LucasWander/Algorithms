#include <iostream>
#include "Store.hpp"
#include "MysqlDB.hpp"
#include "PostgreDB.hpp"


const std::string server = "tcp://0.0.0.0:3306";
const std::string username = "root";
const std::string password = "my-secret-pw";

int main() {

    MysqlDB *myDB = new MysqlDB(server, username, password);
    PostgreDB *postDB = new PostgreDB("0.0.0.0","postgres", "pass", "rate-races", "5432", "0.0.0.0");

    Store *store = new Store(myDB);
    Store *store2 = new Store(postDB);

    User *user = new User((std::string)"Wander", 21);


    store->storeUser(user);
    store2->storeUser(user);

    return 0;
}
