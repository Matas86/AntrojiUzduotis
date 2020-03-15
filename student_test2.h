#ifndef STUDENT_TEST2_H
#define STUDENT_TEST2_H

#include <string>
#include <vector>
#include <list>
#include <deque>

struct student
{
    std::string name;
    std::string surname;
    int homeworkSum;
    std::vector<int> homework;
    int exam;
    double finalGrade;
    bool random;
    bool cool;
    student()
    {
        homeworkSum = 0;
    }
};

#endif // STUDENT_H