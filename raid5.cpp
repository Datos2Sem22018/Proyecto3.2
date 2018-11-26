#include "raid5.h"

Raid5::Raid5() {
    this->d1 = new NodeDisk(6400, 1600, 400, "/home/zuckerberg/Escritorio/Disk 1");
    this->d2 = new NodeDisk(6400, 1600, 400, "/home/zuckerberg/Escritorio/Disk 2");
    this->d3 = new NodeDisk(6400, 1600, 400, "/home/zuckerberg/Escritorio/Disk 3");
    this->d4 = new NodeDisk(6400, 1600, 400, "/home/zuckerberg/Escritorio/Disk 4");
}
