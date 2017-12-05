#ifndef CLOCK_H
#define CLOCK_H
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

class Clock
{
    clock_t frequency;
    bool isRunning;
    clock_t lastUpdate;

    public:

        Clock();

        ///<summary> 
        ///Starts this instance. 
        ///</summary>
        void Start();

        ///<summary>
        /// Updates the clock.
        ///</summary>
        ///<returns> The time, in seconds, that elapsed since the previous call. </returns>
        float Update();

        ///<summary>
        ///Spins until the specified time is reached. 
        ///</summary>
        void SpinTill(float value);

};

#endif