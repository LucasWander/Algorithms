typedef struct student {
    char name[50];
    char curso[30];
    int age;
    float *grades;
}student;

student* readNewStudent();

student printStudent(student *stu);

float* readGrades();

student* createNStudents(int n);

float average(student *stu);
