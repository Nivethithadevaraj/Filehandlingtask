#include <iostream>
#include <fstream>
#include <string>

void Terminate() {
    exit(0);
}
bool fileExists(const std::string &fileName) {
    std::ifstream file(fileName);
    return file.is_open();
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
}