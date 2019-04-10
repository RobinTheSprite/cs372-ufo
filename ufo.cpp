#include <Windows.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
//#include "retriever-win.h"

struct file {
    string name;
    string path;
    int size;
    vector<int> dateCreated;
    vector<int> dateModified;
};

struct folder{
    vector<folder> folders;
    vector<file> files;
    string path;
};

class Ufo{
public:
    explicit Ufo(const string &rootPath): _rootPath{rootPath}{
        _folder.path = _rootPath;
    }

    folder getfolder() const{
        return _folder;
    }

    void printError(){
        cout << "dummy" << endl;
    }

    vector<WIN32_FIND_DATA> retrieveWin(){
        vector<WIN32_FIND_DATA> dummy;
        return dummy;
    }


private:
    string _rootPath; //here root means the current root node, as in the folder we are opening, not the whole system's root directory
    folder _folder;
};




int main() {
    std::cout << "Welcome to the Universal File System" << std::endl;
    return 0;
}