## Compile

    g++ teste.cpp -lssl -lcrypto -Wall -lmysqlcppconn


## Docker

    docker run --name some-mysql -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:8.0.20
