#include <iostream>
#include <vector>
#include <chrono>
#include "Person.h"
#include "FileUtils.h"
#include <fstream>

using namespace std;

int main() {
    cout << "Generating data files..." << endl;
    generateFiles();

    vector<Person> students;
    string filename;

    cout << "Enter the filename to process: ";
    cin >> filename;

    auto start = chrono::high_resolution_clock::now();
    try {
        readDataFromFile(filename, students);
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
    for (const auto& student : students) {
        if (student.getGrade() >= 5.0) {
            passedFile << student.GetName() << " " << student.getGrade() << endl;
        } else {
            failedFile << student.GetName() << " " << student.getGrade() << endl;
        }
    }
    passedFile.close();
    failedFile.close();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    cout << "Data processing completed!" << endl;
    return 0;
}
