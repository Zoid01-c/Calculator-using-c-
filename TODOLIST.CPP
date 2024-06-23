#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct todolist
{
    int id;
    char task[100]; // using char array instead of string
    int completed; // using int instead of bool
};

int ID = 0;
struct todolist todoList[100];

void banner();
void addtask();
void showtask();
void searchtask();
void deletetask();
void completetask();

// Define true and false for Turbo C++
#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

int main()
{
    clrscr(); // Turbo C++ specific clear screen function

    while(true)
    {
        banner();
        cout<<"1] Add task"<<endl;
        cout<<"2] Show task"<<endl;
        cout<<"3] Search task"<<endl;
        cout<<"4] Delete task"<<endl;
        cout<<"5] Complete task"<<endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addtask();
                break;

            case 2:
                showtask();
                break;

            case 3:
                searchtask();
                break;

            case 4:
                deletetask();
                break;

            case 5:
                completetask();
                break;

            default:
                break;
        }
    }

    return 0;
}

void banner()
{
    cout<<"______________________________"<<endl;
    cout<<"       My Todo list         "<<endl;
    cout<<"______________________________"<<endl;
}

void addtask()
{
    clrscr();
    banner();
    struct todolist todo;
    cout<<"Enter New task: ";
    cin.get();
    cin.getline(todo.task, 100);
    char save;
    cout<<"Save? (y/n): ";
    cin>>save;
    if(save=='y')
    {
        todo.id = ++ID;
        todo.completed = false; // initialize as incomplete
        todoList[ID-1] = todo;
        cout<<"Task added successfully!"<<endl;
    }
    else
    {
        cout<<"Task not saved!"<<endl;
    }
    getch(); // wait for user input (similar to system("pause"))
}

void showtask()
{
    clrscr();
    banner();
    if(ID == 0)
    {
        cout<<"No tasks available!"<<endl;
    }
    else
    {
        for(int i=0; i<ID; i++)
        {
            cout<<"Task ID: "<<todoList[i].id<<endl;
            cout<<"Task: "<<todoList[i].task<<endl;
            cout<<"Completed: "<<(todoList[i].completed? "Yes" : "No")<<endl;
            cout<<endl;
        }
    }
    getch();
}

void searchtask()
{
    clrscr();
    banner();
    int searchID;
    cout<<"Enter task ID to search: ";
    cin>>searchID;
    for(int i=0; i<ID; i++)
    {
        if(todoList[i].id == searchID)
        {
            cout<<"Task ID: "<<todoList[i].id<<endl;
            cout<<"Task: "<<todoList[i].task<<endl;
            cout<<"Completed: "<<(todoList[i].completed? "Yes" : "No")<<endl;
            getch();
            return;
        }
    }
    cout<<"Task not found!"<<endl;
    getch();
}

void deletetask()
{
    clrscr();
    banner();
    int deleteID;
    cout<<"Enter task ID to delete: ";
    cin>>deleteID;
    for(int i=0; i<ID; i++)
    {
        if(todoList[i].id == deleteID)
        {
            for(int j=i; j<ID; j++)
            {
                todoList[j] = todoList[j+1];
            }
            ID--;
            cout<<"Task deleted successfully!"<<endl;
            getch();
            return;
        }
    }
    cout<<"Task not found!"<<endl;
    getch();
}

void completetask()
{
    clrscr();
    banner();
    int completeID;
    cout<<"Enter task ID to mark as complete or incomplete: ";
    cin>>completeID;
    for(int i=0; i<ID; i++)
    {
        if(todoList[i].id == completeID)
        {
            todoList[i].completed = !todoList[i].completed; // toggle completion status
            cout<<"Task completion status updated!"<<endl;
            getch();
            return;
        }
    }
    cout<<"Task not found!"<<endl;
    getch();
}
