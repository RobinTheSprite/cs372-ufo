// ufo.cpp
// Source file for Ufo class.

#include "ufo.h"

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
                //TODO place the file f into the correct file extension folder.
            }
        }
    }

    std::string Component::getName() const
    {
        return _name;
    }

    int File::getSize() const
    {
        return _size;
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


}