#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include "Person.h"
#include "FileUtils.h"

using namespace std;

auto start = std::chrono::high_resolution_clock::now();
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

template <typename Container>
void strategy1(const Container& students, Container& passed, Container& failed) {
    std::partition_copy(
            students.begin(),
            students.end(),
            std::back_inserter(passed),
            std::back_inserter(failed),
            [](const Person& student) { return student.getGrade() >= 5.0; });
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