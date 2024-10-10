#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led[2] = {
    LED(LED_PIN1, LED_ACT),
    LED(LED_PIN2, LED_ACT),
};

unsigned char flag =0;

void btnPush();
void btnHold();
void btndbclick();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led[0].off();
    led[1].off();
    button.attachClick(btnPush);
    button.attachLongPressStart(btnHold);
    button.attachDoubleClick(btndbclick);

}

void loop()
{
    led[0].loop();
    led[1].loop();
    button.tick();
}

void btndbclick(){
  flag =(flag +1)%2;
}

void btnPush()
{
    led[flag].flip();
}


void btnHold()
{
    led[flag].blink(200);
}