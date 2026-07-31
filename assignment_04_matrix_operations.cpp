#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function prototypes
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string label);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p);

int main() {
    int choice;

    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        // ---------------- PART A: TRANSPOSE ----------------
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matrix, rows, cols);
        displayMatrix(matrix, rows, cols, "Original Matrix:");

        transposeMatrix(matrix, result, rows, cols);
        displayMatrix(result, cols, rows, "Transposed Matrix:");

    } else if (choice == 2) {
        // ---------------- PART B: ADDITION ----------------
        int rows, cols;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter Matrix A:" << endl;
        readMatrix(a, rows, cols);
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(b, rows, cols);

        displayMatrix(a, rows, cols, "Matrix A:");
        displayMatrix(b, rows, cols, "Matrix B:");

        addMatrices(a, b, result, rows, cols);
        displayMatrix(result, rows, cols, "Sum (A + B):");

    } else if (choice == 3) {
        // ---------------- PART C: MULTIPLICATION ----------------
        int m, n, n2, p;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A (N): ";
        cin >> n;

        cout << "Enter rows of Matrix B (N): ";
        cin >> n2;
        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        if (n != n2) {
            cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            return 0;
        }

        cout << "\nEnter Matrix A:" << endl;
        readMatrix(a, m, n);
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(b, n, p);

        displayMatrix(a, m, n, "Matrix A:");
        displayMatrix(b, n, p, "Matrix B:");

        multiplyMatrices(a, b, result, m, n, p);
        displayMatrix(result, m, p, "Product (A x B):");

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

// Reads a matrix element by element from user input
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Displays a matrix in a neat, aligned grid
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string label) {
    cout << "\n" << label << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Computes the transpose of a matrix (rows become columns)
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Computes the element-wise sum of two matrices
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Computes the matrix product A (M x N) times B (N x P), result is M x P
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
