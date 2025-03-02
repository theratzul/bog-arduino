/*                                                                              
 * SoundSensor.cpp                                                              
 *                                                                              
 * Bogdan Popa                                              
 *                                                                              
 * Simple application to demonstrate the functionality of a FC-04 sound         
 * sensor.  Note that the sensor does _NOT_ detect sound intensity; it detects  
 * only its existance.  The default state of its output pin is HIGH, and when   
 * it detects sound it drops low.                                               
 */                                                                             
#include "Arduino.h"                                                            
                                                                                
enum {                                                                          
    SERIAL_BAUD        = 9600,                                                  
    SENSOR_DIGITAL_PIN =    9,                                                  
    SOUND_DELAY        =   10, /* Delay to avoid duplicate detection */         
};                                                                              
                                                                                
void setup() {                                                                  
    Serial.begin(SERIAL_BAUD);                                                  
    pinMode(SERIAL_BAUD, INPUT);                                                
}                                                                               
                                                                                
void loop() {                                                                   
    if (digitalRead(SENSOR_DIGITAL_PIN) == LOW) {                               
        static int count;                                                       
                                                                                
        Serial.print("Sound detected: ");                                       
        Serial.println(++count);                                                
                                                                                
        // Wait a short bit to avoid multiple detection of the same sound.      
        delay(SOUND_DELAY);                                                     
    }                                                                           
}