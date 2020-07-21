#include "User.hpp"

User::User(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

User::User(std::string name, int age, int id)
{
    this->name = name;
    this->age = age;
    this->id = id;
}

void User::setName(std::string name)
{
    this->name = name;
}

std::string User::getName()
{
    return this->name;
}

void User::setAge(int age)
{
    this->age = age;
}

int User::getAge()
{
    return this->age;
}

void User::setId(int id)
{
    this->id = id;
}

int User::getId()
{
    return this->id;
}
