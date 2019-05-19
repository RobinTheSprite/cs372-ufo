
// ufo.cpp
// Source file for Ufo class.

#include "ufo.h"
#include "folder.h"

void BoxPrint(int num, const string& message){
    int c = num - 1;
    int x = message.size();

    for(int i = 0; i <= c; i++){
        for(int j = 0; j <= 2*c + x + 2; j ++)
            cout << "*";
        cout << "*" << endl;
    }

    for(int a = 0; a <= 2; a++){

        if(a == 1){
            for(int i = 0; i <= c; i++)
                cout << "*";
            cout << " ";
            cout << message << " ";
            for(int i = 0; i < c; i++)
                cout << "*";
        }

        if(a == 0 || a == 2) {
            for(int i = 0; i <= c; i++)
                cout << "*";
            for(int i = 0; i < x + 2; i++)
                cout << " ";
            for(int i = 0; i < c; i++)
                cout << "*";
        }
        cout << "*" << endl;
    }

    for(int i = 0; i <= c; i++){
        for(int j = 0; j <= 2*c + x + 2; j ++)
            cout << "*";
        cout << "*" << endl;
    }
}

namespace ufo
{
    void Ufo::pointFolderAtSelf()
    {
        _folder->parentFolder = _folder;
        _currentFolder = _folder->parentFolder;
    }

    Ufo::Ufo()
    {
        setRoot(".");
        pointFolderAtSelf();
    }

    Ufo::Ufo(const string &rootPath)
    {
        setRoot(rootPath);
        pointFolderAtSelf();
    }

    folder Ufo::getCurrentFolder() const
    {
        return *_currentFolder;
    }

    void Ufo::moveCurrFolderUp()
    {
        _currentFolder = _currentFolder->parentFolder;
    }

    void Ufo::moveCurrFolderDown(const string& folderName)
    {
        auto childFolder = _folder->findFolder(folderName);

        if (childFolder)
        {
            _currentFolder = childFolder;
        }
    }

    string getFileExtension(const string& filename)
    {
         size_t extensionPosition = filename.rfind('.');
         if (extensionPosition != string::npos)
         {
             return filename.substr(extensionPosition, string::npos);
         }
         else
         {
             return " none";
         }
    }

    void Ufo::sortFolder(const string& sortType)
    {
        auto retrievedFiles = this->retrieveFileData();
        if (sortType == "extension")
        {
            for (const auto& f : retrievedFiles)
            {
                string extension = getFileExtension(f.name);

                auto correctFolder = _folder->findFolder(extension);

                //Is there a folder for that file extension already?
                if (correctFolder)
                {
                    correctFolder->push_file(f);
                }
                else
                {
                    folder newFolder;
                    newFolder.name = extension;
                    newFolder.push_file(f);

                    _folder->push_folder(newFolder);
                }
            }
        }
        else if (sortType == "name")
        {
            for (const auto& f : retrievedFiles)
            {
                auto correctFolder = _folder->findFolder(f.name.substr(1));

                //Is there a folder for that file extension already?
                if (correctFolder)
                {
                    correctFolder->push_file(f);
                }
                else
                {
                    folder newFolder;
                    newFolder.name = f.name.front();
                    newFolder.push_file(f);
                    _folder->push_folder(newFolder);
                }
            }
        }
        else
        {
            cout << "Error: Not a valid organization method" << endl;
        }
    }

    bool Ufo::isEmpty()
    {
        return _folder->empty();
    }
}