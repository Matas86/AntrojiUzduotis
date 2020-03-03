#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>
#include <fstream>
#include <sstream>

#include "student.h"

void Skaityk(std::vector<student> &stud);

void Isvesk(std::vector<student> stud);

void FinalCounter(std::vector<student> &stud);

bool sortStudents(student A, student B);

void StartProgram();

#endif // FUNCTIONS_H