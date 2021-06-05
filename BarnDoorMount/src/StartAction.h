#include "buttoncallback.h"
#include "debug.h"
#include "jled.h"

class StartAction : public virtual ButtonCallback
{
private:
    JLed *_led = nullptr;
    void Callback() override;
public:
    StartAction(JLed *led);
};