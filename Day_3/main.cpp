#include <fstream>
#include <iostream>
#include <string>

int main() {

    std::ifstream file;
    file.open("C:\\Users\\Tomek\\Desktop\\powerConsumption.txt");

    if(!file) {
        std::cerr << "Unable to open file";
        exit(1);
    }

    char ch{};
    int a[1000][12]{};
    int b[12][1000]{};
    int zeros{};
    int ones{};
    std::string result{};

    for(int i{}; i < 1000; ++i) {
        for(int j{}; j < 12; ++j) {
            file >> ch;
            a[i][j] = static_cast<int>(ch) - 48;
            //std::cout << a[i][j];
        }
    }
    for(int i{}; i < 12; ++i) {
        for(int j{}; j < 1000; ++j) {
            b[i][j] = a[j][i];
            // std::cout << b[i][j];
            if(b[i][j] == 0) {
                ++zeros;
            }
            else {
                ++ones;
            }
        }
        if(zeros > ones) {
            result.append("0");
        }
        else {
            result.append("1");
        }
        zeros = 0;
        ones = 0;
        std::cout << '\n';
    }

    std::cout << "\n\n" << result << '\n';

    return 0;
}