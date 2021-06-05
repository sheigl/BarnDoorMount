#include "Motor.h"

Motor::Motor(uint8_t enablePin, uint8_t directionPin, uint8_t stepPin) 
{
    _enablePin = enablePin;
    _directionPin = directionPin;
    _stepPin = stepPin;
}

Motor& Motor::Init() 
{
    Disable();
    SetForward();

    return static_cast<Motor&>(*this);
}

Motor& Motor::Update() 
{
    if (_enabled) 
    {
        _rpm++;
    }
    else 
    {
        _rpm = 0;
    }

    setRpm();

    return static_cast<Motor&>(*this);
}

Motor& Motor::Enable() 
{
    digitalWrite(_enablePin, HIGH);
    _enabled = true;

    return static_cast<Motor&>(*this);
}

Motor& Motor::Disable() 
{
    digitalWrite(_enablePin, LOW);
    _enabled = false;

    return static_cast<Motor&>(*this);
}

/*
* Leaving hard coded for now, as STEP_PIN is PIN 8, which maps to PORTB4. Probably need either some abstract methods or callbacks etc.
*/
Motor& Motor::Step() 
{
    if (_enabled)
    {
        // Set STEP_PIN to HIGH, by setting port register and shifting bits
        SET(PORTB, 4);
        
        delayMicroseconds(2);

        // Set STEP_PIN to LOW, by clearing port register
        CLR(PORTB, 4);
    }

    return static_cast<Motor&>(*this);
}

Motor& Motor::MoveForward() 
{
    Enable();
    SetForward();
    setRpm();

    return static_cast<Motor&>(*this);
}

Motor& Motor::MoveReverse() 
{
    Enable();
    SetReverse();

    _rpm = 50;
    setRpm();

    return static_cast<Motor&>(*this);
}

Motor& Motor::Stop() 
{
    Disable();
    _rpm = 0;
    return static_cast<Motor&>(*this);
}

Motor& Motor::SetForward() 
{
    digitalWrite(_directionPin, LOW);
    return static_cast<Motor&>(*this);
}

Motor& Motor::SetReverse() 
{
    digitalWrite(_directionPin, HIGH);
    return static_cast<Motor&>(*this);
}

/*
* Set how often the PWM timer ticks, or the RPM of the motor
* ICR1 = Register that contains Timer1 PWM frequency ticks
* TCNT1 = 16 bit Register that is incremented or decremented by the counter; timer
*/
Motor& Motor::setRpm()
{
    float temp;
    if (_rpm == 0)
    {
        // If RPM is 0, set PWM frequency/top value and disable motor
        ICR1 = ZeroSpeed;
        Enable();
    }
    else
    {
        // If RPM is not 0, enable the motor
        Disable();

        // Don't let _rpm go above MaxRpm
        if (_rpm > MaxRpm)
            _rpm = MaxRpm;

        temp = (_rpm / 60.0) * StepsPerRevolution;
        temp = 2000000 / temp; //  2000000 = (16000000/8) timer1 16Mhz with 1/8 preescaler
        
        if (_period < 600000)
            _period = 60000;

        _period = temp;

        // While the counter is less than 30, wait until a pulse to motor has finished
        while (TCNT1 < 30);
        
        // Set PWM timer tick to _period
        ICR1 = _period;

        // Reset the timer when the counter is greater than the interrupt timer tick
        if (TCNT1 > ICR1)
            TCNT1 = 0;        
    }

    return static_cast<Motor&>(*this);
}

Motor& Motor::setFastPWM() 
{
    // https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM#using-the-atmega-pwm-registers-directly

    // PWM SETUP

    // Fast PWM mode => TOP:ICR1
    TCCR1A =(1<<WGM11);
    
    // Set prescaler 1:8, Fast PWM
    TCCR1B = (1<<WGM13)|(1<<WGM12)|(1<<CS11); 
    
    // Set PWM frequency/top value
    ICR1 = ZeroSpeed;

    // Enable Timer interrupt
    TIMSK1 = (1<<OCIE1A); 

    return static_cast<Motor&>(*this);
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
