#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include "readAndWrite.h"

using namespace std; //simplifies the code by not having to use std::string

/*
Definition of default constructor for the struct student
*/
student::student(){
studentID=0;
firstName="";
lastName="";
className="cs-250";
}

letterGrade::letterGrade(){
a=0;
b=0;
c=0;
d=0;
f=0;
}
/*
This function reads the text file studentsAnswers.txt
and stores it into the struct student
*/
void readStudentsAnswers(student studentType[])
{
    char delimeter(',');  //the file will read until it reaches the comma which is the delimeter
    char comma =',';
    ifstream inFile;
    inFile.open("studentsAnswer.txt");  //opens the file studentsAnswer.txt
    for (int i=0; i<5000; i++)
    {
        getline(inFile, studentType[i].className, delimeter);  //will read until it reaches a comma
        inFile>>studentType[i].studentID;

        inFile>>comma;
        getline(inFile, studentType[i].lastName, delimeter);

        getline(inFile, studentType[i].firstName, delimeter);
        getline(inFile, studentType[i].studentAnswers);

    }
}

/*
This function reads the answer key and stores it into the
struct grader.
*/
void readAnswerKey (grader &graderType)
{
    ifstream inFile;

    inFile.open("answerKey.txt");
    inFile>>graderType.answerKey;
    inFile>>graderType.indicator;

    inFile.close();
}

/*
This function will write the results.txt file.
It will write all the data calculated and collected in the structs
student, results and letterGrade and write it into results.txt
*/
void writeResultsFile(student studentType[], results resultType, letterGrade letterGradeType)
{

    ofstream outFile;

    outFile.open("results.txt");

    outFile<<"CLASS-NAME,  STUDENTS ID, LAST NAME, FIRST NAME,   ANSWERS, LETTER GRADE,   NUMBER OF CORRECT ANSWERS,   NUMBER OF FALSE ANSWERS, NUMBER OF BLANKS, TOTAL POINTS "<<endl;
    outFile<<setprecision(2)<<showpoint<<fixed;  //prints to 2 decimal places

    for (int i=0; i<5000; i++)
    {
        outFile<<left<<setw(7)<<studentType[i].className<<", ";
        outFile<<left<<setw(6)<<studentType[i].studentID<<", ";
        outFile<<left<<setw(13)<<studentType[i].lastName<<", ";
        outFile<<left<<setw(13)<<studentType[i].firstName<<", ";
        outFile<<studentType[i].studentAnswers<<", ";
        outFile<<left<<setw(2)<<resultType.givenLetter[i]<<", ";
        outFile<<left<<setw(2)<<resultType.correctCount[i]<<", ";
        outFile<<left<<setw(2)<<resultType.incorrectCount[i]<<", ";
        outFile<<left<<setw(2)<<resultType.blankCount[i]<<", ";
        outFile<<left<<setw(2)<<resultType.totalPoints[i]<<endl;
    }

    outFile<<"\nNumber of students attended the exam: "<<letterGradeType.a+letterGradeType.b+letterGradeType.c+letterGradeType.d+letterGradeType.f<<endl;
    outFile<<"Number of students received A: "<<letterGradeType.a<<endl;
    outFile<<"Number of students received B: "<<letterGradeType.b<<endl;
    outFile<<"Number of students received C: "<<letterGradeType.c<<endl;
    outFile<<"Number of students received D: "<<letterGradeType.d<<endl;
    outFile<<"Number of students received F: "<<letterGradeType.f<<endl;
}

