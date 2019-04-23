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
        vector<folder> folders;
        vector<file> files;
        string path;
    };

    class Ufo{
    public:
        explicit Ufo(string rootPath);

        folder getfolder() const{
            return _folder;
        }

        void sortFolder(const string& sortType);

        vector<ufo::file> retrieve();


    private:
        string _rootPath; //here root means the current root node, as in the folder we are opening, not the whole system's root directory
        folder _folder;
    };

}
#endif //CS372_UFO_UFO_H
