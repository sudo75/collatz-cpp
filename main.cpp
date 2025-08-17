#include <iostream>
#include <string>
#include <cmath>

int numberOfIterations(unsigned int start);
unsigned long long doIteration(unsigned long long value);
void showProgress(unsigned int start, unsigned int end, unsigned int current);

int main() {

    while (0 < 1) {
        std::cout << "******** Collatz-cpp ********\n";

        std::cout << "Choose a range to calculate for." << '\n';

        std::cout << "Start value:" << '\n';
        unsigned int start_value;
        do {
            std::cin >> start_value;
        } while (!(start_value > 1));
        

        std::cout << "End value:" << '\n';
        unsigned int end_value;
        do {
            std::cin >> end_value;
        } while (!(end_value > 1));


        unsigned int longest_sequence;
        unsigned int most_iterations = 0;

        for (unsigned int i = start_value; i <= end_value; i++) {
            int iterations = numberOfIterations(i);

            if (iterations > most_iterations) {
                most_iterations = iterations;
                longest_sequence = i;
            }

            if (i == start_value || i % 100000 == 0 || i == end_value) {
                showProgress(start_value, end_value, i);
            }
            //std::cout << "** Input value: " << i << ", Iterations: " << iterations << " **" << '\n';
        }

        std::cout << "\n\n" << "**** Longest sequence: " << most_iterations << " iterations, Input value: " << longest_sequence << ", Range: " << start_value << " - " << end_value << " ****";

        for (int i = 0; i < 5; i++) {
            std::cout << '\n';
        }
    }

    return 0;
}

unsigned long long doIteration(unsigned long long value) {

    if (value % 2 == 0) {
        return value / 2;
    } else {
        return value * 3 + 1;
    }
}

int numberOfIterations(unsigned int value_) {

    unsigned long long value = static_cast<unsigned long long>(value_);

    int iterations = 0;
    while (value != 1) {
        value = doIteration(value);
        iterations++;
    }

    return iterations;
}

void showProgress(unsigned int start, unsigned int end, unsigned int current) {
    float progress_decimal = float(current - start + 1) / float(end - start + 1);

    int bar_length = 20;

    int bars_filled = int(std::floor(progress_decimal * (float)bar_length));

    std::string output = "[";
    for (int i = 0; i < bar_length; i++) {
        if (i < bars_filled) {
            output.append("=");
        } else {
            output.append(" ");
        }
    }
    output.append("] ");

    int progress_percentage = std::floor(int(progress_decimal * 100));
    output.append(std::to_string(progress_percentage) + "%");

    //std::cout << output << '\n';
    std::cout << "\r" << output << std::flush;
}