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

    Motor& setRpm();
    Motor& setFastPWM();
    bool _enabled = false;
    float _rpm;
    uint16_t _period;
    uint8_t _enablePin, 
            _directionPin, 
            _stepPin;

public:
    Motor(uint8_t enablePin, uint8_t directionPin, uint8_t stepPin);
    ~Motor() = default;

    /**
    * Init the motor
    */
    Motor& Init();
    /**
     * Update the motor state
     */
    Motor& Update();
    /**
    * Enable the motor
    */
    Motor& Enable();
    /**
    * Disable the motor
    */
    Motor& Disable();
    /**
    * Step the motor using port manipulation
    */
   Motor& Step();
    /**
    * Set forward direction
    */
   Motor& SetForward();
   /**
    * Set reverse direction
    */
   Motor& SetReverse();
   /**
    * Set forward direction
    */
   Motor& MoveForward();
   /**
    * Set reverse direction
    */
   Motor& MoveReverse();
   /**
   * Stop the motor
   */
  Motor& Stop();
};

#endif // __MOTOR_H__