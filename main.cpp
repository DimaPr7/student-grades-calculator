#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "Person.h"


void readDataFromFile(const string& filename, vector<Person>& students) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, surname;
        vector<double> HW;
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
