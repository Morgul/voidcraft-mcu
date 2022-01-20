//----------------------------------------------------------------------------------------------------------------------
// HeaterController
//----------------------------------------------------------------------------------------------------------------------

#ifndef VOIDCRAFT_MCU_HEATER_H
#define VOIDCRAFT_MCU_HEATER_H

#include "../tempsensor/tempSensor.h"
#include "../baseController.h"

#include "config.h"

// ---------------------------------------------------------------------------------------------------------------------

enum HeaterStatus {
    Approaching,
    Maintaining,
    Cooling
};

// ---------------------------------------------------------------------------------------------------------------------

class HeaterController : public BaseController
{
private:
    bool enabled = false;
    int heaterOnCycleCount = 0;
    TempSensor* tempSensor;
    HeaterStatus status = HeaterStatus::Cooling;

    void heaterOn();
    void heaterOff();
    void determineHeaterStatus();

protected:
    void loop() override;

public:
    double setPoint = 0.0;

    explicit HeaterController(TempSensor* tempSensor);

    void setup() override;

    void enable();
    void disable();
};

#endif //VOIDCRAFT_MCU_HEATER_H

//----------------------------------------------------------------------------------------------------------------------
