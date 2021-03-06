#ifndef FUNCTIONS_TEST_H
#define FUNCTIONS_TEST_H

#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>

#include "student_test.h"

void Skaityk(std::vector<student> &stud);

void Skaityk(std::vector<student> &stud, std::string filename);

void Isvesk(std::vector<student> stud);

void FinalCounter(std::vector<student> &stud);

bool sortStudents(student A, student B);

void StartProgram();

void Generate(int n);

bool sortStudentsByGrade(student A, student B);


#endif // FUNCTIONS_TEST_H