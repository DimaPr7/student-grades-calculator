#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <vector>
#include "Person.h"

void readDataFromFile(const std::string& filename, std::vector<Person>& students);
void generateRandomData(const std::string& filename, size_t numStudents);
void generateFiles();

#endif // FILEUTILS_H
