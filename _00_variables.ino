#include "_04_Headers.h"
#include "Arduino.h"
#include <SPI.h>
#include <Ethernet.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

boolean ethernetIsConnected = false;

byte mac[] = {
  0x90, 0xA2, 0xDA, 0x0E, 0xC2, 0xBD};

unsigned long loopCounter = 0L;

TeleInfo* myTeleInfo;

const int plusButtonPin = 6;  // the number of the pushbutton pin
const int minusButtonPin = 7; // the number of the pushbutton pin
const int modeButtonPin = 13; // the number of the pushbutton pin

// variables will change:
int plusButtonState = 0;
int minusButtonState = 0;
int modeButtonState = 0;

