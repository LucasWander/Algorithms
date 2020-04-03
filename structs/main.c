#include <stdio.h>

typedef struct address {
    int number;
    char street[30];
    char neighborhood[30];
    char city[30];
    char state[30];
    char coutry[30];
}address;

struct person {
    char name[30];
    int age;
    char cpf[11];
    address address;
};

int main() {

    struct person p1;

    p1.name[0] = 'a';
    p1.age = 20;
    p1.address.number = 263;

    // printf("%ld\n", sizeof(p1.name));
    // printf("%ld\n", sizeof(p1.cpf));

    fgets(p1.name, sizeof(p1.name), stdin);
    fgets(p1.cpf, sizeof(p1.cpf), stdin);
    scanf("%d", &p1.age);

    printf("%d\n",p1.age);
    printf("%d\n", p1.address.number);
    puts(p1.name);
    puts(p1.cpf);

    return 0;
}
