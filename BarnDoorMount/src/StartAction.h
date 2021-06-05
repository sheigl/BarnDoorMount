#ifndef __STARTACTION_H__
#define __STARTACTION_H__

#include "buttoncallback.h"
#include "debug.h"
#include "jled.h"
#include "Motor.h"

class StartAction : public virtual ButtonCallback
{
private:
    JLed *_led = nullptr;
    Motor *_motor = nullptr;
    bool _actionRunning = false;
    void Callback() override;
public:
    StartAction(JLed *led, Motor *motor);
};
#endif // __STARTACTION_H__