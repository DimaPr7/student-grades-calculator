#include "FileUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>

void readDataFromFile(const std::string& filename, std::vector<Person>& students) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Error: Could not open the file!");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, surname;
        std::vector<double> HW;
        double exam;

        ss >> name >> surname;
        double temp;
        for (int i = 0; i < 5; ++i) {
            ss >> temp;
            HW.push_back(temp);
        }
        ss >> exam;

        Person student(name, surname, HW, exam);
        students.push_back(student);
    }
    file.close();
}
