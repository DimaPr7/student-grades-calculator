#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include "Person.h"
#include "FileUtils.h"

using namespace std;

template <typename Container>
void strategy1(const Container& students, Container& passed, Container& failed) {
    std::copy_if(students.begin(), students.end(), std::back_inserter(passed),
                 [](const Person& student) { return student.getGrade() >= 5.0; });
    std::copy_if(students.begin(), students.end(), std::back_inserter(failed),
                 [](const Person& student) { return student.getGrade() < 5.0; });
}

template <typename Container>
void strategy2(Container& students, Container& failed) {
    auto it = std::remove_if(students.begin(), students.end(),
                             [&](const Person& student) {
                                 if (student.getGrade() < 5.0) {
                                     failed.push_back(student);
                                     return true;
                                 }
                                 return false;
                             });
    students.erase(it, students.end());
}

int main() {
    vector<Person> students;
    const size_t numStudents = 1000000;
    const string filename = "students.txt";

    try {
        generateRandomData(filename, numStudents);
    } catch (const exception& e) {
        cerr << "Error generating data: " << e.what() << endl;
        return 1;
    }

    vector<Person> studentsVector;
    list<Person> studentsList;
    deque<Person> studentsDeque;

    try {
        readDataFromFile(filename, studentsVector);
    } catch (const exception& e) {
        cerr << "Error reading data: " << e.what() << endl;
        return 1;
    }

    for (auto& student : studentsVector) {
        student.calculateGrade('A');
    }

    vector<Person> passedVector, failedVector;
    list<Person> passedList, failedList;
    deque<Person> passedDeque, failedDeque;


    cout << "Strategy 1 (Splitting into two containers):" << endl;

    auto startVector = chrono::high_resolution_clock::now();
    strategy1(studentsVector, passedVector, failedVector);
    auto endVector = chrono::high_resolution_clock::now();
    cout << "Time (Vector): " << chrono::duration_cast<chrono::nanoseconds>(endVector - startVector).count() << " ms" << endl;

    auto startList = chrono::high_resolution_clock::now();
    strategy1(studentsList, passedList, failedList);
    auto endList = chrono::high_resolution_clock::now();
    cout << "Time (List): " << chrono::duration_cast<chrono::nanoseconds>(endList - startList).count() << " ms" << endl;

    auto startDeque = chrono::high_resolution_clock::now();
    strategy1(studentsDeque, passedDeque, failedDeque);
    auto endDeque = chrono::high_resolution_clock::now();
    cout << "Time (Deque): " << chrono::duration_cast<chrono::nanoseconds>(endDeque - startDeque).count() << " ms" << endl;

    vector<Person> failedVector2;
    list<Person> failedList2;
    deque<Person> failedDeque2;

    cout << "Strategy 2 (Splitting into one container):" << endl;

    auto startVector2 = chrono::high_resolution_clock::now();
    strategy2(studentsVector, failedVector2);
    auto endVector2 = chrono::high_resolution_clock::now();
    cout << "Time (Vector): " << chrono::duration_cast<chrono::nanoseconds>(endVector2 - startVector2).count() << " ms" << endl;

    auto startList2 = chrono::high_resolution_clock::now();
    strategy2(studentsList, failedList2);
    auto endList2 = chrono::high_resolution_clock::now();
    cout << "Time (List): " << chrono::duration_cast<chrono::nanoseconds>(endList2 - startList2).count() << " ms" << endl;

    auto startDeque2 = chrono::high_resolution_clock::now();
    strategy2(studentsDeque, failedDeque2);
    auto endDeque2 = chrono::high_resolution_clock::now();
    cout << "Time (Deque): " << chrono::duration_cast<chrono::nanoseconds>(endDeque2 - startDeque2).count() << " ms" << endl;

    cout << "Data processing completed!" << endl;
    return 0;
}
