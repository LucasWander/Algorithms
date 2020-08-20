#include <iostream>

class User
{
private:
    std::string name;
    std::string birthdate;
    std::uint8_t height;

public:
    User()
    {
        this->name = "";
    }

    User(std::string name)
    {
        this->name = name;
    }

    std::string getName() {
        return this->name;
    }

    void setName(std::string name) {
        this->name = name;
    }
};


class Figure{

    public:
        std::uint8_t a,b;
        int c;

        Figure(){
            std::cout << "Criando" << std::endl;
        }
};

int main()
{
    User a;

    a.setName("Lucas");

    std::cout << "Name: " << a.getName() << std::endl;

    std::cout << "Size: " << sizeof(a) << std::endl;

    std::cout << "Size uint8_t: " << sizeof(std::uint8_t) << std::endl;
    std::uint8_t teste = 45;
    std::cout << "Size uint8_t variable: " << sizeof(teste) << std::endl;
    User *pointer = new User("Lucas Wander de Freitas");

    Figure f1;

    std::cout << "Size figure: " << sizeof(Figure) << std::endl;
    std::cout << "Size Figure a:" << sizeof(f1.a) << std::endl;
    std::cout << "Size Figure b:" << sizeof(f1.b) << std::endl;
    std::cout << "Size Figure c:" << sizeof(f1.c) << std::endl;
    std::cout << "Size figure object: " << sizeof(f1) << std::endl;
}
