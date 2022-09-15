#include "TempHumidService.h"

TempHumidService::TempHumidService(TempHumidView *tempHumidView)//, View *view
{
    this->tempHumidView = tempHumidView;
    //this->view = view;
}   

TempHumidService::~TempHumidService()
{

}

void TempHumidService::updateEvent(DHT_Data dhtData)
{
    float temp, humid;
    
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RHDec/10.0);

    tempHumidView->setTempHumidData(temp, humid);
    //view -> Warning(temp);
   

}