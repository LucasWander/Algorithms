## Docker

    docker run -p 3306:3306 --name some-mysql -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:8.0.20
    docker run --name some-postgres -p 5432:5432 -e POSTGRES_PASSWORD=pass -d postgres:12.3

## Compile

    g++ main.cpp MysqlDB.cpp PostgreDB.cpp Store.cpp User.cpp  -lpq -lmysqlcppconn
