#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double getAverage(const Student& s) {
    if (s.scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int count;
    cout << "How many scores? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    for (const Student& s : students) {
        cout << "Name: " << s.name << endl;
        cout << "ID: " << s.id << endl;
        cout << "Scores: ";
        for (size_t i = 0; i < s.scores.size(); i++) {
            cout << s.scores[i];
            if (i != s.scores.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "Average: " << getAverage(s) << endl;
        cout << "--------------------------------" << endl;
    }
}

void calculateAverage(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << getAverage(s) << endl;
            return;
        }
    }

    cout << "Error: No student found with ID " << id << "." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                calculateAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
