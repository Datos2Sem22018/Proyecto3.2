#include "filemanagement.h"

float FileManagement::GetFileSize(const std::string &filename) {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

void FileManagement::writeFile(std::string file, std::string text) {
    // open a file in write mode.
    std::ofstream outfile;
    outfile.open(file);

    // write inputted data into the file.
    outfile << text << std::endl;
    // close the opened file.
    outfile.close();

    // open a file in read mode.
    std::ifstream infile;
    infile.open(file);

    std::cout << "Reading from the file" << std::endl;
    std::string file_contents;
    std::string str;
    while (getline(infile, str)) {
        file_contents += str;
        file_contents.push_back('\n');
    }
    std::cout << file_contents << std::endl;
    infile.close();

}

void FileManagement::copy_file(std::string pathSrc, std::string pathDest) {
    std::ifstream source(pathSrc, std::ios::binary);
    std::ofstream dest(pathDest, std::ios::binary);
    std::istreambuf_iterator<char> begin_source(source);
    std::istreambuf_iterator<char> end_source;
    std::ostreambuf_iterator<char> begin_dest(dest);
    copy(begin_source, end_source, begin_dest);
    source.close();
    dest.close();
    std::cout << "Archivo copiado exitosamente" << std::endl;
}

std::unique_ptr<std::ofstream> FileManagement::createChunkFile(std::vector<std::string> &vecFilenames) {
    std::stringstream filename;
    filename << "chunk" << (vecFilenames.size() + 1) << ".bin";
    vecFilenames.push_back(filename.str());
    return make_unique<std::ofstream>(filename.str(), std::ios::binary);
}

void FileManagement::split(const std::string& text, std::istream &inStream, int nMegaBytesPerChunk, std::vector<std::string> &vecFilenames) {
    std::unique_ptr<char[]> buffer(new char[(int)GetFileSize(text)]);
    int nCurrentMegaBytes = 0;
    std::unique_ptr<std::ostream> pOutStream = createChunkFile(vecFilenames);
    while (!inStream.eof()) {
        inStream.read(buffer.get(), (int)GetFileSize(text));
        pOutStream->write(buffer.get(), inStream.gcount());
        ++nCurrentMegaBytes;
        if (nCurrentMegaBytes >= nMegaBytesPerChunk) {
            pOutStream = createChunkFile(vecFilenames);
            nCurrentMegaBytes = 0;
        }
    }
}

void FileManagement::join(std::vector<std::string>& vecFilenames, std::ostream &outStream) {
    for (int n = 0; n < vecFilenames.size(); ++n) {
        std::ifstream ifs(vecFilenames[n], std::ios::binary);
        outStream << ifs.rdbuf();
    }
}
