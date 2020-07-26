#include "DBConnectionInterface.hpp"
#include <postgresql/libpq-fe.h>
#include <string>
#include <iostream>

class PostgreDB: public DBConnectionInterface {

    private:
        std::string server;
        std::string userName;
        std::string password;
        std::string dbName;
        std::string port;
        std::string host;
        PGconn *conn;
        PGresult *res;

    public:
        PostgreDB(std::string server,std::string userName, std::string password,std::string dbName, std::string port, std::string host);
        void connect();
        void desconnect();
        void insertUser(User *user);
        void createUserTable();
};
