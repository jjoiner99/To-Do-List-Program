#include <string>
#include <vector>

using namespace std;

class toDoList
{
private:
    string title;
    vector<string> list;
    
public:
    toDoList(){
        title = "Title";
    }

    void setTitle(string t){
        title = t;
    }

    string getTitle(){
        return title;
    }

    void addToList(string item){
        list.push_back(item);
    }

    vector<string> getList(){
        return list;
    }

    void printList(){
        for(string x : list){
            cout << x << endl;
        }
    }

    ~toDoList(void);
};
