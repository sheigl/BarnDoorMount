#include "Motor.h"

Motor::Motor(uint8_t enablePin, uint8_t directionPin, uint8_t stepPin) 
{
    _enablePin = enablePin;
    _directionPin = directionPin;
    _stepPin = stepPin;
}

void Motor::Update() 
{
    
}

void Motor::Enable() 
{
    _enabled = true;
}

void Motor::Disable() 
{
    _enabled = false;
}

void Motor::setRpm()
{
    float temp;
    if (_rpm == 0)
    {
        // Set PWM frequency/top value
        ICR1 = ZeroSpeed;
        digitalWrite(10, HIGH); // Disable motor
    }
    else
    {
        digitalWrite(10, LOW); // Enable motor
                               /*   if (rpm<8)
      rpm = 8;*/
        if (_rpm > MaxRpm)
            _rpm = MaxRpm;
        temp = (_rpm / 60.0) * StepsPerRevolution;
        temp = 2000000 / temp; //  2000000 = (16000000/8) timer1 16Mhz with 1/8 preescaler
        if (_period < 600000)
            _period = 60000;
        _period = temp;
        while (TCNT1 < 30)
            ; // Wait until a pulse to motor has finished
        //cli();
        ICR1 = _period;    //+ userCommand;
        if (TCNT1 > ICR1) // Handle when we need to reset the timer
            TCNT1 = 0;
        //sei();
    }
}

template <typename T1, typename T2>
void Motor::CLR(T1 x, T2 y)
{
    x &= (~(1 << y));
}

template <typename T1, typename T2>
void Motor::SET(T1 x, T2 y)
{
    x |= (1 << y);
}
