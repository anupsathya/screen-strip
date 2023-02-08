#include "Adafruit_Thermal.h"
// #include "adalogo.h"
// #include "adaqrcode.h"

#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_IN1 3
#define PIN_IN2 5

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 7 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);

void setup()
{
  // Serial.begin(115200);
  // while (! Serial);
  // Serial.println("SimplePollRotator example for the RotaryEncoder library.");
  pinMode(5, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  pinMode(7, OUTPUT); digitalWrite(7, LOW);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200);
  //printer.setTimes(80, 190); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)
  

  // The following calls are in setup(), but don't *need* to be.  Use them
  // anywhere!  They're just here so they run one time and are not printed
  // over and over (which would happen if they were in loop() instead).
  // Some functions will feed a line when called, this is normal.

  // Font options
  
  // printer.sleep();      // Tell printer to sleep
  // delay(3000L);         // Sleep for 3 seconds
  // printer.wake();       // MUST wake() before printing again, even if reset
  // printer.setDefault(); // Restore printer to defaults
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    // Serial.print("pos:");
    // Serial.print(newPos);
    // Serial.print(" dir:");
    // Serial.println((int)(encoder.getDirection()));
    printer.println("Willa is the best");
    pos = newPos;
  } // if
  // printer.sleep();  
} // loop ()

// The End

