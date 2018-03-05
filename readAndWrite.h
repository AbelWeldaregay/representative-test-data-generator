#ifndef READANDWRITE_H_INCLUDED
#define READANDWRITE_H_INCLUDED

using namespace std;

struct student {
    string className;
    int studentID;
    string firstName;
    string lastName;
    string studentAnswers;
    student();
};
struct results
{
    char givenLetter[5000];
    int correctCount[5000];
    int incorrectCount[5000];
    int blankCount[5000];
    float totalPoints[5000];
};

struct grader{

string answerKey;
string indicator;
float score[5000];
};

struct letterGrade{

int a;
int b;
int c;
int d;
int f;
letterGrade();
};

void readStudentsAnswers(student studentType[]);
void readAnswerKey (grader &graderType);
void writeResultsFile(student studentType[], results resultType, letterGrade letterGradeType);

#endif // READANDWRITE_H_INCLUDED
