//----------------------------------------------------------------------------------------------------------------------
// Base Controller
//----------------------------------------------------------------------------------------------------------------------

#ifndef VOIDCRAFT_MCU_BASECONTROLLER_H
#define VOIDCRAFT_MCU_BASECONTROLLER_H

#include "Arduino.h"

// ---------------------------------------------------------------------------------------------------------------------

class BaseController
{
private:
    unsigned long lastTS = 0;

protected:
    unsigned int loopInterval = 250;
    virtual void loop() = 0;

public:
    void tick();
};

#endif //VOIDCRAFT_MCU_BASECONTROLLER_H

//----------------------------------------------------------------------------------------------------------------------
