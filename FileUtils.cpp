#include "FileUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

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

void generateRandomData(const std::string& filename, size_t numStudents) {
    std::ofstream file(filename);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 10.0);

    for (size_t i = 0; i < numStudents; ++i) {
        file << "Name" << i + 1 << " Surname" << i + 1;
        for (int j = 0; j < 5; ++j) {
            file << " " << dis(gen);
        }
        file << " " << dis(gen) << std::endl;
    }

    file.close();
}

void generateFiles() {
    std::vector<size_t> sizes = {10000, 100000, 1000000};
    for (size_t size : sizes) {
        std::string filename = "students_" + std::to_string(size) + ".txt";
        std::cout << "Generating file: " << filename << " with " << size << " records." << std::endl;
        generateRandomData(filename, size);
    }
}
