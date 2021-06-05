#include "StartAction.h"

StartAction::StartAction(JLed *led) {
    _led = led;
}

void StartAction::Callback()
{
    _led->Breathe(250)
        .Repeat(3)
        .MaxBrightness(10);

    DEBUG_MSG("StartAction");
}