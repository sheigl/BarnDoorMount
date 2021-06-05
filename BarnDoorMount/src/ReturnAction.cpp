#include "ReturnAction.h"

ReturnAction::ReturnAction(JLed *led, Motor *motor) {
    _led = led;
    _motor = motor;
}

void ReturnAction::Callback()
{
    _led->Breathe(2000)
        .Repeat(1)
        .MaxBrightness(10);

    if (!_actionRunning) 
    {
        _motor->MoveReverse();
        _actionRunning = true;
    }
    else 
    {
        _motor->Stop();
        _actionRunning = false;        
    }

    DEBUG_MSG("LongPress");
}