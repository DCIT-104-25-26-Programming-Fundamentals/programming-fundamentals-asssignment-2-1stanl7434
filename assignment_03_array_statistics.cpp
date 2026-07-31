#include <iostream>
using namespace std;

// Function prototypes
int calculateSum(int arr[], int n);
double calculateAverage(int arr[], int n);
int findMaximum(int arr[], int n);
int findMinimum(int arr[], int n);

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    int* numbers = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int sum = calculateSum(numbers, n);
    double average = calculateAverage(numbers, n);
    int maximum = findMaximum(numbers, n);
    int minimum = findMinimum(numbers, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    delete[] numbers;
    return 0;
}

// Adds up all elements in the array
int calculateSum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Computes the average of the array elements
double calculateAverage(int arr[], int n) {
    int total = calculateSum(arr, n);
    return static_cast<double>(total) / n;
}

// Finds the largest value in the array
int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Finds the smallest value in the array
int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
