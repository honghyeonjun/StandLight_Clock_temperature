#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidView.h"
#include "TempHumidService.h"
#include "DHT_Data.h"
int main()
{
    //std::cout << "Hello World!" << std::endl;

    Button modeButton(27);//mode
    Button powerButton(28);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView tempHumidView(&lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    TempHumidService tempHumidService(&tempHumidView);//,&view
    ClockService clockSerivce(&clockView);
    Controller control(&service, &clockSerivce, &tempHumidService);
    Listener listener(&modeButton,&powerButton, &control, &clockCheck, &dht);
    
    
    // DHT_Data dhtData;

    while (1)
    {
        if(dht.dhtData.Temp < 27)
        {
            // view.Warning();
            view.lightView();

        }
        else
        {
            // view.lightView();
            view.Warning();

        }
        listener.checkEvent();
        // view.lightView();
        delay(10);
    }

    return 0;
}