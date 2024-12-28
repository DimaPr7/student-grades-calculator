#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person {
private:
    std::string name, surname;
    std::vector<double> HW;
    double grade;

public:
    Person();
    Person(std::string name, std::string surname, std::vector<double> HW, double exam);
    ~Person();

    void SetName(std::string name);
    std::string GetName() const;
    void printPerson() const;
    void calculateGrade(char method);
    double getGrade() const;
};

#endif // PERSON_H
