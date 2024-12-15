#include "FileUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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