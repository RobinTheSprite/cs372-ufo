// file-folder.h
// Created by Mark on 4/11/2019.
//

#ifndef CS372_UFO_FILE_FOLDER_H
#define CS372_UFO_FILE_FOLDER_H

#include <vector>
using std::vector;
#include <string>
using std::string;

namespace ufo
{
    struct file
    {
        string name;
        string path;
        int size;
        vector<int> dateCreated;
        vector<int> dateModified;
    };

    struct folder
    {
        vector<folder> folders;
        vector<file> files;
        string path;
    };
}
#endif //CS372_UFO_FILE_FOLDER_H
