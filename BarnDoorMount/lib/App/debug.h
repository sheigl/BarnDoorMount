#ifndef ARD
#define ARD
#include <Arduino.h>
#endif

#ifndef DEBUG
    #define DEBUG Serial.println
#endif

#ifdef DEBUG
    #define DEBUG_MSG(msg) { DEBUG(msg); }
#else
    #define DEBUG_MSG(msg)
#endif