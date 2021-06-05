#include "BarnDoorMountApp.h"

void BarnDoorMountApp::setup()
{
    Serial.begin(9600);
    _button = new Button(BTN_PIN);
    _led = new JLed(LED_PIN);

    _start = new StartAction(_led);
    _button->OnPress(_start);

    _return = new ReturnAction(_led);
    _button->OnLongPress(_return);

    //set pin modes
    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
    pinMode(DIR_PIN, OUTPUT);
    
    digitalWrite(DIR_PIN, HIGH); //LOW or HIGH
    pinMode(STEP_PIN, OUTPUT);
    digitalWrite(STEP_PIN, LOW);

    digitalWrite(EN_PIN, LOW); //activate driver
    //LED BUILT_IN is GPIO 33
    //pinMode(33, OUTPUT); // Set the pin as output

    //Serial.begin(9600);
    //Serial.println("Booting");

    // led
}

void BarnDoorMountApp::loop()
{
    _led->Update();

    /* if (digitalRead(BTN_PIN) == 0) {
        digitalWrite(LED_PIN, HIGH);
    }
    else {
        digitalWrite(LED_PIN, LOW);
    } */

    //make steps
    //Serial.println("High");
    digitalWrite(STEP_PIN, HIGH);
    delay(2);
    //Serial.println("Low");
    digitalWrite(STEP_PIN, LOW);
    delay(2);

    /*
    digitalWrite(33, LOW); //Turn on
    delay (1000); //Wait 1 sec
    digitalWrite(33, HIGH); //Turn off
    delay (1000); //Wait 1 sec
    */

    //int result = digitalRead(10);
    //Serial.print(result);

    //DEBUG_MSG("Test");

    _button->Update();
}