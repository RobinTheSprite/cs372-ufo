// folder.cpp
// Created by Mark on 5/18/2019.
//

#include "folder.h"

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
    bool folder::empty()
    {
        return folders.empty() && files.empty();
    }

    shared_ptr<folder> folder::findFolder(const string& folderName)
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

    void folder::push_file(const file &f)
    {
        files.push_back(f);
    }

    void folder::push_folder(folder &f)
    {
        f.parentFolder = shared_from_this();
        folders.insert({f.name, std::make_shared<folder>(f)});
    }
}

