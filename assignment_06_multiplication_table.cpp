#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << setw(2) << i << "  =  " << num * i << endl;
    }
}

void printAllTables(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    printTable(num);

    int n;
    cout << "Enter N (for tables 1 to N): ";
    cin >> n;
    printAllTables(n);

    return 0;
}
