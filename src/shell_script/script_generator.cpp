#include <iostream>
#include <fstream>

#include "generator.h"

void createCFile(const char* filename, const char* content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error creating file: " << filename << std::endl;
        return;
    }
    file << content;
    file.close();
    std::cout << "File " << filename << " created successfully." << std::endl;
}
