//----------------------------------------------------------------------------------------------------------------------
// HeaterController
//----------------------------------------------------------------------------------------------------------------------

#ifndef VOIDCRAFT_MCU_HEATER_H
#define VOIDCRAFT_MCU_HEATER_H

#include "../tempsensor/tempSensor.h"
#include "../baseController.h"

#include "config.h"

// ---------------------------------------------------------------------------------------------------------------------

class HeaterController : public BaseController
{
private:
    TempSensor* tempSensor;

protected:
    void loop() override;

public:
    explicit HeaterController(TempSensor* tempSensor);

    void setup() override;
};

#endif //VOIDCRAFT_MCU_HEATER_H

//----------------------------------------------------------------------------------------------------------------------
