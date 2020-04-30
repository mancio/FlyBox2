#include <Arduino.h>
#include <unity.h>
#include <Timer.h>
//#include <../src/Timer.h>

// time loop operation
unsigned long lp = 5000;

//time expired
unsigned long t_exp = 1000;

// initialize timer for testing 
Timer_ timer_test;


void test_time_expired(){
    TEST_ASSERT_TRUE(timer_test.expired(t_exp));
}

void setup(){

}

void loop(){
    unsigned long t = 0;
    while (t<lp){
        Serial.print("time ");
        Serial.println(t);
        t++;
    }
    RUN_TEST(test_time_expired);
}





