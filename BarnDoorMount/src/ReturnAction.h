#include "buttoncallback.h"
#include "debug.h"
#include <jled.h>

class ReturnAction : public virtual ButtonCallback
{
private:
    JLed *_led = nullptr;
    void Callback() override;
public:
    ReturnAction(JLed *led);
};
