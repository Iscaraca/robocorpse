
// Include Libraries
#include "Arduino.h"
#include "PIR.h"


// Pin Definitions
#define IRCAMERA_5V_PIN_INT	2
#define MQ7_5V_PIN_AOUT	A3
#define PIR_PIN_SIG	3



// Global variables and defines

// object initialization
PIR pir(PIR_PIN_SIG);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1')
    {
    // Disclaimer: The AMG8833 IR Thermal Camera Breakout is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '2')
    {
    // Disclaimer: The Carbon Monoxide Sensor - MQ-7 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '3') {
    // Infrared PIR Motion Sensor Module - Test Code
    bool pirVal = pir.read();
    Serial.print(F("Val: ")); Serial.println(pirVal);

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) AMG8833 IR Thermal Camera Breakout"));
    Serial.println(F("(2) Carbon Monoxide Sensor - MQ-7"));
    Serial.println(F("(3) Infrared PIR Motion Sensor Module"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("AMG8833 IR Thermal Camera Breakout in use- no code yet"));
    		else if(c == '2') 
    			Serial.println(F("Carbon Monoxide Sensor - MQ-7 in use- no code yet"));
    		else if(c == '3') 
    			Serial.println(F("Infrared PIR Motion Sensor Module in use"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
