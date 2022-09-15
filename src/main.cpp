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

int main()
{
    std::cout << "Hello World!" << std::endl;

    Button modeButton(27);//mode
    Button powerButton(28);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockSerivce(&clockView);
    Controller control(&service, &clockSerivce);
    Listener listener(&modeButton,&powerButton, &control, &clockCheck);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(10);
    }

    return 0;
}