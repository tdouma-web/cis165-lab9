#include <iostream>

int main() {
    const int SENTINEL = -99;
    int currentNumber = 0;
    int smallest = 0;
    int largest = 0;
    bool hasData = false;

    std::cout << "Enter a series of integers (" << SENTINEL << " to end): ";
    std::cin >> currentNumber;

    // Sentinel-controlled loop to process a variable-length series
    while (currentNumber != SENTINEL) {
        if (!hasData) {
            // Initialize extrema from the very first actual data value
            smallest = currentNumber;
            largest = currentNumber;
            hasData = true;
        } else {
            // Update extrema if a smaller or larger value is entered
            if (currentNumber < smallest) {
                smallest = currentNumber;
            }
            if (currentNumber > largest) {
                largest = currentNumber;
            }
        }

        // Read the next value in the series
        std::cin >> currentNumber;
    }

    // Display results or a clear message if no data was entered
    if (hasData) {
        std::cout << "Smallest: " << smallest << "\n";
        std::cout << "Largest: " << largest << "\n";
    } else {
        std::cout << "No data values were entered.\n";
    }

    return 0;
}