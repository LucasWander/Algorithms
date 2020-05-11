#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

student* readNewStudent() {

    student *n = (student*) malloc(sizeof(student));

    printf("Digite o nome do estudante: ");
    fgets(n->name,sizeof(n->name), stdin);
    printf("Digite o nome do curso: ");
    fgets(n->curso,sizeof(n->curso),stdin);
    printf("Digite a idade do estudante: ");
    scanf("%d",&n->age);

    return n;
}

student printStudent(student *stu) {
    printf("%s", stu->name);
    printf("%s", stu->curso);
    printf("%d\n", stu->age);
}


float* readGrades() {
    float *n = (float*) malloc(sizeof(float)*3);

    scanf("%f %f %f", &n[0], &n[1], &n[2]);

    return n;
}

float average(student *stu) {

    return (stu->grades[0]+stu->grades[2]+stu->grades[1]) / 3.0;
}


student* createNStudents(int n){

    return (student*) malloc(sizeof(student)*n);
}
