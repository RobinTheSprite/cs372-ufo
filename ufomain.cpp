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

// Test folder: ..\our_directory_for_testing\ //

int main() {
    BoxPrint(3, "Welcome to UFO!");

    while(true) {
        cout << endl;
        cout << "Please choose a file / folder path directory [ENTER to quit]: ";

        string rootpath;
        if (cin.get() == '\n'){
            cout << "*****************************************" << endl;
            cout << "Okay, Good bye! :)" << endl;
            cout << "*****************************************" << endl;
            break;
        }
        cin >> rootpath;
        //getline(cin, rootpath);


        ufo::Ufo organizer(rootpath);

        // if file path cannot be opened...
        if (rootpath == "") {
            cout << "*****************************************" << endl;
            cout << "ERROR: Please enter a valid file / folder path directory." << endl;
            cout << "*****************************************" << endl;
            break;
        }

        // file path can be opened
        cout << "*****************************************" << endl;
        cout << "file was opened successfully! How would you like to sort the files? " << endl;
        cout << "*****************************************" << endl;

        cout << "\t [1] file extension" << endl;
        cout << "\t [2] date modified" << endl;
        cout << "\t [3] file size" << endl;


        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Organizing files..." << endl << endl;
                organizer.sortFolder("extension");
                break;
            case 2:
                cout << "This feature hasn't been implemented yet" << endl;
                continue;
            case 3:
                cout << "This feature hasn't been implemented yet" << endl;
                continue;
            default:
                cout << "ERROR: Please choose choice from "
                        "1-3" << endl;
                continue;
        }

        cout << "*****************************************" << endl;
        cout << "UFO has sorted the files in the following extensions: " << endl;
        cout << "*****************************************" << endl;

        ufo::folder sortedFolders  = organizer.getfolder();

        for(auto i = 0; i < sortedFolders.folders.size(); ++i){
            cout << "\t [" << i+1 << "]" + sortedFolders.folders[i].name << endl;
        }

        cout << "*****************************************" << endl;
        cout << "Which file extension were you looking for? (Enter a number from the list above) " << endl;

        int x;
        cin >> x;

        ufo::folder currFolder = sortedFolders.folders[x-1];
        cout << "*****************************************" << endl;
        cout << "Opening all " << currFolder.name;
        cout << " files: " << endl;
        cout << "*****************************************" << endl;

        int counter = 0;
        for(auto i : currFolder.files){
            counter ++;
            cout << "[" << counter << "]" << i.name << endl;
        }

        cout << "*****************************************" << endl;
        cout << "Which file path were you looking for? (Enter a number from the list above) " << endl;

        int fileNumber;
        cin >> fileNumber;

        cout << "*****************************************" << endl;
        cout << "Here you go: " << endl;
        cout << currFolder.files[fileNumber-1].path << endl;
        cout << "*****************************************\n" << endl;

        cout << "*****************************************" << endl;
        cout << "*****************************************" << endl;
    }

    return 0;
}