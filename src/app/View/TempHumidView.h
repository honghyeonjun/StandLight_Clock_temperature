#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#include "LCD.h"

#pragma once

class TempHumidView
{
public:
    TempHumidView(LCD *lcd);
    virtual ~TempHumidView();
    void setTempHumidData(float temp, float humid);
private:

    LCD *lcd;

};

#endif