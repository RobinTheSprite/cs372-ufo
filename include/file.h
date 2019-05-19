// file.h
// Created by Mark on 5/18/2019.
//

#ifndef CS372_UFO_FILE_H
#define CS372_UFO_FILE_H

struct file
{
    string name;
    string path;
    unsigned long size;
    vector<int> dateCreated;
    vector<int> dateModified;
};

#endif //CS372_UFO_FILE_H
