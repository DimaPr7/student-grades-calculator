#include "Person.h"
#include <iostream>
#include <numeric>
#include <algorithm>

Person::Person() : name("test"), surname("test"), exam(0), grade(0) {}

Person::Person(std::string name, std::string surname, std::vector<double> HW, double exam)
        : name(name), surname(surname), HW(HW), exam(exam), grade(0) {}

Person::~Person() {}

void Person::SetName(std::string name) {
    this->name = name;
}

std::string Person::GetName() const {
    return name;
}

void Person::printPerson() const {
    std::cout << name << " " << surname << " " << grade << std::endl;
}

double Person::getGrade() const {
    return grade;
}

void Person::calculateGrade(char method) {
    if (method == 'A') {
        double sum = std::accumulate(HW.begin(), HW.end(), exam);
        grade = sum / (HW.size() + 1);
    } else if (method == 'M') {
        std::vector<double> allScores = HW;
        allScores.push_back(exam);
        std::sort(allScores.begin(), allScores.end());

        size_t size = allScores.size();
        if (size % 2 == 0) {
            grade = (allScores[size / 2 - 1] + allScores[size / 2]) / 2.0;
        } else {
            grade = allScores[size / 2];
        }
    }
}
