#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <sys/stat.h>

class FileManagement {
public:
    void writeFile(std::string file, std::string text);
    void copy_file(std::string pathSrc, std::string pathDest);
    std::unique_ptr<std::ofstream> createChunkFile(std::vector<std::string>& vecFilenames);
    void split(const std::string& text, std::istream& inStream, int nMegaBytesPerChunk, std::vector<std::string>& vecFilenames);
    void join(std::vector<std::string>& vecFilenames, std::ostream& outStream);
    float GetFileSize(const std::string& filename);
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
};
#endif // FILEMANAGER_H
