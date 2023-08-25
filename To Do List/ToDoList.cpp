#include <bits/stdc++.h>
using namespace std;

vector<string> tasks;

void viewTasks(){
    if(tasks.size() == 0)
        cout << "No Tasks!\n";
    else{
        cout << "________Tasks________\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << "Task - " << i + 1 << " : " << tasks[i] << endl;
        }
    }
}

void addTask(){
    string task;
    cout << "Enter the task you want to add: ";
    cin >> task;
    tasks.push_back(task);
    cout << "Task Added!\n";
}

void deleteTask(){
    int num;
    cout << "Enter the number of task you want to delete: ";
    cin >> num;
    tasks.erase(tasks.begin() + num-1, tasks.begin() + num);
    cout << "Task Deleted!\n";
}

void editTask(){
    int num;
    string task;
    cout << "Enter the number of task you want to edit: ";
    cin >> num;
    cout << "Enter the modified task: ";
    cin >> task;
    tasks[num-1] = task;
    cout << "Task Modified!\n";
}

void markComplete(){
    int num;
    cout << "Enter the number of task you want to mark as a complete: ";
    cin >> num;
    tasks[num-1] += " (COMPLETED!)";
}

int main(){
    int choice;
    cout << "_________________Welcome To My To Do List_________________\n";
    do {
        cout << "\nYou Can: \n";
        cout << "1- View Tasks.\n";
        cout << "2- Add Task.\n";
        cout << "3- Edit Task.\n";
        cout << "4- Delete Task.\n";
        cout << "5- Mark Task As Complete.\n";
        cout << "Enter '0' To Exit\n";
        cout << "Choose what do you want: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                markComplete();
                break;
            case 6:
                return 0;
        }
    }while(choice != 0);

}