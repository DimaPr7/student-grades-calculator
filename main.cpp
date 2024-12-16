#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
using namespace std;
#include "Person.h"
#include "FileUtils.h"


void generateRandomData(const string& filename, size_t numStudents) {
    ofstream file(filename);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 10.0);

    for (size_t i = 0; i < numStudents; ++i) {
        file << "Name" << i + 1 << " Surname" << i + 1;
        for (int j = 0; j < 5; ++j) {
            file << " " << dis(gen);
        }
        file << " " << dis(gen) << endl;
    }

    file.close();}


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

    cout << "Data processing completed!" << endl;

    return 0;
}
