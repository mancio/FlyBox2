#include <Encoder.h>

Encoder_::Encoder_(int clk, int dt, int sw){
    _clk = clk;
    _dt = dt;
    _sw = sw;

    _encoder0PinALast = LOW;
    _n = LOW;

    _Timer;
}

int Encoder_::direction(long out_t){
    _n = digitalRead(_clk);
    if ((_encoder0PinALast == LOW) && (_n == HIGH)) {
    if (digitalRead(_dt) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
    Serial.print (encoder0Pos);
    Serial.print ("/");
  }
  _encoder0PinALast = _n;
}