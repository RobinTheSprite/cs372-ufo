// ufo-win.cpp
// Created by Mark on 5/12/2019.
//

#include <windows.h>

#include "ufo.h"

namespace ufo
{
    Ufo::Ufo() : _rootPath{"."}
    {

    }

    Ufo::Ufo(string rootPath) : _rootPath{std::move(rootPath)}
    {
        _folder.path = _rootPath;
    }
}

