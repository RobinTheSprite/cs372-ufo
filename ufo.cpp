// ufo.cpp
// Source file for Ufo class.

#include "ufo.h"

Ufo::Ufo(string rootPath) : _rootPath{std::move(rootPath)}{
    _folder.path = _rootPath;
}
