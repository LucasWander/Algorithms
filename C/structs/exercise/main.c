// 1. Faça um programa para leitura, via teclado, dos dados de um
// aluno. Os dados a serem guardados na estrutura aluno são os
// seguintes: nome, curso, idade. Ao final, imprima estas informações
// na tela.



#include <stdio.h>
#include "struct.h"

int main() {

    student *s1;
    s1 = readNewStudent();
    printStudent(s1);

    int n = 10,i;

    student *s2 = createNStudents(10);

    for(i=0;i<10;i++) {
        s2[i].age = 25;
        printStudent(s2);
    }

    return 0;
}
