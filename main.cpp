#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
private:
    string name, surname;
    vector<double> HW;
    double exam;
    double grade;
public:
    Person();
    Person(string A, string B, vector<double> C, double D, double E);
    ~Person();
    void SetName(string N);
    string GetName();
    void printPerson();
    void calculateGrade(char choice);
};

Person::Person() : name("test"), surname("test"), exam(0), grade(0) {}

Person::Person(string A, string B, vector<double> C, double D, double E)
        : name(A), surname(B), HW(C), exam(D), grade(E) {}

Person::~Person() {}

void Person::SetName(string N) {
    name = N;
}

string Person::GetName() {
    return name;
}

void Person::printPerson() {
    cout << name << " " << surname << " " << grade << endl;
}

void Person::calculateGrade(char choice) {
    double final_grade;
    HW.push_back(exam);

    if (choice == 'A') {
        double sum = 0;
        for (double hw : HW) {
            sum += hw;
        }
        final_grade = sum / HW.size();
    } else if (choice == 'M') {
        sort(HW.begin(), HW.end());
        size_t size = HW.size();
        if (size % 2 == 0) {
            final_grade = (HW[size / 2 - 1] + HW[size / 2]) / 2.0;
        } else {
            final_grade = HW[size / 2];
        }
    }
    grade = final_grade;
}

int main() {
    vector<Person> arr;
    for (int i = 0; i < 1; i++) {
        cout << "Please input student name and surname: ";
        string TN, TS;
        cin >> TN >> TS;

        cout << "Please input student HW points:" << endl;
        vector<double> THW;
        double n;
        while (true) {
            cout << "Enter points for homework: ";
            cin >> n;
            if (n < 0) break;
            THW.push_back(n);
        }

        cout << "Please input student Final Exam points: ";
        double TE;
        cin >> TE;

        char choice;
        cout << "Choose grade calculation method (A for Average, M for Median): ";
        cin >> choice;

        Person student(TN, TS, THW, TE, 0);
        student.calculateGrade(choice);
        arr.push_back(student);
    }

    cout << "Name       Surname       Final_Point" << endl;
    cout << "------------------------------------" << endl;
    for (auto &var : arr) {
        var.printPerson();
    }

    return 0;
}
