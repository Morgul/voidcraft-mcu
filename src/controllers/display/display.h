//----------------------------------------------------------------------------------------------------------------------
// Display Controller
//----------------------------------------------------------------------------------------------------------------------

#ifndef VOIDCRAFT_MCU_DISPLAY_H
#define VOIDCRAFT_MCU_DISPLAY_H

#include "../tempsensor/tempSensor.h"
#include "../baseController.h"

// ---------------------------------------------------------------------------------------------------------------------

class DisplayController : public BaseController
{
private:
    TempSensor* tempSensor;

protected:
    void loop() override;

public:
    explicit DisplayController(TempSensor* tempSensor);
};

#endif //VOIDCRAFT_MCU_DISPLAY_H

//----------------------------------------------------------------------------------------------------------------------
