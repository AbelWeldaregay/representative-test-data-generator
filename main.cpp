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
}
