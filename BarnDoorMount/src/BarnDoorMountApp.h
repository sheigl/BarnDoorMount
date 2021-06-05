#include "app.h"
#include "StartAction.h"
#include "ReturnAction.h"
#include "button.h"
#include <jled.h>

#define EN_PIN 9 //enable (CFG6)
#define DIR_PIN 7 //direction
#define STEP_PIN 8 //step
#define LED_PIN 3
#define BTN_PIN 10

class BarnDoorMountApp : public App
{
    private:
        Button *_button = nullptr;
        JLed *_led = nullptr;

        StartAction *_start = nullptr;
        ReturnAction *_return = nullptr;
    public:
        BarnDoorMountApp() = default;
        void setup() override;
        void loop() override;
};