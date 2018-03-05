#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include "student.h"

using namespace std;

/*
Generates a random answer and stores it into
the struct student. it is a nested loop because studentType
is an array of structs of 5000 components, and studentAnswers, which is
a string, which means it is an array of characters, giving me the ability to
treat it as such.
*/
void randAnswer(student studentType[])
{


    for (int i=1; i<5000; i++)
    {
        for(int j=0; j<100; j++)
        {
            if (rand()%100==1)  //since 1/100 is equal to 1 percent, if the random number modulas 100 equals 1 then add a blank
                studentType[i].studentAnswers+=' ';
            else if(j==4 || j==9 || j==14 || j==24) //since an array starts at 0 the true and false questions would be one less than what there actual number is
                studentType[i].studentAnswers+=char(rand()%(66-65+1)+65);  //If you look at the ASCII code 65-66 represent A and B
            else
                studentType[i].studentAnswers+=char(rand()%(67-65+1)+65); //if it is not a true and false question, then it will choose a random char from A, B, C
        }
    }
}
/*

This function generates a random string and stores it into the
array of structs student.
I used a nested loop because student is an array of structs.
The second for loop will ran for a random amount of times between
5-9 times, which means the length of the string will be around that same
length
*/
void randStr(student studentType[])
{
    for (int i=0; i<5000; i++)
    {
        for (int j=0; j<(rand()%9+5); j++)  //it will loop trough a random number of times between 5-9.
        {
            studentType[i].firstName+=char(rand()%26+65); //ASCII code says 26 -65 represent the alphabet, so each time this loops, i add a random char from 26-65 to first Name.
        }
    }

    for (int i=0; i<5000; i++)
    {
        for (int j=0; j<(rand()%9+5); j++)        //it will loop trough a random number of times between 5-9.
        {
              studentType[i].lastName+=char(rand()%26+65);  //ASCII code says 26 -65 represent the alphabet, so each time this loops, i add a random char from 26-65 to first Name.
        }
    }
}
/*
This function generates a random integer and
stores it into the struct student. It also checks if the
number generated is a duplicate.
*/
void randInt(student studentType[])
{

    for (int i =0; i<5000; i++)
    {

        bool checkId = false;
        do
        {
            checkId=false;
            int id = (rand()%10000+10000);
            for (int j=0; j<i; j++)
                if (id == studentType[i].studentID)
                    checkId=true;
                if (checkId==false)
                    studentType[i].studentID=id;
        }while(checkId==true);


    }
}
