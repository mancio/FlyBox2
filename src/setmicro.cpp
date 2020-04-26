#include <Arduino.h>

void setLed(){
    // disable TXLED and RXLED (TXLED is always on if the USB is tranmitting data)
    DDRD &= ~(1<<5);
} 