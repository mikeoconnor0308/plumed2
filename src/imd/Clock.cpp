#include "Clock.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Clock::Clock()
{
    frequency = CLOCKS_PER_SEC;
}

///<summary> 
///Starts this instance. 
///</summary>
void Clock::Start()
{
    lastUpdate = clock();
    isRunning = true;
}

///<summary>
/// Updates the clock.
///</summary>
///<returns> The time, in seconds, that elapsed since the previous call. </returns>
float Clock::Update()
{
    float result = 0.0f; 
    if(isRunning)
    {
        clock_t last = lastUpdate;
        lastUpdate = clock();
        result = (float)(lastUpdate - last) / frequency;
    }
    return result;
}

///<summary>
///Spins until the specified time is reached. 
///</summary>
void Clock::SpinTill(float value)
{
    float accumulator = 0;
    if (isRunning == false)
    {
        return;
    }

    clock_t count = lastUpdate;
    while (accumulator < value)
    {
        clock_t last = count;
        count = clock();
        accumulator += (float)(count - last) / frequency;
    }    
}
