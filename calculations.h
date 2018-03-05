#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED
using namespace std;

void initializeScores(student studentType[],grader &gradeType, results &resultType);
void calcLetterGrade (grader graderType, letterGrade &letterGradeType, results &resultType);
void gradeAnswers(student studentType[], grader &graderType, results &resultType);
void initializeResultsType(results &resultType);
void calcTotalPoints(results &resultType, grader graderType);
void initializeLetterGrade(results resultType);
#endif // CALCULATIONS_H_INCLUDED
