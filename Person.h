#ifndef GRADES_CALCULATOR_PERSON_H
#define GRADES_CALCULATOR_PERSON_H

#include <string>
#include <vector>
using namespace std;

class Person {
private:
    string name, surname;
    vector<double> HW;
    double exam;
    double grade;

public:
    Person();
    Person(string A, string B, vector<double> C, double D);
    ~Person();

    void SetName(string N);
    string GetName() const;
    void printPerson() const;
    void calculateGrade(char method);
    const double getGrade() const;
};

#endif // GRADES_CALCULATOR_PERSON_H
