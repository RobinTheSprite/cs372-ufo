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

    class Component
    {
    public:
        virtual ~Component() = default;
        virtual int getSize() const=0;
        std::string getName() const;
        const string path;
    private:
        const std::string _name;
    };

    class File : public Component
    {
    public:
        int getSize() const override;
        string name;
        string path;
        unsigned long size;
        vector<int> dateCreated;
        vector<int> dateModified;
        File& operator=(const File& rhs);
    private:
        int _size;
    };

    class Folder : public Component
    {
    public:
        using Component::Component;
        using ChildContainer = std::vector<std::unique_ptr<Component>>;
        int getSize() const override;
        void add(std::unique_ptr<Component>);
        void remove(const string& name);
        const ChildContainer & getChildren() const;
    private:
        ChildContainer _children;
    };

    class Ufo{
    public:
        Ufo();
        explicit Ufo(string rootPath);

        folder getfolder() const{
            return _folder;
        }

        void sortFolder(const string& sortType);

        vector<File> retrieve();


    private:
        string _rootPath; //here root means the current root node, as in the folder we are opening, not the whole system's root directory
        folder _folder;
    };

}
#endif //CS372_UFO_UFO_H
