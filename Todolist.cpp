#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;    
    bool completed; 
};
void showMenu() {
    cout << "\nTo Do List Manager:\n";
    cout << "\n 1. Add Task";
    cout << "\n 2. View Tasks";
    cout << "\n 3. Mark Task as Completed";
    cout << "\n 4. Delete Task";
    cout << "\n 5. Exit";
    cout << "\n Choose an option---> ";
}
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter the task--> ";
    cin.ignore();
    getline(cin, newTask.name);
    newTask.completed = false;  
    tasks.push_back(newTask);  
    cout << "\n Task added";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n No tasks available";
    } else {
        cout << "\n Your tasks-->""\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].name;
            cout << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
}
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n No tasks to mark as completed";
        return;
    }

    int taskNum;
    cout << "Enter the task number to mark as completed--> ";
    cin >> taskNum;

    if (taskNum >= 1 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "\n Task marked as completed";
    } else {
        cout << "\n Invalid task number";
    }
}
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n No tasks to delete";
        return;
    }

    int taskNum;
    cout << "\n Enter the task number to delete--> ";
    cin >> taskNum;

    if (taskNum >= 1 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1); 
        cout << "\n Task deleted";
    } else {
        cout << "\n Invalid task number";
    }
}
int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu(); 
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks); 
                break;
            case 3:
                markTaskCompleted(tasks); 
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "\n Invalid choice. Please try again"; 
        }
    } while (choice != 5);
    return 0;
}
