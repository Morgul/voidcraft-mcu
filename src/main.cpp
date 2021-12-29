//----------------------------------------------------------------------------------------------------------------------
// VoidCraft Arduino Control
//----------------------------------------------------------------------------------------------------------------------

#include <Arduino.h>
#include "controllers/tempsensor/tempSensor.h"
#include "controllers/display/display.h"

//----------------------------------------------------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------------------------------------------------

int8_t heatRelayPin = 45;

// Configuration
double tempOffset = 0.0;

//----------------------------------------------------------------------------------------------------------------------
// Controllers
//----------------------------------------------------------------------------------------------------------------------

TempSensor ovenTemp = TempSensor(tempOffset);
DisplayController display = DisplayController(&ovenTemp);

//----------------------------------------------------------------------------------------------------------------------

void setup()
{
    Serial.begin(9600);

    // Set up pins
    pinMode(heatRelayPin, OUTPUT);

    // Hard code the heater relay to be on.
    digitalWrite(heatRelayPin, 1);

    // Wait for MAX6675 chip to stabilize
    delay(500);
}

void loop()
{
    ovenTemp.tick();
    display.tick();
}

//----------------------------------------------------------------------------------------------------------------------
