#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream input_file;
    input_file.open(filename.c_str());
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return;
    }

    std::string output_filename = filename + ".replace";
    std::ofstream output_file;
    output_file.open(output_filename.c_str());
    if (!output_file.is_open()) {
        std::cerr << "Error: Could not create file '" << output_filename << "'" << std::endl;
        input_file.close();
        return;
    }

    // ----------------->    (read file line by line and replace occurrences)   <-------
   std::string line;
    while (std::getline(input_file, line))
    {
        std::string result;
        size_t i = 0;

        while (i < line.length())
        {
            size_t j = 0;
            size_t pos = i;
            while (i < line.length() && j < s1.length() && line[i] == s1[j])
            {
                i++;
                j++;
            }
            if (j == s1.length())
                result += s2;
            else {
                result += line[pos];
                i = pos + 1;
            }
        }
    
        output_file << result;
        
        if (!input_file.eof())
            output_file << std::endl;
    }
    input_file.close();
    output_file.close();
    
    std::cout << "Successfully created '" << output_filename << "'" << std::endl;
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