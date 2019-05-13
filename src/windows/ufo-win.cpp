// ufo-win.cpp
// Created by Mark on 5/12/2019.
//

#include <windows.h>

#include "ufo.h"

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

namespace ufo
{
    Ufo::Ufo() : _rootPath{"."}
    {
        if (!SetCurrentDirectory(_rootPath.data()))
        {
            printError();
        }
    }

    Ufo::Ufo(string rootPath) : _rootPath{std::move(rootPath)}
    {
        _folder.path = _rootPath;
        if (!SetCurrentDirectory(_rootPath.data()))
        {
            printError();
        }
    }
}

