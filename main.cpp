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

    readDataFromFile("students", students);

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
