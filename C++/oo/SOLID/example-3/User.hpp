#include <string>
#pragma once

class User {
    private:
        std::string name;
        int id;
        int age;

    public:
        User(std::string name, int age);

        User(std::string name, int age, int id);

        void setName(std::string name);

        std::string getName();

        void setAge(int age);

        int getAge();

        void setId(int id);

        int getId();
};
