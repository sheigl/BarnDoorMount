#ifndef BTN
#define BTN

#ifndef ARD
#define ARD
#include <Arduino.h>
#endif

#include "buttoncallback.h"

#define BTN_PRESSED 0
#define BTN_NOT_PRESSED 1
#define DEBOUNCE 100

class Button
{
private:
    unsigned long _lastPressTime;
    int _lastState = BTN_NOT_PRESSED;
    int _currentState = BTN_NOT_PRESSED;
    bool _didShortPress;
    bool _didLongPress;
    bool _didDoublePress;
    uint8_t _pin;
    ButtonCallback *_onPressCallback = nullptr;
    ButtonCallback *_onDoublePressCallback = nullptr;
    ButtonCallback *_onLongPressCallback = nullptr;

    bool isPressed();
public:    
    Button(uint8_t pin);
    void OnPress(ButtonCallback *callback);
    void OnDoublePress(ButtonCallback *callback);
    void OnLongPress(ButtonCallback *callback);
    void Update();
};

#endif