#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
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
    Person(string A, string B, vector<double> C, double D);
    ~Person();
    void SetName(string N);
    string GetName() const;
    void printPerson() const;
    void calculateGrade(char method);
};

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

void Person::SetName(string N) { name = N; }

void Person::calculateGrade(char method) {
    if (method == 'A') {
        double sum = exam;
        for (double hw : HW) {
            sum += hw;
        }
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

string Person::GetName() const { return name; }

void Person::printPerson() const {
    cout << left << setw(12) << name << setw(12) << surname
         << fixed << setprecision(2) << grade << endl;
}

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
