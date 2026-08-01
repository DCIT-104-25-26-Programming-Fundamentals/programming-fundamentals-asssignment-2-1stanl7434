#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void addTask(vector<string>& tasks) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter task: ";
    string task;
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty!" << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty!" << endl;
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    int num;
    cin >> num;

    if (num < 1 || num > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[num - 1];
    tasks.erase(tasks.begin() + (num - 1));
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\n============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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
