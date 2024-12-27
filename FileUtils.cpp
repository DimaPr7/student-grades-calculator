#include "FileUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
