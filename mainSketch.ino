//Manipulation may be required
#include <Adafruit_PWMServoDriver.h> //Servo 
#include <FaBo9Axis_MPU9250.h>       //9 axis, gyro and mag sensor
#include <SparkFunMPL3115A2.h>       //Tempature and bariomitor 
#include <SD.h>                      // SD card 
#include <SPI.h>                     // Means of communcating
#define DEBUG(a) (Serial.println(a)) //Debug code, clear serial if you dont want it
// Setting LED pins
//TODO:Set pins via bit register? Make functions so ugly code isn't every where though
#define VCC_V_LED      D7
#define SD_LED         D19
#define MPL3115A2_LED  D18
#define MPU9250_LED    D17
#define MCU_LED        D16
#define VCC_V          A1
#define SERVO_S_V_A    A0
 
//Setting componets on respective pins
const int SD_CARD       = 999;
FaBo9Axis my_9Axis;
MPL3115A2 myPressure;

void setup() {
  Serial.begin(9600); //Debug, may want switch to toggle?
  pinMode(VCC_V_LED, OUTPUT);
  pinMode(SD_LED, OUTPUT);
  pinMode(MPL3115A2_LED, OUTPUT);
  pinMode(MPU9250_LED, OUTPUT);
  pinMode(MCU_LED, OUTPUT);

  //startup error checking, is my shit together?
  while (1) {
    if (SD.begin()) {
      DEBUG("SD is a go");
      if (my_9Axis.begin()) {
        DEBUG("Accel, Gyro, mag sense is a go!");
        //TODO: pressure and temp on I2c? May not be a good library
        myPressure.begin();
        break;
      } else {
        //TODO: What should the micro controler do if mpu9250 fails?
        DEBUG("9Axis FAILED HALP");
      }
    } else {
      //TODO: SD FAILED now what
      DEBUG("SD CARD FAILED");
    }
  }
}

void loop() {
  
}
