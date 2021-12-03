#include <iostream>
#include <fstream>

int main() {
    int howManyTimes{};
    int curr{};
    // int prev{};
    int A[3]{};
    int B[3]{};
    int C[3]{};
    std::ifstream file;
    file.open("C:\\Users\\Tomek\\Desktop\\depths.txt");

    if (!file) {
        std::cerr << "Unable to open file.";
        exit(1);
    }

    int tempA{};
    int tempB{};
    int tempC{};

    int sumA{};
    int sumB{};
    int sumC{};

    while (file >> curr) {
        if (tempA == 3) {
            sumA = A[0] + A[1] + A[2];
            tempA = 0;
        }
        A[tempA] = curr;
        if (tempA != 0 || tempB != 0) {
            if(tempB == 3) {
                sumB = B[0] + B[1] + B[2];
                tempB = 0;
            }
            B[tempB] = curr;
            if (tempB != 0 || tempC != 0) {
                if (tempC == 3) {
                    sumC = C[0] + C[1] + C[2];
                    tempC = 0;
                }
            C[tempC] = curr;
            ++tempC;
            }
            ++tempB;
        }
        ++tempA;
        if (tempA == 2 && tempB == 1) {
            if(sumA < sumB) {
                ++howManyTimes;
            }
        }
        if (tempB == 2 && tempC == 1) {
            if(sumB < sumC) {
                ++howManyTimes;
            }
        }
        if (tempC == 2 && tempA == 1) {
            if (sumC < sumA) {
                ++howManyTimes;
            }
        }
    }

    file.close();
    std::cout << howManyTimes;

    return 0;
}