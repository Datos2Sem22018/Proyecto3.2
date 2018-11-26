#ifndef NODEDISK_H
#define NODEDISK_H
#include<iostream>


class NodeDisk
{
public:
NodeDisk(int disk_Spaces, float disk_Space, float block_Space, std::string Path);

private:
    float disk_Space;
    int disk_Spaces;
    float block_Space;
    std::string IP;
    std::string PORT;
    std::string Path;

};

#endif // NODEDISK_H
