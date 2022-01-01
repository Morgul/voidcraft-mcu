//----------------------------------------------------------------------------------------------------------------------
// HeaterController
//----------------------------------------------------------------------------------------------------------------------

#include "heater.h"

//----------------------------------------------------------------------------------------------------------------------

HeaterController::HeaterController(TempSensor* tempSensor)
{
    this->loopInterval = 10;
    this->tempSensor = tempSensor;
}

void HeaterController::setup()
{
    // Set up pins
    pinMode(HEATER_RELAY_PIN, OUTPUT);

    // Hard code the HeaterController relay to be on.
    digitalWrite(HEATER_RELAY_PIN, 1);
}

void HeaterController::loop()
{
    // TODO: write control code...
}

//----------------------------------------------------------------------------------------------------------------------
