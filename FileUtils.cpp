#include "FileUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

template <typename Container>
void readDataFromFile(const std::string& filename, std::vector<Person>& students) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string name, surname;
    double grade, hwScore;
    while (file >> name >> surname) {
        std::vector<double> HW;
        for (int i = 0; i < 5; ++i) {
            file >> hwScore;
            HW.push_back(hwScore);
        }
        file >> grade;
        students.emplace_back(name, surname, HW, grade);
    }
}

void generateRandomData(const std::string& filename, size_t numStudents) {
    std::ofstream file(filename);

    if (!file) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

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
    std::cout << "Random data generated in file: " << filename << std::endl;
}
