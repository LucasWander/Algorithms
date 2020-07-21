#include "DBConnectionInterface.hpp"
#include <string>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>

#include <mysql-cppconn-8/jdbc/cppconn/driver.h>

#include <mysql-cppconn-8/jdbc/cppconn/exception.h>

#include <mysql-cppconn-8/jdbc/cppconn/prepared_statement.h>

class MysqlDB:public DBConnectionInterface
{
private:
    std::string server;
    std::string userName;
    std::string password;
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::PreparedStatement *pstmt;

public:
    MysqlDB(std::string server, std::string userName, std::string password);
    ~MysqlDB();

    void connect();
    void desconnect();
    void createUserTable();
    void insertUser(User *user);
};

