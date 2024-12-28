#include <iostream>
#include <ctime>
#include <iomanip>

class ExecutionTimer {
private:
    clock_t startTime;
    bool useFile;

public:
    ExecutionTimer(bool useFileIO = false) : useFile(useFileIO) {
        startTime = clock();
        if (useFile) {
            setupFileIO();
        }
        setupIO();
    }

    // Destructor now always prints the time
    ~ExecutionTimer() {
        printExecutionTime();
    }

    double getExecutionTime() const {
        return static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
    }

private:
    void setupIO() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cout << std::fixed << std::setprecision(6);
    }

    void setupFileIO() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    void printExecutionTime() {
        std::cout << "\nExecution Time: " << getExecutionTime() << " seconds" << std::endl;
    }
};

// Example usage with Euclid's algorithm
int main() {
    ExecutionTimer timer(true);  // Create timer object

    // Your Euclid algorithm code here
    long long a, b;
    std::cout << "Enter two numbers to find their GCD:\n";
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;

    // Calculate GCD
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    std::cout << "GCD is: " << a << std::endl;
    // Timer destructor will automatically print time when main() ends
    return 0;
}
