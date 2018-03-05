#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include "readAndWrite.h"
#include "calculations.h"
using namespace std;

int main()
{
    student studentType[5000]; //creates an array of structs of 5000 components
    grader graderType;  //creates an object of type grader
    letterGrade letterGradeType;  //creates an object of type letterGrade
    results resultType;  //creates an object of type results
    initializeLetterGrade(resultType);  //calls the function that initializes the letter grade char's
    readStudentsAnswers(studentType);  //calls the function that will read the studentsAnswers.txt file

    readAnswerKey(graderType);  //calls the function that will read the answer key and stores it into grader struct


    initializeResultsType(resultType);  //calls the function that will initialize components of results
    gradeAnswers(studentType, graderType, resultType);  //calls the function that will grade the answers by comparing it to the answerKey

    calcTotalPoints(resultType, graderType); //calls the function that will calculate the total points
    initializeScores(studentType, graderType, resultType); //calls the function that will add 70 to each calculated score
    calcLetterGrade(graderType, letterGradeType, resultType); //calls the function that will assign a letter grade to each student
    writeResultsFile(studentType,resultType,letterGradeType); //calls the function that will write the results.txt file

    return 0; //will return 0 to main
}
