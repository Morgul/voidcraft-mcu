//----------------------------------------------------------------------------------------------------------------------
// VoidCraft Arduino Control
//----------------------------------------------------------------------------------------------------------------------

#include <Arduino.h>

#include "config.h"
#include "controllers/display/display.h"
#include "controllers/heater/heater.h"
#include "controllers/tempsensor/tempSensor.h"

//----------------------------------------------------------------------------------------------------------------------
// Controllers
//----------------------------------------------------------------------------------------------------------------------

TempSensor tempSensor = TempSensor();
DisplayController display = DisplayController(&tempSensor);
HeaterController heater = HeaterController(&tempSensor);

//----------------------------------------------------------------------------------------------------------------------

void setup()
{
    Serial.begin(BAUDRATE);

    // Set up Controllers
    tempSensor.setup();
    display.setup();
    heater.setup();

    heater.setPoint = 50;
    heater.enable();

    // Wait for MAX6675 chip to stabilize
    delay(500);
}

void loop()
{
    tempSensor.tick();
    display.tick();
    heater.tick();
}

//----------------------------------------------------------------------------------------------------------------------
