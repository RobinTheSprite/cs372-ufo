// folder.h
// Created by Mark on 5/18/2019.
//

#ifndef CS372_UFO_FOLDER_H
#define CS372_UFO_FOLDER_H

#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "file.h"

struct folder : public std::enable_shared_from_this<folder>
{
    string name;
    map<string, std::shared_ptr<folder>> folders;
    vector<file> files;
    std::shared_ptr<folder> parentFolder;

    bool empty()
    {
        return folders.empty() && files.empty();
    }

    shared_ptr<folder> findFolder(const string& folderName)
    {
        auto maybeFolder = folders.find(folderName);
        if(maybeFolder != folders.end())
        {
            return maybeFolder->second;
        }
        else
        {
            return nullptr;
        }
    }

    void push_file(const file &f)
    {
        files.push_back(f);
    }

    void push_folder(folder &f)
    {
        f.parentFolder = shared_from_this();
        folders.insert({f.name, std::make_shared<folder>(f)});
    }
};
#endif //CS372_UFO_FOLDER_H
