#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include "student.h"
using namespace std;
//definition of the default constructor
student::student(){
studentID=0;
firstName="";
lastName="";
className="cs-250";
}
/*
This function reads the first students answers and
stores it into the struct student.
*/
void readFirstStudent(student studentType[])
{
    ifstream inFile;
    inFile.open("firstStudentAnswersEntry.txt"); //opens the file firstStudentAnswersEntry.txt

    inFile>>studentType[0].studentAnswers;  //reads the first line of the file and stores it into the first component of student

    inFile.close(); //closes the file.
}

/*
This function creates the file studentsAnswer.txt and
writes the data stored in student struct and writes it to
the studentsAnswer.txt
*/
void createAnswersFile(student studentType[])
{
    ofstream outFile;
    outFile.open("studentsAnswer.txt");  //creates the file studentsAnswer.txt
    outFile<<left;
    for (int i=0; i<5000; i++)
    {
        outFile<<left<<setw(5)<<studentType[i].className<<",";
        outFile<<left<<setw(5)<<studentType[i].studentID<<",";
        outFile<<left<<setw(5)<<studentType[i].lastName<<",";
        outFile<<left<<setw(5)<<studentType[i].firstName<<",";
        outFile<<studentType[i].studentAnswers<<endl;
    }
}

