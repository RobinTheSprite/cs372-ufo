// ufo.cpp
// Source file for Ufo class.

#include "ufo.h"
#include <algorithm>

namespace ufo
{
    Ufo::Ufo() : _rootPath{"."}
    {}

    Ufo::Ufo(string rootPath) : _rootPath{std::move(rootPath)}
    {
        _folder.path = _rootPath;
    }

    string getFileExtension(const string& filename)
    {
        return filename.substr(filename.rfind('.'), string::npos);
    }

    void Ufo::sortFolder(const string& sortType)
    {
        auto retrievedFiles = this->retrieve();
        if (sortType == "extension")
        {
            for (const auto& f : retrievedFiles)
            {
                string extension = getFileExtension(f.name);

                auto correctFolder = std::find_if(_folder.folders.begin(), _folder.folders.end(),
                                                  [extension](auto a){return a.name == extension;});

                //Is there a folder for that file extension already?
                if (correctFolder != _folder.folders.end())
                {
                    correctFolder->push_file(f);
                }
                else
                {
                    folder newFolder;
                    newFolder.name = extension;
                    newFolder.push_file(f);

                    _folder.push_folder(newFolder);
                }
            }
        }
    }

    bool Ufo::empty()
    {
        return _folder.empty();
    }
}