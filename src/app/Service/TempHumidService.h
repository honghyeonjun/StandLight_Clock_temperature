#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#include "DHT_Data.h"
#include "TempHumidView.h"
#include "View.h"
#pragma once

class TempHumidService
{
   public:
    // TempHumidService(TempHumidView *tempHumidView, View *view);
    TempHumidService(TempHumidView *tempHumidView);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);


private:
    TempHumidView *tempHumidView;
    View *view;

};

#endif