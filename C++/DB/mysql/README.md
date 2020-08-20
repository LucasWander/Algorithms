# Mysql

Connecting to a mysql database
```c++
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
```

# Usage

You need to have a mysql database on your machine. The best away is using [docker](https://www.docker.com/).

### With [docker](https://www.docker.com/) instaled you can run

```bash

# Create the mysql container
docker run -p 3306:3306 --name some-mysql -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:8.0.20
```

You also need to install this one package that contains the libraries to connect to the database

- [For mysql](https://dev.mysql.com/doc/connector-cpp/8.0/en/connector-cpp-introduction.html): **sudo apt-get install libboost-all-dev && sudo apt-get install libmysqlcppconn-dev** 

## Commands to run the example

```bash
# -lmysqlcppconn tells the compiler to link the mysql library

g++ main.cpp -lmysqlcppconn
./a.out
```
