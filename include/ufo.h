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

#include "file.h"
#include "folder.h"

void BoxPrint(int num, const string& message);

namespace ufo
{
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