// ---------------------------------------------------------------------------------------------------------------------
// TempSensor Controller Header
// ---------------------------------------------------------------------------------------------------------------------

#ifndef VOIDCRAFT_MCU_TEMPSENSOR_H
#define VOIDCRAFT_MCU_TEMPSENSOR_H

#include "max6675.h"

#include "../baseController.h"

// ---------------------------------------------------------------------------------------------------------------------

class TempSensor : public BaseController
{
private:
    // Pins
    int8_t pinDO = 4;
    int8_t pinCS = 5;
    int8_t pinCLK = 6;

    // Sensor
    double offset;
    MAX6675 sensor;

protected:
    void loop() override;

public:
    double currentTemp = 0;

    explicit TempSensor(double offset = 0.0);

    void setup() override;
};

#endif //VOIDCRAFT_MCU_TEMPSENSOR_H

// ---------------------------------------------------------------------------------------------------------------------
