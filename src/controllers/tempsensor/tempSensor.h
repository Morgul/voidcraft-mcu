// ---------------------------------------------------------------------------------------------------------------------
// TempSensor Controller Header
// ---------------------------------------------------------------------------------------------------------------------

#ifndef VOIDCRAFT_MCU_TEMPSENSOR_H
#define VOIDCRAFT_MCU_TEMPSENSOR_H

#include "max6675.h"

#include "../baseController.h"

#include "config.h"

// ---------------------------------------------------------------------------------------------------------------------

class TempSensor : public BaseController
{
private:
    double offset;
    MAX6675 sensor;

protected:
    void loop() override;

public:
    double currentTemp = 0;

    explicit TempSensor();

    void setup() override;
};

#endif //VOIDCRAFT_MCU_TEMPSENSOR_H

// ---------------------------------------------------------------------------------------------------------------------
