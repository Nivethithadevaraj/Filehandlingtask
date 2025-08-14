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
    
    
    // 3. Check if B.csv exists
    if (!fileExists(B)) {
        std::cout << "[INFO] " << B << " not found. Creating new file.\n";
        Create(B);
    } else {
        std::cout << "[INFO] " << B << " found.\n";
        // If found and not empty → empty it
        if (!isFileEmpty(B)) {
            std::cout << "[ACTION] " << B << " has data. Clearing contents.\n";
            Create(B);
        } else {
            std::cout << "[INFO] " << B << " is already empty.\n";
        }
    }
    // 4. Copy contents from A.csv to B.csv
    std::ifstream inFile(A);
    std::ofstream outFile(B, std::ios::app);
 
    std::cout << "[ACTION] Copying contents from " << A << " to " << B << "...\n";
    std::string line;
    while (std::getline(inFile, line)) {
        outFile << line << "\n";
    }
 
    // Close files
    inFile.close();
    outFile.close();
 
    std::cout << "[SUCCESS] Data copied from " << A << " to " << B << ".\n";
 
    return 0;
 
 
}