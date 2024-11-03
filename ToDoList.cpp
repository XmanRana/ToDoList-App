#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully!" << endl;
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].isCompleted = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void displayTasks() const {
        cout << "\nTo-Do List:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description
                 << (tasks[i].isCompleted ? " [Completed]" : " [Incomplete]") << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string description;
    int taskNumber;

    while (true) {
        cout << "\n1. Add Task\n2. Complete Task\n3. Display Tasks\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                todoList.addTask(description);
                break;
            case 2:
                cout << "Enter task number to complete: ";
                cin >> taskNumber;
                todoList.completeTask(taskNumber - 1);
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }
}
