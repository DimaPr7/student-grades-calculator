#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <vector>
#include <string>
#include "Person.h"

void readDataFromFile(const std::string& filename, std::vector<Person>& students);
void generateRandomData(const std::string& filename, size_t numStudents);

#endif // FILEUTILS_H
