#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <vector>
#include "Person.h"

void readDataFromFile(const std::string& filename, std::vector<Person>& students);

#endif // FILEUTILS_H
