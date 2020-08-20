# Example 3

- [Liskov substitution principle](https://en.wikipedia.org/wiki/Liskov_substitution_principle),
- [Dependency inversion principle](https://en.wikipedia.org/wiki/Dependency_inversion_principle)
- [Open–closed principle](https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle)


```cpp
MysqlDB *myDB = new MysqlDB(server, username, password);

PostgreDB *postDB = new PostgreDB(server,username, password, database, port);

Store *store = new Store(myDB);
Store *store2 = new Store(postDB);

User *user = new User((std::string)"Wander", 21);


store->storeUser(user);
store2->storeUser(user);
```


# Usage

You need to have a mysql database and a postgresql database on your machine. The best away is using [docker](https://www.docker.com/).

### With [docker](https://www.docker.com/) instaled you can run

```bash

# Create the mysql container
docker run -p 3306:3306 --name some-mysql -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:8.0.20

# Create the postres container
docker run --name some-postgres -p 5432:5432 -e POSTGRES_PASSWORD=pass -d postgres:12.3
```

You also need to install this two packages that contains the libraries to connect to the databases

- [For mysql](https://dev.mysql.com/doc/connector-cpp/8.0/en/connector-cpp-introduction.html): **sudo apt-get install libboost-all-dev**
- [For postgresql](https://www.postgresql.org/docs/12/libpq.html): **sudo apt-get install -y libpq-dev**

## Commands to run the example

```bash
# -lpg tells the compiler to link the postgresql library
# -lmysqlcppconn tells the compiler to link the mysql library

g++ main.cpp MysqlDB.cpp PostgreDB.cpp Store.cpp User.cpp  -lpq -lmysqlcppconn
```
