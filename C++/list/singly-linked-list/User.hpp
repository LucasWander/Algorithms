#include <string>

#pragma once

class User {
    public:
        std::string name;
        std::string email;
        std::string birthDate;
        float height;
        float weigth;
        long int id;
        User();
        User(long int id);
};
