#include "DBConnectionInterface.hpp"

class PostgreDB: public DBConnectionInterface {

    public:
        PostgreDB();
        void connect();
        void desconnect();
};
