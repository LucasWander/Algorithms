#include "MysqlDB.hpp"

MysqlDB::MysqlDB(std::string server, std::string userName, std::string password)
{
    this->server = server;
    this->userName = userName;
    this->password = password;
}

MysqlDB::~MysqlDB()
{
    this->desconnect();
}


void MysqlDB::connect() {
    try
    {
        this->driver = get_driver_instance();
        this->con = driver->connect(this->server, this->userName, this->password);
        con->setSchema("TestCpp");

    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        exit(1);
    }
}

void MysqlDB::createUserTable() {

    this->stmt = con->createStatement();

/*     stmt->execute("DROP TABLE IF EXISTS users");
    std::cout << "Finished dropping table (if existed)" << std::endl; */

    stmt->execute("CREATE TABLE IF NOT EXISTS users (id serial PRIMARY KEY, name VARCHAR(50), age INTEGER);");
    std::cout << "Finished creating table" << std::endl;
    delete stmt;
}

void MysqlDB::insertUser(User *user) {
    pstmt = con->prepareStatement("INSERT INTO users(name, age) VALUES(?,?)");
    pstmt->setString(1, user->getName());
    pstmt->setInt(2, user->getAge());
    pstmt->execute();
    std::cout << "One row inserted." << std::endl;
}

void MysqlDB::desconnect() {
    delete this->pstmt;
    delete this->con;
}
