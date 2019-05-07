// openFile-win.cpp
// Created by Mark on 4/28/2019.
//

#include <Windows.h>
#include <iostream>
#include "ufo.h"

namespace ufo
{
    void Ufo::openFile(const file& file)
    {
       auto retval = ShellExecute(nullptr, "open", file.name.data(), nullptr, nullptr, SW_SHOWNORMAL);
       if ((size_t)retval <= 32)
       {
           std::cout << "Error opening file" << std::endl;
       }
    }
}
