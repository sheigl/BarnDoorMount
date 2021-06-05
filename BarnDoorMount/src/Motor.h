#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <Arduino.h>
#include "Constants.h"

class Motor
{
private:
    template <typename T1, typename T2>
    void CLR(T1 x, T2 y);
    template <typename T1, typename T2>
    void SET(T1 x, T2 y);

    void setRpm();
    bool _enabled = false;
    float _rpm;
    uint16_t _period;
    uint8_t _enablePin, 
            _directionPin, 
            _stepPin;

public:
    Motor(uint8_t enablePin, uint8_t directionPin, uint8_t stepPin);
    ~Motor() = default;

    void Update();    
    void Enable();
    void Disable();
};

#endif // __MOTOR_H__