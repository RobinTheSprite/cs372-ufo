// retriever-win.cpp
// Created by Mark on 4/9/2019.
//

#include <Windows.h>
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include "retriever-win.h"
#include "file-folder.h"

namespace ufo
{

//printError
//Tell me what the last error in this thread was
    void printError()
    {
        LPTSTR errorMessage = nullptr;
        DWORD errorCode = GetLastError();
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER
                      | FORMAT_MESSAGE_FROM_SYSTEM
                      | FORMAT_MESSAGE_IGNORE_INSERTS,
                      nullptr,
                      errorCode,
                      0,
                      (LPTSTR) &errorMessage,
                      0,
                      nullptr);
        std::cout << "Error: " << errorMessage << std::endl;
    }

vector<WIN32_FIND_DATA> retrieveWin()
{
    //Get the current directory
    char currentDirectory[MAX_PATH];
    if (GetCurrentDirectory(MAX_PATH, currentDirectory) == 0)
    {
        printError();
    }

        //Get a handle to the first file in the current directory
        WIN32_FIND_DATA foundData;
        HANDLE fileHandle = FindFirstFile("*", &foundData);
        if (fileHandle == INVALID_HANDLE_VALUE)
        {
            printError();
        }

        vector<ufo::file> fileMetadata;
        do
        {
            if (foundData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
            {
                ufo::file file = createFile(foundData);
                fileMetadata.push_back(file);
            }

            FindNextFile(fileHandle, &foundData);
        } while (GetLastError() != ERROR_NO_MORE_FILES);

        return fileMetadata;
    }

}