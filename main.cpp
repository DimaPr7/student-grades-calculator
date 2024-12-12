#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "Person.h"
#include "FileUtils.h"

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

    cout << left << setw(12) << "Name" << setw(12) << "Surname"
         << "Final Grade" << endl;
    cout << "-------------------------------------------" << endl;

    for (const auto& student : students) {
        student.printPerson();
    }

    return 0;
}
