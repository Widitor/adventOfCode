#include <iostream>
#include <fstream>

int main() {
    int howManyTimes{};
    int curr{};
    int prev{};
    std::ifstream file;
    file.open("C:\\Users\\Tomek\\Desktop\\depths.txt");

    if (!file) {
        std::cerr << "Unable to open file.";
        exit(1);
    }

    while (file >> curr) {
        if (prev != 0) {
            if (curr > prev) {
                howManyTimes++;
            }
        }
        prev = curr;
    }

    file.close();
    std::cout << howManyTimes;

    return 0;
}