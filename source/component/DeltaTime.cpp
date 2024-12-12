//
// Created by đỗ quyên on 12/12/24.
//

#include "DeltaTime.h"
DeltaTime::DeltaTime() {
    mDeltaTime = 0;
    mTimer.start();

    mLastTime = 0;
    mCurrentTime = 0;
}

DeltaTime::DeltaTime (const float milliseconds) {
    mDeltaTime = milliseconds;
    mTimer.start();

    mLastTime = milliseconds;
    mCurrentTime = 0;
}

void DeltaTime::update() {
    mCurrentTime = mTimer.getTicks();
    mDeltaTime = (mCurrentTime - mLastTime) / 1000.f;
    mLastTime = mCurrentTime;
}

float DeltaTime::getDeltaTime() const {
    return mDeltaTime;
}
