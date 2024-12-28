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

auto start = std::chrono::high_resolution_clock::now();


template <typename Container>
void strategy1(const Container& students, Container& passed, Container& failed) {
    for (const auto& student : students) {
        if (student.getGrade() >= 5.0) {
            passed.push_back(student);
        } else {
            failed.push_back(student);
        }
    }
}

template <typename Container>
void strategy2(Container& students, Container& failed) {
    auto it = remove_if(students.begin(), students.end(),
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
    const size_t numStudents = 100000;
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

    vector<Person> passedVector, failedVector;
    list<Person> passedList, failedList;
    deque<Person> passedDeque, failedDeque;

    cout << "Strategy 1 (Splitting into two containers):" << endl;

    auto start = chrono::high_resolution_clock::now();
    strategy1(studentsVector, passedVector, failedVector);
    auto end = chrono::high_resolution_clock::now();
    cout << "Time (Vector): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    strategy1(studentsList, passedList, failedList);
    end = chrono::high_resolution_clock::now();
    cout << "Time (List): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    strategy1(studentsDeque, passedDeque, failedDeque);
    end = chrono::high_resolution_clock::now();
    cout << "Time (Deque): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    // Strategy 2: Separate students into one container and shrink the original
    vector<Person> failedVector2;
    list<Person> failedList2;
    deque<Person> failedDeque2;

    cout << "Strategy 2 (Splitting into one container):" << endl;

    start = chrono::high_resolution_clock::now();
    strategy2(studentsVector, failedVector2);
    end = chrono::high_resolution_clock::now();
    cout << "Time (Vector): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    strategy2(studentsList, failedList2);
    end = chrono::high_resolution_clock::now();
    cout << "Time (List): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    strategy2(studentsDeque, failedDeque2);
    end = chrono::high_resolution_clock::now();
    cout << "Time (Deque): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    cout << "Data processing completed!" << endl;
    return 0;
}