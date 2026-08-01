#include <iostream>
using namespace std;

void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacci(int number) {
    if (number < 0) return false;

    int a = 0, b = 1;
    while (a <= number) {
        if (a == number) return true;
        int next = a + b;
        a = b;
        b = next;
    }
    return false;
}

int main() {
    int n;
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    int number;
    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacci(number))
        cout << number << " is a Fibonacci number." << endl;
    else
        cout << number << " is NOT a Fibonacci number." << endl;

    return 0;
}
