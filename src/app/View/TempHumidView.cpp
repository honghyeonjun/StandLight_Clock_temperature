#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *lcd)
{
    this->lcd = lcd;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];
    sprintf(buff, "%.1fC", temp);
    lcd->WriteStringXY(0, 10, "            ");
    lcd->WriteStringXY(0, 10, buff);

    sprintf(buff, " %.1f%% ", humid);
    lcd->WriteStringXY(1, 9, buff);
    printf("%.1f'C, %.1f%%\n",temp,humid);

  
}