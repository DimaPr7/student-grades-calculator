#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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
    string GetSurname();
    double GetGrade();
    void printPerson();
    void calculateGrade();
};

Person::Person() : name("test"), surname("test"), exam(0), grade(0) {}

Person::Person(string A, string B, vector<double> C, double D, double E)
        : name(A), surname(B), HW(C), exam(D), grade(E) {}

Person::~Person() {
    name.clear();
    surname.clear();
    HW.clear();
}

void Person::SetName(string N) { name = N; }
string Person::GetName() { return name; }
string Person::GetSurname() { return surname; }
double Person::GetGrade() { return grade; }

void Person::calculateGrade() {
    double sum = exam;
    for (double hw : HW) {
        sum += hw;
    }
    grade = sum / (HW.size() + 1);
}

void Person::printPerson() {
    cout << left << setw(10) << name
         << setw(10) << surname
         << setw(15) << fixed << setprecision(2) << grade << endl;
}

void generateRandomScores(vector<double>& HW, double& exam) {
    HW.clear();
    for (int i = 0; i < 5; ++i) {
        HW.push_back(rand() % 11);
    }
    exam = rand() % 11;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Person> arr;

    int choice;
    cout << "Choose input method:\n1. Manual input\n2. Randomly generate scores\nChoice: ";
    cin >> choice;

    if (choice == 2) {
        vector<double> THW;
        double TE;
        generateRandomScores(THW, TE);
        arr.emplace_back("Random", "Student", THW, TE, 0);
        arr.back().calculateGrade();
    } else {
        cout << "Please input student name and surname: ";
        string TN, TS;
        cin >> TN >> TS;

        cout << "Please input student HW points:\n";
        vector<double> THW;
        for (int i = 0; i < 5; ++i) {
            double n;
            cout << "HW" << i + 1 << ": ";
            cin >> n;
            THW.push_back(n);
        }

        cout << "Please input student Final Exam points: ";
        double TE;
        cin >> TE;

        arr.emplace_back(TN, TS, THW, TE, 0);
        arr.back().calculateGrade();
    }

    cout << left << setw(10) << "Name"
         << setw(10) << "Surname"
         << setw(15) << "Final_Point(Aver.)" << endl;
    cout << "-------------------------------------------" << endl;

    for (const auto& var : arr) {
        var.printPerson();
    }
    return 0;
}
