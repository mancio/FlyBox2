#include <Pushbutton.h>

Button_::Button_(){
    
    _last_state = HIGH;

    _state = HIGH;

    _name = "NONE";

    //_pin = A3;
}

int Button_::debounce(long delay){
    
    _state = digitalRead(_pin);

    //Serial.println(_state);

    _last_state = _state;

    if(_Timer.expired(delay)){
        _Timer.update();
        //Serial.println(_state);
        if (!_state){
            //Serial.println("return 1");
            return 0;
        } else {
            //Serial.println("return zero");
            return 1;
        } 
    }

    //Serial.println(_last_state);

    return _last_state;
    
}

void Button_::setPin(int pin){
    _pin = pin;
}

void Button_::setName(String name){
    _name = name;
}

String Button_::getName(){
    return _name;
}