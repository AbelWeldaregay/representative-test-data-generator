<<<<<<< HEAD
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
=======
#include <iostream> //ability to use input output
#include <fstream> //read and write from a file
#include <cstdlib> ///to use the rand() function, this must be included
#include <cmath> //basic math functionalities
#include <ctime> //needed for srand(time())
#include <string> //gives me the ability to user strings
#include <iomanip>  //formatting
#include "student.h"  //linking the functions in student.cpp together
#include "randgen.h"  //linking the functions in randgen.cpp together
using namespace std; //simplifies the code by not having to do std::string

int main()
{
    srand(time(0));  //seeds a time, so everytime i compile the numbers and strings will be different
    student myStudent[5000]; //creates an array of structs of type student, and it has 5000 components
    readFirstStudent(myStudent);  //calls the function to read the first student's data


    randStr(myStudent);  //calls the function that generates random strings for the names
    randInt(myStudent); //calls the function that generates random numbers for the ID
    randAnswer(myStudent); //calls the function that generates random strings for the answers
    createAnswersFile(myStudent);  //calls the function that creates studentAnswers.txt

    return 0;  //returns zero to main, which lets the compiler know everything went well
>>>>>>> d9d3e69928f0f7631c4aab203835f4bcab738047
}
