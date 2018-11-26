#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>

class Video
{

private:
    //metadata
    std::string title;
    std::string contributor;
    std::string description;
    std::string date;
    std::string duration;

    std::string path;

public:
    std::string getTitle();
    void setTitle(std::string ntitle);
    std::string getContributor();
    void setContributor(std::string nContributor);
    std::string getDescription();
    void setDescription(std::string nDescription);
    std::string getDate();
    void setDate(std::string nDate);
    std::string getDuration();
    void setDuration(std::string nDuration);

    Video();
};

#endif // VIDEO_H
