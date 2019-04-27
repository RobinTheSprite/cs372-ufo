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

    std::string Component::getName() const
    {
        return _name;
    }

    int File::getSize() const
    {
        return _size;
    }

    File& File::operator=(const File &rhs)
    {
        this->size = rhs.size;
        this->name = rhs.name;
        this->path = rhs.path;
        this->dateModified = rhs.dateModified;
        this->dateCreated = rhs.dateCreated;

        return *this;
    }

    int Folder::getSize() const
    {
        int total = 0;
        for(const auto &c :_children)
            total += c->getSize();
        return total;
    }

    void Folder::add(std::unique_ptr<Component> child)
    {
        _children.push_back(move(child));
    }

    void Folder::remove(const string& name)
    {
        for(auto i = _children.begin(); i != _children.end(); ++i)
        {
            if ((*i)->getName() == name){
                _children.erase(i);
                return;
            }
        }
    }

    const Folder::ChildContainer &Folder::getChildren() const
    {
        return _children;
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