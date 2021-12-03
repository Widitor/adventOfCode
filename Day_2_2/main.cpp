#include <fstream>
#include <iostream>
#include <string>

int readValue(std::string s) {
        return s.back() - 48;
    }

int main() {
    std::ifstream file;
    file.open("C:\\Users\\Tomek\\Desktop\\instructions.txt");

    if (!file) {
    std::cerr << "Unable to open this file!";
    exit(1);
    }

    int horizontal{};
    int depth{};
    int aim{};

    std::string line;
    while (std::getline(file, line)) {
        if (!line.find("forward")) {
            horizontal += readValue(line);
            depth += (readValue(line) * aim);    
        }
        if (!line.find("down")) {
            aim += readValue(line);
        }
        if (!line.find("up")) {
            aim -= readValue(line);
        }
    }
    std::cout << horizontal << '\n';
    std::cout << depth << '\n';

    int multiplication{};
    multiplication = horizontal * depth;
    std::cout << multiplication << '\n';

    return 0;
}