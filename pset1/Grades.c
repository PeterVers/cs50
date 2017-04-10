#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int score, i, gradeCounter[5];
char grade;
for(i = 0; i <= 4; i++)
    gradeCounter[i] = 0;  
    printf("Please enter your score.\n");
for(i = 1; i <=10; ++i) {
    scanf("%i", &score);
    if (score >= 93){
        grade = 'A';
        ++gradeCounter[0];
        }
    if (score < 93 && score >= 85) {
        grade = 'B';
        ++gradeCounter[1];
        }
    if (score < 85 && score >= 75) {
        grade = 'C';
        ++gradeCounter[2];
        }
    if (score < 75 && score >= 70) {
        grade = 'D';
        ++gradeCounter[3]; 
        }
    if (score < 70) {
        grade = 'F';
        ++gradeCounter[4];
        }
}
grade = 'A';
for(i = 0; i <=4; ++i) {
printf("%4c%14i\n", grade, gradeCounter[i]);
++grade;
if(grade == 'E')
    grade = 'F';
}

return 0;
}
