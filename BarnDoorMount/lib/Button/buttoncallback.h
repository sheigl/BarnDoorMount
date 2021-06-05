#ifndef ButtonCallback_H
#define ButtonCallback_H

class ButtonCallback
{
public:
    virtual ~ButtonCallback() = default;
    virtual void Callback() = 0;
};

#endif
