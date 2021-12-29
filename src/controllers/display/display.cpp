//----------------------------------------------------------------------------------------------------------------------
// Display Controller
//----------------------------------------------------------------------------------------------------------------------

#include "display.h"

//----------------------------------------------------------------------------------------------------------------------

DisplayController::DisplayController(TempSensor* tempSensor)
{
    this->loopInterval = 1000;
    this->tempSensor = tempSensor;
}

void DisplayController::loop()
{
    // TODO: Eventually, we display this on the LCD.
    Serial.print(this->tempSensor->currentTemp);
    Serial.println("°C");
}

//----------------------------------------------------------------------------------------------------------------------
