#include <iostream>
#include <chrono>
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
    Person(string A, string B, vector<double> C, double D, double E);
    ~Person();
    void SetName(string N);
    string GetName();
    void printPerson();

    void calculateGrade();
};

Person::Person() {
    name = "test";
    surname = "test";
    HW = {};
    exam = 0;
    grade = 0;
}

Person::Person(string A, string B, vector<double> C, double D, double E) {
    name = A;
    surname = B;
    HW = C;
    exam = D;
    grade = E;
}

Person::~Person() {
    name.clear();
    surname.clear();
    HW.clear();
    exam = 0;
    grade = 0;
}

void Person::SetName(string N) { name = N; }
void Person::calculateGrade(){
    double sum = exam;
    for (double hw : HW){
        sum += hw;
    }
    grade = sum / (HW.size() + 1);
}
string Person::GetName() { return name; }
void Person::printPerson() {
    cout << name << " " << surname << " " << grade << endl;
}

int main(){
    Person A;
    A.printPerson();
    vector<Person> arr;
    for (int i = 0; i < 1; i++) {
        cout << "Please input student name and surname: ";
        string TN, TS;
        cin >> TN >> TS;
        cout << "Please input student HW points:" << endl;
        vector<double> THW;

        for (int j = 0; j < 3; j++) {
            cout << "Please input points of HW" << j + 1 << ": ";
            double n;
            cin >> n;
            THW.push_back(n);
        }

        cout << "Please input student Final Exam points: ";
        double TE;
        cin >> TE;

        Person student(TN, TS, THW, TE, 0);
        student.calculateGrade();
        arr.push_back(student);
    }

    cout << "Name       Surname       Final_Point(Aver.)" << endl;
    cout << "-------------------------------------------" << endl;
    for (auto &var : arr) {
        var.printPerson();
    }
}

