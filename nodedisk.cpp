#include "nodedisk.h"

NodeDisk::NodeDisk(int disk_Spaces, float disk_Space, float block_Space, std::string Path) {
    this->block_Space = block_Space;
    this->disk_Space = disk_Space;
    this->disk_Spaces = disk_Spaces;
    this->Path = Path;
}
