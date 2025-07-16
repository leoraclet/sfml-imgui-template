#include <cmath>

#include "header.hpp"


void sm2(unsigned int &n, unsigned int grade, unsigned int &interval, float &easiness_factor)
{
    // Correct response
    if (grade >= 3)
    {
        if (n == 0)
            interval = 1;
        else if (n == 1)
            interval = 6;
        else
            interval = (int)roundf((float)interval * easiness_factor);
        n++;
    }
    // Incorrect response
    else
    {
        n = 0;
        interval = 1;
    }

    easiness_factor += (float)((0.1 - (5 - grade)) * (0.08 + (5 - grade) * 0.02));
    if (easiness_factor < 1.3)
    {
        easiness_factor = 1.3;
    }
}

Card::Card(std::string ask, std::string res)
{
    ask_ = ask;
    res_ = res;
    easiness_ = 2.5;
    nbSeen_ = 0;
    lastSeen_ = 0;
    usrGrade_ = 0;
    n_ = 0;
    interval_ = 0;
}

void Card::update()
{
    sm2(n_, usrGrade_, interval_, easiness_);
}
