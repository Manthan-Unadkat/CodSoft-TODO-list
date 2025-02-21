#include <iostream>
#include <vector>
using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

vector<Task> tasks;
int taskIdCounter = 1;

void addTask(string description) {
    tasks.push_back({taskIdCounter++, description, false});
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "To-Do List:\n";
    for (const auto &task : tasks) {
        cout << "ID: " << task.id << " - " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(int id) {
    for (auto &task : tasks) {
        if (task.id == id) {
            task.completed = true;
            cout << "Task marked as completed!\n";
            return;
        }
    }
    cout << "Task not found!\n";
}

void removeTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task removed successfully!\n";
            return;
        }
    }
    cout << "Task not found!\n";
}

int main() {
    int choice;
    string description;
    int id;
    
    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task ID to mark as completed: ";
                cin >> id;
                markTaskCompleted(id);
                break;
            case 4:
                cout << "Enter task ID to remove: ";
                cin >> id;
                removeTask(id);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
