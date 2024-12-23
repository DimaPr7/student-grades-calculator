#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <sstream>
#include <random>
using namespace std;
#include "Person.h"
#include "FileUtils.h"

auto start = std::chrono::high_resolution_clock::now();
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


int main() {
    vector<Person> students;

    try {
        readDataFromFile("students", students);
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }


    char method;
    cout << "Choose grade calculation method (A for Average, M for Median): ";
    cin >> method;

    for (auto& student : students) {
        student.calculateGrade(method);
    }

    ofstream passedFile("passed_students"), failedFile("failed_students");
    for (const auto& student : students){
        if (student.getGrade() >= 5.0) {
            passedFile << student.GetName() << " " << student.getGrade() << endl;
        } else {
            failedFile << student.GetName() << " " << student.getGrade() << endl;
        }
    }
    passedFile.close();
    failedFile.close();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    cout << "Data processing completed!" << endl;

    return 0;
}