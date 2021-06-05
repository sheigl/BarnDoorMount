#include "BarnDoorMountApp.h"

void BarnDoorMountApp::setup()
{
    Serial.begin(9600);
    _button = new Button(BTN_PIN);
    _led = new JLed(LED_PIN);

    _motor = new Motor(EN_PIN, DIR_PIN, STEP_PIN);
    _motor->Init();    

    _start = new StartAction(_led, _motor);
    _button->OnPress(_start);

    _return = new ReturnAction(_led, _motor);
    _button->OnLongPress(_return);   
}

void BarnDoorMountApp::loop()
{
    _led->Update();
    _motor->Update();
    _button->Update();
}

void BarnDoorMountApp::onTimer1Interrupt()
{
    _motor->Step();
}




