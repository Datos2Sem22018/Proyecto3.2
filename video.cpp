#include "video.h"

Video::Video(){
}

std::string Video::getContributor(){
    return contributor;
}

std::string Video::getDate(){
    return date;
}

std::string Video::getDescription(){
    return description;
}

std::string Video::getDuration(){
    return duration;
}

std::string Video::getTitle(){
    return title;
}

void Video::setContributor(std::string nContributor){
    contributor = nContributor;
}

void Video::setDate(std::string nDate){
    date = nDate;
}

void Video::setDescription(std::string nDescription){
    description = nDescription;
}

void Video::setDuration(std::string nDuration){
    duration = nDuration;
}

void Video::setTitle(std::string nTitle){
    title = nTitle;
}
