#include "Person.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;


Person::Person() {
    name = "test";
    surname = "test";
    HW = {};
    exam = 0;
    grade = 0;
}

Person::Person(string A, string B, vector<double> C, double D) {
    name = A;
    surname = B;
    HW = C;
    exam = D;
    grade = 0;
}

Person::~Person() {
    name.clear();
    surname.clear();
    HW.clear();
    exam = 0;
    grade = 0;
}

void Person::SetName(string N) {
    name = N;
}

string Person::GetName() const {
    return name;
}

void Person::printPerson() const {
    cout << name << " " << surname << " " << grade << endl;
}

void Person::calculateGrade(char method) {
    if (method == 'A') {
        double sum = accumulate(HW.begin(), HW.end(), exam);
        grade = sum / (HW.size() + 1);
    } else if (method == 'M') {
        HW.push_back(exam);
        sort(HW.begin(), HW.end());
        size_t size = HW.size();
        if (size % 2 == 0) {
            grade = (HW[size / 2 - 1] + HW[size / 2]) / 2.0;
        } else {
            grade = HW[size / 2];
        }
    }
}
