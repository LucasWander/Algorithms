#include <iostream>
#include <string>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>

#include <mysql-cppconn-8/jdbc/cppconn/driver.h>

#include <mysql-cppconn-8/jdbc/cppconn/exception.h>

#include <mysql-cppconn-8/jdbc/cppconn/prepared_statement.h>

/* #include <mysql-cppconn-8/mysql/jdbc.h> */

using namespace std;

const string server = "tcp://0.0.0.0:3306";
const string username = "root";
const string password = "my-secret-pw";

int main () {

    /* g++ teste.cpp -lssl -lcrypto -Wall -lmysqlcppconn */
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::PreparedStatement *pstmt;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //please create database "quickstartdb" ahead of time


    con->setSchema("TestCpp");

    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory");
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
    cout << "Finished creating table" << endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "apple");
    pstmt->setInt(2, 100);
    pstmt->execute();
    cout << "One row inserted." << endl;

    delete pstmt;
    delete con;
    return 0;
}
