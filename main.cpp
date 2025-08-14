#include <iostream>
#include <fstream>
#include <string>

void Terminate() {
    exit(0);
}

void Create(const std::string &fileName) {
    std::ofstream file(fileName);
}

bool fileExists(const std::string &fileName) {
    std::ifstream file(fileName);
    return file.is_open();
}

bool isFileEmpty(const std::string &fileName) {
    std::ifstream file(fileName);
    return file.peek() == std::ifstream::traits_type::eof();
}

int main(){
      std::string A = "Email.csv"; // Source file
    std::string B = "Destination_File.csv"; // Destination file
 
    // 1. Check if A.csv exists
    if (!fileExists(A)) {
        std::cerr << "[ERROR] " << A << " not found. Terminating.\n";
        Terminate();
    } else {
        std::cout << "[INFO] " << A << " found.\n";
    }

    //2. check if A.csv is empty
    if (isFileEmpty(A)) {
        std::cerr << "[ERROR] " << A << " is empty. Terminating.\n";
        Terminate();
    } else {
        std::cout << "[INFO] " << A << " has data.\n";
    }
    
    
 
}