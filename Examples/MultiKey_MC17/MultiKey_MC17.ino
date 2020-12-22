/* Multikey_MC17 - 16-bit I2C port conversion of Keypad's Multikey
:: G. D. (Joe) Young Feb 12, 2013
:: MC23017 version - GDY May 19, 2014
::
|| @file MultiKey.ino
|| @version 1.0
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
|| 
|| Modified for Keypad 5x5 Matrix I2C Board by Mehmet S. Bilge 01/2020
*/

#include <Keypad.h>
#include <Keypad_MC17.h>    // I2C i/o library for Keypad
#include <Wire.h>           // I2C library for Keypad_MC17

#define I2CADDR 0x27

const byte ROWS = 5; 
const byte COLS = 5; 
char keys[ROWS][COLS] = {
  {'1','2','3','4','5'},
  {'6','7','8','9','0'},
  {'A','B','C','D','E'},
  {'F','G','H','I','J'},
  {'K','L','M','N','O'}
};

byte rowPins[ROWS] = {0,1,2,3,4};     //Row pin connections to the MCP23017
byte colPins[COLS] = {8,9,10,11,12};  //Column pin connections to the MCP23017


// modify constructor for I2C i/o
Keypad_MC17 kpd = Keypad_MC17( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR );

String msg = "";

void setup() {
  Serial.begin(9600);
  kpd.begin( );            // also starts wire library
}

void loop() {

  // Fills kpd.key[ ] array with up-to 10 active keys.
  // Returns true if there are ANY active keys.
  if (kpd.getKeys())
  {
    for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
    {
      if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
      {
        switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
            case PRESSED:
                msg = " PRESSED.";
                break;
            case HOLD:
                msg = " HOLD.";
                break;
            case RELEASED:
                msg = " RELEASED.";
                break;
            case IDLE:
                msg = " IDLE.";
        }
        Serial.print("Key ");
        Serial.print(kpd.key[i].kchar);
        Serial.println(msg);
      }
    }
  }
}  // End loop
