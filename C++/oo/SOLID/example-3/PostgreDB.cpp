#include "PostgreDB.hpp"

PostgreDB::PostgreDB(std::string server, std::string userName, std::string password, std::string dbName, std::string port, std::string host)
{
    this->server = server;
    this->userName = userName;
    this->password = password;
    this->dbName = dbName;
    this->port = port;
    this->host = host;
}

void PostgreDB::connect()
{

    std::string connec = "postgresql://postgres@" + this->host + "?port=" + this->port + "&dbname=" + this->dbName + "&user=" + this->userName + "&password=" + this->password;
    this->conn = PQconnectdb(connec.c_str());

    if (PQstatus(this->conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit(0);
    }
}

void PostgreDB::desconnect()
{
    PQclear(this->res);

    PQfinish(this->conn);
}

void PostgreDB::createUserTable()
{
    res = PQexec(conn, "CREATE TABLE IF NOT EXISTS users (id serial PRIMARY KEY, name VARCHAR(50), age INTEGER);");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        std::cout << "Create table failed: " << PQresultErrorMessage(res)
                  << std::endl;
        PQclear(res);
        exit(0);
    }
    PQclear(res);
}

void PostgreDB::insertUser(User *user)
{
    std::string aux = "insert into users(name,age) values ('" + user->getName() + "'," + std::to_string(user->getAge()) + ")";

    this->res = PQexec(conn,
                       aux.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        std::cout << "Insert into table failed: " << PQresultErrorMessage(res)
                  << std::endl;
    }
    PQclear(res);
}
