#include <Arduino.h>
#include <unity.h>

int array

int conf[8][3] = {
//  s0,s1,s2  
    {0,0,0}, //Y0
    {1,0,0}, //Y1
    {0,1,0}, //Y2
    {1,1,0}, //Y3
    {0,0,1}, //Y4
    {1,0,1}, //Y5
    {0,1,1}, //Y6
    {1,1,1}, //Y7
    

};

void test_selectMuxPin(){
    selectMuxPin(0)
}