#include "StartAction.h"

StartAction::StartAction(JLed *led, Motor *motor) {
    _led = led;
    _motor = motor;
}

void StartAction::Callback()
{
    _led->Breathe(250)
        .Repeat(3)
        .MaxBrightness(10);

    if (!_actionRunning) 
    {
        _motor->MoveForward();
        _actionRunning = true;
    }
    else 
    {
        _motor->Stop();
        _actionRunning = false;        
    }

    DEBUG_MSG("StartAction");
}