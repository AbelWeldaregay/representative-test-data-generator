#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include "readAndWrite.h"

using namespace std;

/*
This function adds 70 to the total score of all of the students score
*/
void initializeScores(student studentType[],grader &gradeType, results &resultType)
{
    for (int i=0; i<5000; i++)
    {
        gradeType.score[i]+=70;
    }
    for (int i=0; i<5000; i++)
    {
        resultType.totalPoints[i]+=70;
    }
}

/*
This function calculates the letter grade of each student depending on whether the
answer key has the easy, medium or hard indicator.
*/
void calcLetterGrade (grader graderType, letterGrade &letterGradeType, results &resultType)
{

    if (graderType.indicator=="easy" || graderType.indicator=="Easy")
    {
        for (int i=0; i<5000; i++)
        {
            if (resultType.totalPoints[i]>=85)
            {
                letterGradeType.a++;
                resultType.givenLetter[i]='A';
            }
            else if (resultType.totalPoints[i]>=75)
            {
                letterGradeType.b++;
                resultType.givenLetter[i]='B';
            }
            else if (resultType.totalPoints[i]>=65)
            {
                letterGradeType.c++;
                resultType.givenLetter[i]='C';
            }
            else if (resultType.totalPoints[i]>=55)
            {
                letterGradeType.d++;
                resultType.givenLetter[i]='D';
            }
            else if (resultType.totalPoints[i]<55)
            {
                letterGradeType.f++;
                resultType.givenLetter[i]='F';
            }

        }
    }
    else if (graderType.indicator=="medium" || graderType.indicator=="Medium")
    {
        for (int i=0; i<5000; i++)
        {
            if (resultType.totalPoints[i]>=90)
            {
                letterGradeType.a++;
                resultType.givenLetter[i]='A';
            }
            else if (resultType.totalPoints[i]>=80)
            {
                letterGradeType.b++;
                resultType.givenLetter[i]='B';
            }
            else if (resultType.totalPoints[i]>=70)
            {
                letterGradeType.c++;
                resultType.givenLetter[i]='C';
            }
            else if (resultType.totalPoints[i]>=60)
            {
                letterGradeType.d++;
                resultType.givenLetter[i]='D';
            }
            else if (resultType.totalPoints[i]<=59)
            {
                letterGradeType.f++;
                resultType.givenLetter[i]='F';
            }

        }
    }
    else if(graderType.indicator=="hard" || graderType.indicator=="Hard")
    {
        for (int i=0; i<5000; i++)
        {
         if (resultType.totalPoints[i]>=95)
         {
                letterGradeType.a++;
                resultType.givenLetter[i]='A';
         }
         else if (resultType.totalPoints[i]>=85)
         {
                letterGradeType.b++;
                resultType.givenLetter[i]='B';
         }
         else if (resultType.totalPoints[i]>=75)
         {
                letterGradeType.c++;
                resultType.givenLetter[i]='C';
         }
         else if (resultType.totalPoints[i]>=65)
         {
                letterGradeType.d++;
                resultType.givenLetter[i]='D';
         }

         else
         {
            letterGradeType.f++;
            resultType.givenLetter[i]='F';
         }

        }
    }
}

/*
This function grades the answers by comparing each character from studentsAnswer
answer section with the answer key, character by character.
*/
void gradeAnswers(student studentType[], grader &graderType, results &resultType){

      for (int i=0; i<5000; i++)
        {
            for (int j=0; j<100; j++)
            {
                if(studentType[i].studentAnswers[j]==graderType.answerKey[j])
                {
                    graderType.score[i]=graderType.score[i]+2;
                    resultType.correctCount[i]++;
                }
                else if (studentType[i].studentAnswers[j]==' ')
                {
                    resultType.blankCount[i]++;

                    if (resultType.blankCount[i]>=5)
                        graderType.score[i]=graderType.score[i]-2;
                }
                else if (studentType[i].studentAnswers[j]!=graderType.answerKey[j])
                {
                    resultType.incorrectCount[i]++;
                    graderType.score[i]=graderType.score[i]-1;
                }

            }
        }
}

/*
This function initializes all the components of results to 0 or a blank.
*/
void initializeResultsType(results &resultType)
{
    for (int i=0; i<5000; i++)
    {
        resultType.blankCount[i]=0;
        resultType.correctCount[i]=0;
        resultType.givenLetter[i]=' ';
        resultType.incorrectCount[i]=0;
        resultType.totalPoints[i]=0.0;
    }
}

/*
This function calculates the totalPoints for each students,
based on the formula given  in the direction
*/
void calcTotalPoints(results &resultType, grader graderType)
{
    float maxPoints =200;  //max points is a 100 because if you get all the questions right

    for (int i=0; i<5000; i++)
    {
        resultType.totalPoints[i]=(graderType.score[i]/maxPoints)*100;
    }

}
/*
This function initializes each component of givenLetter, which
is a member of results struct to a blank.
*/
void initializeLetterGrade(results resultType)
{
    for (int i=0; i<5000; i++)
    {
        resultType.givenLetter[i]=' ';
    }
}


