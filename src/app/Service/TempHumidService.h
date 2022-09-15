#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#include "DHT_Data.h"
#include "TempHumidView.h"

#pragma once

class TempHumidService
{
   public:
    TempHumidService(TempHumidView *tempHumidView);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);


private:
    TempHumidView *tempHumidView;

};

#endif