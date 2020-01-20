/* @file HelloKeypad.ino
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
   Modified for Keypad_MCP G. D. (Joe) Young July 29/12
   Modified for Keypad_MC16 G. D. (Joe) Young Jan 26/13
   Modified for Keypad_MC17 G. D. (Joe) Young May 18/14
   Modified for Keypad 5x5 Matrix I2C Board by Mehmet S. Bilge 01/2020
*/

#include <Keypad_MC17.h>
#include <Wire.h>
#include <Keypad.h>

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

byte rowPins[ROWS] = {4,3,2,1,0};     //Row pin connections to the MCP23017
byte colPins[COLS] = {8,9,10,11,12};  //Column pin connections to the MCP23017

Keypad_MC17 keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR );

void setup(){
  Serial.begin(9600);
  keypad.begin( );
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}
