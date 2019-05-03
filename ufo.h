#include <utility>

// ufo.h
// Header file for Ufo class

#ifndef CS372_UFO_UFO_H
#define CS372_UFO_UFO_H

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

void BoxPrint(int num, string message);

namespace ufo
{
    struct file {
        string name;
        string path;
        unsigned long size;
        vector<int> dateCreated;
        vector<int> dateModified;
    };

    struct folder {
        string name;
        vector<folder> folders;
        vector<file> files;
        string path;

        bool empty()
        {
            return folders.empty() && files.empty();
        }

        void push_file(const file& f)
        {
            files.push_back(f);
        }

        void push_folder(const folder& f)
        {
            folders.push_back(f);
        }
    };

    class Ufo{
    public:
        Ufo();
        explicit Ufo(string rootPath);

        folder getfolder() const{
            return _folder;
        }

        void sortFolder(const string& sortType);

        vector<file> retrieve();

        void openFile(const file&);

        bool isEmpty();

    private:

        string _rootPath; //here root means the current root node, as in the folder we are opening, not the whole system's root directory
        folder _folder;
    };

}
#endif //CS372_UFO_UFO_H