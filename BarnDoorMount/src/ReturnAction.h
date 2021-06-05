#ifndef __RETURNACTION_H__
#define __RETURNACTION_H__

#include "buttoncallback.h"
#include "debug.h"
#include <jled.h>
#include "Motor.h"

class ReturnAction : public virtual ButtonCallback
{
private:
    JLed *_led = nullptr;
    Motor *_motor = nullptr;
    bool _actionRunning = false;
    void Callback() override;
public:
    ReturnAction(JLed *led, Motor *motor);
};

#endif // __RETURNACTION_H__