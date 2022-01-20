//----------------------------------------------------------------------------------------------------------------------
// HeaterController
//----------------------------------------------------------------------------------------------------------------------

#include "heater.h"

//----------------------------------------------------------------------------------------------------------------------

HeaterController::HeaterController(TempSensor* tempSensor)
{
    this->loopInterval = 4000;
    this->tempSensor = tempSensor;
}

//----------------------------------------------------------------------------------------------------------------------
// Internal
//----------------------------------------------------------------------------------------------------------------------

void HeaterController::heaterOn()
{
    // Ensure the heater is on
    digitalWrite(HEATER_RELAY_PIN, 1);

    // Increase the cycle count
    this->heaterOnCycleCount += 1;
}

void HeaterController::heaterOff()
{
    // Ensure the heater is off
    digitalWrite(HEATER_RELAY_PIN, 0);
}

void HeaterController::determineHeaterStatus()
{
    if(this->enabled)
    {
        if (this->heaterOnCycleCount >= MIN_HEATER_CYCLE_COUNT)
        {
            this->status = HeaterStatus::Approaching;
        }
        else
        {
            this->status = HeaterStatus::Maintaining;
            this->heaterOnCycleCount = 0;
        }
    }
    else
    {
        this->status = HeaterStatus::Cooling;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Controller API
//----------------------------------------------------------------------------------------------------------------------

void HeaterController::setup()
{
    // Set up pins
    pinMode(HEATER_RELAY_PIN, OUTPUT);
}

void HeaterController::loop()
{
    // Determine our current heater status
    this->determineHeaterStatus();

    // Calculate the delta between the setPoint and the current temperature
    double tempDelta = this->setPoint - this->tempSensor->currentTemp;

    //------------------------------------------------------------------------------------------------------------------
    // Temperature Control
    //------------------------------------------------------------------------------------------------------------------
    //
    // We have three states, Cooling, Maintaining, or Approaching. In each state, we handle controlling the temperature
    // differently. This allows us to keep the logic much simpler and easier to understand than doing something more
    // complicated (even if it would be more accurate.)
    //
    //------------------------------------------------------------------------------------------------------------------

    if(this->enabled)
    {
        // If we're cooling, we turn off the heater. Nothing else to do.
        if(this->status == HeaterStatus::Cooling)
        {
            this->heaterOff();
        }

        // If we're maintaining, we turn on the heater if we're less than or equal to setPoint - 1, or turn the heater
        // off if we're over or equal to setPoint + 1.
        if(this->status == HeaterStatus::Maintaining)
        {
            if(tempDelta >= 1)
            {
                this->heaterOn();
            }
            else if(tempDelta <= -1)
            {
                this->heaterOff();
            }
        }

        // If we're approaching, we only turn on the heater if tempDelta is greater than our temperature epsilon.
        if(this->status == HeaterStatus::Approaching)
        {
            if(tempDelta > TEMP_EPSILON)
            {
                this->heaterOn();
            }
            else
            {
                this->heaterOff();
            }
        }
    }

    //------------------------------------------------------------------------------------------------------------------
    // Temperature Watchdog
    //------------------------------------------------------------------------------------------------------------------
    //
    // This code always executes, even if we're not enabled, because we don't want to get in a state where we've
    // disabled the controller, but the heater was left on. It's a safety thing.
    //
    //------------------------------------------------------------------------------------------------------------------

    if(this->tempSensor->currentTemp >= MAX_TEMP || tempDelta <= -MAX_SETPOINT_DELTA)
    {
        // We disable the heater control
        this->disable();

        // Ensure the heater's off, just to be safe.
        this->heaterOff();

        // TODO: We need to do something more serious, but for now, this is out only output.
        Serial.println("**** ERROR! TEMPERATE OVERSHOOT! ****");
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Public API
//----------------------------------------------------------------------------------------------------------------------

void HeaterController::enable()
{
    this->enabled = true;

    // Reset state
    this->status = HeaterStatus::Maintaining;
    this->heaterOnCycleCount = 0;
}

void HeaterController::disable()
{
    this->enabled = false;

    // Reset state
    this->status = HeaterStatus::Cooling;
    this->heaterOnCycleCount = 0;

    // Let's just make sure the heater's off.
    this->heaterOff();
}

//----------------------------------------------------------------------------------------------------------------------
