/*Prompt 3a: Task Manager (Use std::list)
Objective:
Use std::list<std::string> to create a simple task list with the following menu options:

Add a task
Remove a task
Show tasks
Exit
 */



#include <iostream>
#include <list>
#include <string>

using namespace std;

void displayTasks(const list <string> & tasks) {
    if (tasks.empty()) {
        cout << "You have no task.\n";
        return;
    }
//had chatgpt help to make a counter
    int i = 1;
    for (const string & task : tasks) {
        cout << i++ << ". " << task << endl;
    }
}

int main() {
    list <string> tasks;
    int choice;
    string task;

    while (true) {
        //menu
        cout << "Welcome to task manager" << endl;
        cout << "_______________________\n" << endl;

        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Show Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice number: ",cin >> choice;
        cin.ignore();

        //Users choices
        switch (choice) {
            case 1:
                cout << "Enter new task: ";
            getline(cin, task);
            tasks.push_back(task);
            cout << "Added to task!\n";
            break;

            //task items
            case 2:
                //if task is empty
                if (tasks.empty()) {
                    cout << "No tasks to remove.\n";
                    break;
                }
            //asking which task to remove
            displayTasks(tasks);
            int taskNumber;
            cout << "Enter task number to remove: ";
            cin >> taskNumber;

            //had some help with this, i was struggling with this
            if (taskNumber > 0 && taskNumber <= tasks.size()) {
                list<string>::iterator currentTask = tasks.begin();
                for (int i = 0; i < taskNumber - 1; i++) {
                    i++;
                }
                tasks.erase(currentTask);
                cout << "Task has been removed!\n";

            } else {
                cout << "Invalid task number.\n";
            }
            break;


            case 3:
                displayTasks(tasks);
            break;


            case 4:
                cout << "Exiting task manager\n";
            return 0;


            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
