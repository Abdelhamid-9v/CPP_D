#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        exit(1);
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create file '" << outputFilename << "'" << std::endl;
        inputFile.close();
        exit(1);
    }

    // Read file line by line and replace occurrences
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string result;
        size_t pos = 0;
        size_t foundPos = 0;

        while ((foundPos = line.find(s1, pos)) != std::string::npos){
            result.append(line, pos, foundPos - pos);
            result.append(s2);
            pos = foundPos + s1.length();
        }
        
        result.append(line, pos, line.length() - pos);
        
        outputFile << result;
        
        if (!inputFile.eof()) {
            outputFile << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();
    
    std::cout << "Successfully created '" << outputFilename << "'" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);

    return 0;
}