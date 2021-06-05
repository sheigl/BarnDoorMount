#include "ReturnAction.h"

ReturnAction::ReturnAction(JLed *led) {
    _led = led;
}

void ReturnAction::Callback()
{
    _led->Breathe(2000)
        .Repeat(1)
        .MaxBrightness(10);

    DEBUG_MSG("LongPress");
}