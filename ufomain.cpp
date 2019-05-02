// ufomain.cpp
// main function

#include "ufo.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using ufo::Ufo;

void BoxPrint(int num, string message){
    int c = num - 1;
    int x = message.size();

    for(int i = 0; i <= c; i++){
        for(int i = 0; i <= 2*c + x + 2; i ++)
            cout << "@";
        cout << "@" << endl;
    }

    for(int a = 0; a <= 2; a++){
        if(a == 1){
            for(int i = 0; i <= c; i++)
                cout << "@";
            cout << " ";
            cout << message << " ";
            for(int i = 0; i < c; i++)
                cout << "@";
        }

        if(a == 0 || a == 2) {
            for(int i = 0; i <= c; i++)
                cout << "@";
            for(int i = 0; i < x + 2; i++)
                cout << " ";
            for(int i = 0; i < c; i++)
                cout << "@";
        }

        cout << "@" << endl;
    }

    for(int i = 0; i <= c; i++){
        for(int i = 0; i <= 2*c + x + 2; i ++)
            cout << "@";
        cout << "@" << endl;
    }
}

int main() {
    BoxPrint(3, "Welcome to UFO!");

    while(true) {
        cout << endl;
        cout << "Please choose a file / folder path directory [enter to quit]: ";

        string rootpath;
        getline(cin, rootpath);

        ufo::Ufo organizer(rootpath);

        // if file path cannot be opened...
        if (rootpath.empty()) {
            cout << "*****************************************" << endl;
            cout << "ERROR: Please enter a valid file / folder path directory." << endl;
            cout << "*****************************************" << endl;
            break;
        }

        // file path can be opened
        cout << "*****************************************" << endl;
        cout << "file was opened successfully! How would you like to sort the files? " << endl;
        cout << "*****************************************" << endl;

        string organizationPreference;
        getline(cin, organizationPreference);

        cout << "Organizing files..." << endl;
        organizer.sortFolder(organizationPreference);

        for (const auto &folder : organizer.getfolder().folders)
        {
            cout << "Folder: " << folder.name << endl;
            cout << endl;
            for (const auto &file : folder.files)
            {
                cout << file.name << endl;
            }
            cout << endl;
        }
    }

    return 0;
}