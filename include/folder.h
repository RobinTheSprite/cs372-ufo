// folder.h
// Created by Mark on 5/18/2019.
//

#ifndef CS372_UFO_FOLDER_H
#define CS372_UFO_FOLDER_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "file.h"
using ufo::file;
using std::string;
using std::map;
using std::shared_ptr;
using std::vector;

namespace ufo
{
    struct folder : public std::enable_shared_from_this<folder>
    {
        string name;
        map<string, std::shared_ptr<folder>> folders;
        vector<file> files;
        std::shared_ptr<folder> parentFolder;

        bool empty();

        shared_ptr<folder> findFolder(const string& folderName);

        void push_file(const file &f);

        void push_folder(folder &f);
    };
}

#endif //CS372_UFO_FOLDER_H
