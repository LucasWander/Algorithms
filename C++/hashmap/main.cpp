#include <iostream>
#include <unordered_map>

int main()
{

    std::unordered_map<std::string, unsigned long long int> teste;

    std::cout << "Max Size: " << teste.max_size() << std::endl;
    std::cout << "Current size: " << teste.size() << std::endl;

    teste.insert({"Lucas", 10});
    teste.insert({"Wander", 40});
    teste.insert({"De", 5});
    teste.insert({"Freitas", 11});

    for (auto &x : teste)
    {
        std::cout << x.first << ": " << x.second << std::endl;
    }

    //std::unordered_map<std::string, unsigned long long int>::const_iterator de = teste.find("lol");

    //std::cout << "Key:" << de->first << " Value: " << de->second << std::endl;

    teste["teste"] = 45;
    teste["tesdasdasd"] = 56;

    for (auto &x : teste)
    {
        std::cout << x.first << ": " << x.second << std::endl;
    }

    std::cout << "Current size: " << teste.size() << std::endl;
}
