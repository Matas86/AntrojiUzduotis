#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct student
{
    std::string name;
    std::string surname;
    int homeworkSum;
    std::vector<int> homework;
    int exam;
    double finalGrade;
    bool random;
    student()
    {
        homeworkSum = 0;
    }
};

#endif // STUDENT_H