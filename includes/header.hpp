#ifndef CPP_SKELETON_HEADER_H
#define CPP_SKELETON_HEADER_H

#include <string>


void sm2(unsigned int &n, unsigned int grade, unsigned int &interval, float &easiness_factor);


class Card {
private:
    std::string ask_;
    std::string res_;
    float easiness_;
    unsigned int n_;
    unsigned int nbSeen_;
    unsigned int lastSeen_;
    unsigned int usrGrade_;
    unsigned int interval_;
public:
    Card(std::string ask, std::string res);

    void update();
};


#endif //CPP_SKELETON_HEADER_H
