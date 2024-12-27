#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <vector>
#include <list>
#include <deque>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Person.h"

template <typename Container>
void readDataFromFile(const std::string& filename, Container& students) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, surname;
        double examGrade;
        std::vector<double> grades;

        iss >> name >> surname;
        for (int i = 0; i < 5; ++i) {
            double taskGrade;
            iss >> taskGrade;
            grades.push_back(taskGrade);
        }
        iss >> examGrade;

        students.emplace_back(name, surname, grades, examGrade);
    }
    file.close();
}

template <typename Container>
void strategy1(const Container& students, Container& passed, Container& failed) {
    std::partition_copy(
            students.begin(),
            students.end(),
            std::back_inserter(passed),
            std::back_inserter(failed),
            [](const Person& student) { return student.getGrade() >= 5.0; }
    );
}

#endif
