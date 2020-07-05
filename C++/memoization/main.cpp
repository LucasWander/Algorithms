#include <iostream>
#include <unordered_map>
#include <limits>

std::unordered_map<unsigned long long int, char> powerOfTwo()
{
    std::unordered_map<unsigned long long int, char> teste;

    unsigned long long int i = 1;
    unsigned long long int max = std::numeric_limits<unsigned long long int>::max();

    while (i < max)
    {
        teste[i] = 't';
        i = i * 2;
        if (i == 0)
            break;
    }

    return teste;
}

void showMap(std::unordered_map<unsigned long long int, char> power) {
    for(auto& aux: power){
        std::cout << aux.first << std::endl;
    }
}

void writeFile(std::unordered_map<unsigned long long int, char> power) {

}

int main()
{
    unsigned long long int i = 1;

    std::unordered_map<unsigned long long int, char> power = powerOfTwo();

    showMap(power);
}
