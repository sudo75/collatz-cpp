#include <iostream>

int numberOfIterations(int start);
int doIteration(int value);

int main() {

    std::cout << "******** Collatz-cpp ********\n";

    std::cout << "Choose a range to calculate for." << '\n';

    std::cout << "Start value:" << '\n';
    int start_value;
    do {
        std::cin >> start_value;
    } while (!(start_value > 1));
    

    std::cout << "End value:" << '\n';
    int end_value;
    do {
        std::cin >> end_value;
    } while (!(end_value > 1));

    for (int i = start_value; i <= end_value; i++) {
        int iterations = numberOfIterations(i);
        
        std::cout << "** Input value: " << i << " , Iterations: " << iterations << " **" << '\n';
    }
    

    return 0;
}

int doIteration(int value) {
    if (value % 2 == 0) {
        return value / 2;
    } else {
        return value * 3 + 1;
    }
}

int numberOfIterations(int value) {

    int iterations = 0;
    while (value != 1) {
        value = doIteration(value);
        iterations++;
    }

    return iterations;
}