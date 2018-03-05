#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

using namespace std;

struct student {
    string className;
    int studentID;
    string firstName;
    string lastName;
    string studentAnswers;
    student();
};

void readFirstStudent(student studentType[]);
void createAnswersFile(student studentType[]);
#endif // STUDENT_H_INCLUDED
