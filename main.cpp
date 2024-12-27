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

int main() {
    const std::string dataFile = "students.txt";
    size_t studentCount = 1000;
    generateRandomData(dataFile, studentCount);

    vector<Person> studentsVector;
    list<Person> studentsList;
    deque<Person> studentsDeque;

    try {
        readDataFromFile(dataFile, studentsVector);
    } catch (const runtime_error& e) {
        cerr << "Error reading data: " << e.what() << endl;
        return 1;
    }

    vector<Person> passedVector, failedVector;
    list<Person> passedList, failedList;
    deque<Person> passedDeque, failedDeque;

    auto start = std::chrono::high_resolution_clock::now();
    strategy1(studentsVector, passedVector, failedVector);
    auto end = std::chrono::high_resolution_clock::now();
    cout << "Vector Strategy 1 Time: "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    start = std::chrono::high_resolution_clock::now();
    strategy1(studentsList, passedList, failedList);
    end = std::chrono::high_resolution_clock::now();
    cout << "List Strategy 1 Time: "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    start = std::chrono::high_resolution_clock::now();
    strategy1(studentsDeque, passedDeque, failedDeque);
    end = std::chrono::high_resolution_clock::now();
    cout << "Deque Strategy 1 Time: "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    cout << "Data loaded successfully!" << endl;

    return 0;
}