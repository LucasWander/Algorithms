# Postgresql

Connecting to a postgresql database
```c
conn = PQconnectdb(conninfo);

/* Check to see that the backend connection was successfully made */
if (PQstatus(conn) != CONNECTION_OK)
{
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exit_nicely(conn);
}
...
```

# Usage

You need to have a postgresql database on your machine. The best away is using [docker](https://www.docker.com/).

### With [docker](https://www.docker.com/) instaled you can run

```bash
# Create the postres container
docker run --name some-postgres -p 5432:5432 -e POSTGRES_PASSWORD=pass -d postgres:12.3
```

You also need to install this one package that contains the libraries to connect to the database

- [For postgresql](https://www.postgresql.org/docs/12/libpq.html): **sudo apt-get install -y libpq-dev**

## Commands to run the example

```bash
# -lpg tells the compiler to link the postgresql library

g++ main.cpp  -lpq
./a.out
```
