#include <iostream>
#include <fstream>

#include "generator.h"

void createFile(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error creating file: " << filename << std::endl;
        return;
    }
    file.close();
    std::cout << "File " << filename << " created successfully." << std::endl;
}

void te()
{
  std::cout << "Cleitus" << std::endl;
}
