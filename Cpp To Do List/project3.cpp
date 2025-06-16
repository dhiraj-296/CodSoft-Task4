#include<iostream>
#include<windows.h>
using namespace std;

struct Task {
    string description;
    bool isCompleted = false;
};

// Function to view tasks
void view_tasks(Task tasks[], int task_count) {
    cout << "Tasks To Do:\n";
    cout << "-----------------------\n";
    for (int i = 0; i < task_count; i++) {
        cout << "Task " << i << ": " << tasks[i].description;
        cout << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

int main() {
    system("color a");   // green color
    Task tasks[10];
    int task_count = 0;
    int option = -1;

    while (option != 0) {
        cout << "\n--- TO DO LIST ---\n";
        cout << "1 --- Add New Task\n";
        cout << "2 --- View Tasks\n";
        cout << "3 --- Delete a Task\n";
        cout << "4 --- Mark Task as Completed\n";
        cout << "0 --- Terminate Program\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                if (task_count > 9) {
                    cout << "Task list is full.\n";
                } else {
                    cout << "Enter a new task: ";
                    cin.ignore();
                    getline(cin, tasks[task_count].description);
                    tasks[task_count].isCompleted = false;
                    task_count++;
                }
                break;
            }

            case 2:
                system("cls");
                view_tasks(tasks, task_count);
                break;

            case 3: {
                system("cls");
                int del_task;
                cout << "Enter the task number to delete: ";
                cin >> del_task;
                if (del_task < 0 || del_task >= task_count) {
                    cout << "Invalid task number.\n";
                } else {
                    for (int i = del_task; i < task_count - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    task_count--;
                    cout << "Task deleted successfully.\n";
                }
                break;
            }

            case 4: {
                int task_id;
                cout << "Enter the task number to mark as completed: ";
                cin >> task_id;
                if (task_id < 0 || task_id >= task_count) {
                    cout << "Invalid task number.\n";
                } else {
                    tasks[task_id].isCompleted = true;
                    cout << "Task marked as completed.\n";
                }
                break;
            }

            case 0:
                cout << "Terminating the program...\n";
                break;

            default:
                cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
