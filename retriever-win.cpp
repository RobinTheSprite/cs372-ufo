// retriever-win.cpp
// Created by Mark on 4/9/2019.
//

#include <Windows.h>
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include "ufo.h"

namespace ufo
{

    //printError
    //Tell me what the last error in this thread was
    void printError()
    {
        LPTSTR errorMessage = nullptr;
        DWORD errorCode = GetLastError();
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER // NOLINT(hicpp-signed-bitwise)
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

    SYSTEMTIME getDate(FILETIME filetime)
    {
        SYSTEMTIME systemtime;
        FileTimeToLocalFileTime(&filetime, &filetime);
        FileTimeToSystemTime(&filetime, &systemtime);
        return systemtime;
    }

    ufo::file createFile(WIN32_FIND_DATA metaData)
    {
        ufo::file file;
        file.name = metaData.cFileName;
        file.size = (metaData.nFileSizeHigh * MAXDWORD) + metaData.nFileSizeLow; //MAXDWORD might need to be
                                                                                 //MAXDWORD + 1
        SYSTEMTIME created = getDate(metaData.ftCreationTime);
        file.dateCreated.push_back(created.wMonth);
        file.dateCreated.push_back(created.wDay);
        file.dateCreated.push_back(created.wYear);

        SYSTEMTIME modified = getDate(metaData.ftLastWriteTime);
        file.dateModified.push_back(modified.wMonth);
        file.dateModified.push_back(modified.wDay);
        file.dateModified.push_back(modified.wYear);

        char pathBuffer[MAX_PATH];
        GetFullPathName(file.name.data(), MAX_PATH, pathBuffer, nullptr);
        file.path = pathBuffer;

        return file;
    }

    vector<ufo::file> retrieve_recurse(string filepath)
    {
        //Get a handle to the first file in the current directory
        WIN32_FIND_DATA foundData;

        if (filepath.empty())
        {
            filepath = ".";
        }

        if (filepath.back() != '/' && filepath.back() != '\\')
        {
            filepath.push_back('/');
        }

        string fileSelector = filepath + "*";
        HANDLE fileHandle = FindFirstFile(fileSelector.data(), &foundData);
        if (fileHandle == INVALID_HANDLE_VALUE)
        {
            printError();
            return {};
        }

        vector<ufo::file> fileMetadata;
        do
        {
            if (foundData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
            {
                ufo::file file = createFile(foundData);
                fileMetadata.push_back(file);
            }
            else if (strcmp(foundData.cFileName, ".") != 0 && strcmp(foundData.cFileName, "..") != 0)
            {
                auto subfolderMetaData = retrieve_recurse(filepath + foundData.cFileName);
                fileMetadata.insert(fileMetadata.end(), subfolderMetaData.begin(), subfolderMetaData.end());
            }

            FindNextFile(fileHandle, &foundData);
        } while (GetLastError() != ERROR_NO_MORE_FILES);

        SetLastError(0);
        return fileMetadata;
    }

    vector<ufo::file> Ufo::retrieve()
    {
        if (!SetCurrentDirectory(_rootPath.data()))
        {
            printError();
            return {};
        }

        return retrieve_recurse(_rootPath);
    }

}