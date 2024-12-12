
#ifndef LDELTATIME_H
#define LDELTATIME_H

#include "Timer.h"

class DeltaTime {
public:
    //Initializes variables
    DeltaTime();

    //Initializes variables with existing offset
    DeltaTime(float milliseconds);

    //Update delta time
    void update();

    //Get delta time
    float getDeltaTime() const;

private:
    Timer mTimer;
    float mDeltaTime;
    float mLastTime;
    float mCurrentTime;
};



#endif //LDELTATIME_H
