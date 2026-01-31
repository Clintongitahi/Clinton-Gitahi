#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int mainArray[20];
    std::vector<int> evens;
    std::vector<int> odds;

    std::cout << "Main Array: ";
    for (int i = 0; i < 20; i++) {
        mainArray[i] = (rand() % 100) + 1; 
        std::cout << mainArray[i] << " ";

        if (mainArray[i] % 2 == 0) {
            evens.push_back(mainArray[i]);
        } else {
            odds.push_back(mainArray[i]);
        }