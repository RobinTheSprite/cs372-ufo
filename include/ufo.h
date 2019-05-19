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
#include <memory>
using std::shared_ptr;
#include <map>
using std::map;

void BoxPrint(int num, const string& message);

namespace ufo
{
    struct file
    {
        string name;
        string path;
        unsigned long size;
        vector<int> dateCreated;
        vector<int> dateModified;
    };

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

    class Ufo
    {
      public:
        Ufo();

        explicit Ufo(const string &rootPath);

        void setRoot(string);

        folder getfolder() const
        {
            return *_folder;
        }

        folder getCurrentFolder() const;

        void moveCurrFolderUp();

        void moveCurrFolderDown(const string &folderName);

        void sortFolder(const string &sortType);

        vector<file> retrieveFileData();

        void openFile(const file &);

        bool isEmpty();

      private:

        void pointFolderAtSelf();

        string _rootPath;
        std::shared_ptr<folder> _folder = std::make_shared<folder>();
        std::shared_ptr<folder> _currentFolder;
    };

}
#endif //CS372_UFO_UFO_H