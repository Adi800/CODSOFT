#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string name; 
    bool completed; 

public:
    Task(const string& name)
        : name(name)
        , completed(false)
    {
    }
    string getName() const { return name; }
    bool isCompleted() const { return completed; }

    void setName(const string& name) { this->name = name; }

    void markAsDone() { completed = true; }

    void displayTask() const
    {
        cout << name << " ("<< (completed ? "Completed" : "Pending") <<")"<< endl;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void displayMenu()
    {
        cout<< "Select your choice->"<<endl;
        cout << "1. Add Task"<<endl;
        cout << "2. Delete Task"<<endl;
        cout << "3. View Tasks"<<endl;
        cout << "4. Mark as Done Task"<<endl;
        cout << "5. Exit"<<endl;
    }

    void addTask()
    {
        string name;
        cout << "Enter task : ";
        cin.ignore();
        getline(cin, name);

        tasks.emplace_back(name);
        cout << "Task added successfully!" << endl;
    }

    void removeTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to remove!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to remove: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    void displayTasks()
    {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    void markAsDone()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as done!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to mark as done: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markAsDone();
            cout << "Task marked as done!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    void run()
    {
        int ch;
        while (ch != 6) {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> ch;

            switch (ch) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                markAsDone();
                break;
            case 5:
                cout << "Do the tasks ASAP. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!"<< endl;
            }
        } ;
    }
};

int main()
{
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
