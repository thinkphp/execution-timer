#include <stdio.h>
#include <time.h>

// Structure to hold timer data
struct ExecutionTimer {
    clock_t startTime;
    int useFile;
};

// Functions to handle timer operations
void initTimer(struct ExecutionTimer* timer, int useFile) {
    timer->startTime = clock();
    timer->useFile = useFile;

    if (useFile) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
}

double getExecutionTime(const struct ExecutionTimer* timer) {
    return ((double)(clock() - timer->startTime)) / CLOCKS_PER_SEC;
}

void printExecutionTime(const struct ExecutionTimer* timer) {
    printf("\nExecution Time: %.6f seconds\n", getExecutionTime(timer));
}

// Euclidean algorithm function
long long euclid(long long a, long long b) {
    if (b == 0) return a;
    return euclid(b, a % b);
}

int main() {
    // Initialize timer
    struct ExecutionTimer timer;
    initTimer(&timer, 1);  // 0 means don't use file I/O, 1 to use files

    // Input numbers
    long long a, b;
    printf("Enter two numbers to find their GCD:\n");
    printf("Enter first number: ");
    scanf("%lld", &a);
    printf("Enter second number: ");
    scanf("%lld", &b);

    // Calculate GCD
    long long result = euclid(a, b);

    // Print result
    printf("\nGCD of %lld and %lld is: %lld\n", a, b, result);

    // Print execution time
    printExecutionTime(&timer);

    return 0;
}
