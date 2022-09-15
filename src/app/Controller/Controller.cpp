#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ)
{
    service = serv;
    clockService = clockServ;
    lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
    
}