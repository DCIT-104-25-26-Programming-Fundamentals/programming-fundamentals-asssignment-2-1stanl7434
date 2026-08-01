#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, bool& valid) {
    if (b == 0) {
        valid = false;
        return 0.0;
    }
    valid = true;
    return a / b;
}

double modulus(double a, double b, bool& valid) {
    if (b == 0) {
        valid = false;
        return 0.0;
    }
    valid = true;
    return fmod(a, b);
}

double exponent(double base, double exp) {
    return pow(base, exp);
}

int main() {
    int choice;
    double a, b;
    bool valid;

    do {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;
            cout << fixed << setprecision(2);
        }

        switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
                break;
            case 4: {
                double result = divide(a, b, valid);
                if (valid)
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                else
                    cout << "Error: Cannot divide by zero." << endl;
                break;
            }
            case 5: {
                double result = modulus(a, b, valid);
                if (valid)
                    cout << "Result: " << a << " % " << b << " = " << result << endl;
                else
                    cout << "Error: Cannot perform modulus by zero." << endl;
                break;
            }
            case 6:
                cout << "Result: " << a << " ^ " << b << " = " << exponent(a, b) << endl;
                break;
            case 7:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    } while (choice != 7);

    return 0;
}
