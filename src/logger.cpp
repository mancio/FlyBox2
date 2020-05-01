#include <Arduino.h>


void log_ax(long x_p, long y_p, long z_p){
    
    
    Serial.print("Axis X: ");
    Serial.print(x_p);
    Serial.print("    Axis Y: ");
    Serial.print(y_p);
    Serial.print("    Axis Z: ");
    Serial.print(z_p);
    Serial.println("");
}