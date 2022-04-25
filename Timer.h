#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <chrono>
#include <windows.h>
using namespace std;

const double STEP_DELAY = 1;
#define CLOCK_NOW chrono::system_clock::now
typedef chrono::duration<double> ElapsedTime;

class Timer{
   chrono::time_point<chrono::_V2::system_clock, chrono::duration<long long int, ratio<1, 1000000000> > > startTime;
   chrono::time_point<chrono::_V2::system_clock, chrono::duration<long long int, ratio<1, 1000000000> > > endTime;
public:
   Timer() { startTime =CLOCK_NOW(); }
   double getElapsed(){
      endTime =CLOCK_NOW();
      ElapsedTime elapsed = endTime -startTime;
      return elapsed.count();
   }
   bool isFullCharge() {
      if (getElapsed() >STEP_DELAY) {
         startTime =endTime;
         return true;
      }
      else return false;
   }
};

#endif
