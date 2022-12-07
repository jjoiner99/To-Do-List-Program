#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "toDoList.h"

using namespace std;

toDoList::~toDoList(void){ //ToDo List class destructor
    ;
}

//Function used to handle exporting list to a .txt file for further user use.
void exportList(toDoList list)
{
    vector<string>::iterator ptr;
    string filename = list.getTitle() + ".txt";
    int counter = 1;
    vector<string> l = list.getList();
    if(!l.empty()){ //If user created list is not empty, export file
        ofstream file (filename);
        file << list.getTitle() << endl;
        for(ptr=l.begin(); ptr<l.end(); ptr++){
            file << to_string(counter) + ". " << *ptr << endl;
            counter++;
        }
        cout << "list exported successfully to " << filename << endl;
    }
    else{cout << "List is empty, no file exported." << endl;}
}

//Function to create List
void createList(toDoList& newList)
{   
    string title, item;

    cout << "Enter list title: ";
    cin.clear();
    cin.sync();
    getline(cin, title);
    newList.setTitle(title);

    do{ //Main loop for user to enter items/tasks
        cout << "Enter list items now, then enter 'end' to finish." << endl;
        cin.clear();
        cin.sync();
        getline(cin, item);
        if(item == "end"){
            return;
        }
        else{
            newList.addToList(item);
        }
    }while(true);

}

int main(){
    string response;
    toDoList l;

    START:cout << "Hello, would you like to create a new To-do list? Enter yes or no" << endl;
    cin >> response;
    if(response == "yes"){
        createList(l);
        exportList(l);
    }
    else if(response == "no"){
        return 0;
    }
    else{
        cout << "Unrecognized response, please try again" << endl;
        goto START;
    } 
}