#include <iostream>
#include <fstream>
#include <string>

void OutputFile() {
    std::ofstream file("cpp-review\\c\\file.c"); // create if not present

    if (file.is_open()) {
        file << "#include <stdio.h>" << '\n';
        file << "int main() { }" << '\n';
        file.close();
        std::cout << "File written successfully" << '\n';
    }
    else {
        std::cout << "File open failed" << '\n';
    }
}

void InputFile() {
    std::ifstream file("cpp-review\\c\\arr-init.cpp");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        file.close();
    }
    else {
        std::cout << "File open failed" << '\n';
    }
}

void AddFile() {
    std::ofstream file("cpp-review\\c\\file.c", std::ios::app);

    if (file.is_open()) {
        file << "\n;;;"; // append last line
        file.close();
        std::cout << "File append write successful" << '\n';
    }
    else {
        std::cout << "File open failed" << '\n';
    }
}

int main() {
    // OutputFile();
    // InputFile();
    // AddFile();
    system("D://distake//speedtest.bat");
    return 0;
}