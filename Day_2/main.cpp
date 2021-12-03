#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file;
    file.open("C:\\Users\\Tomek\\Desktop\\instructions.txt");

    if (!file) {
    std::cerr << "Unable to open this file!";
    exit(1);
    }
    int horizontal{};
    int depth{};
    int valueH{};
    int valueD{};

    std::string line;
    while (std::getline(file, line)) {
        if (!line.find("forward")) {
            // std::cout << line << '\n';
            valueH = line.back() - 48;
            horizontal += valueH;
            // std::cout << horizontal << '\n';
        }
        if (!line.find("down")) {
            // std::cout << line << '\n';
            valueD = line.back() - 48;
            depth += valueD;
            // std::cout << depth << '\n';
        }
        if (!line.find("up")) {
            // std::cout << line << '\n';
            valueD = line.back() - 48;
            depth -= valueD;
            // std::cout << depth << '\n';            
        }
    }
    int multiplication{};
    multiplication = horizontal * depth;
    std::cout << '\n' << multiplication << '\n';
    file.close();
    return 0;
}