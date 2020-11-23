//*******************************************************************************
//File: HackerTV_Firmware.ino
//Version:  v0.0.1
//Date Revised:  22 November 2020
//
//https://github.com/GreenShoeGarage/HackerTV
//
//Released under MIT License
//
//Based on work by Lakshantha Dissanayake https://github.com/lakshanthad/Wio_Terminal_Classroom_Arduino/tree/main/Classroom%2011
//********************************************************************************

#include <IRremote.h>
#include <TFT_eSPI.h>
#include "hackertv.h"
#include "samsung_codes.h"  // tv_manufacturer_index = 0
#include "lg_codes.h"       // tv_manufacturer_index = 1
#include "vizio_codes.h"    // tv_manufacturer_index = 2

#define DELAYAMOUNT 500

TFT_eSPI tft; //Initializing TFT LCD library
TFT_eSprite spr = TFT_eSprite(&tft); //Initializing the buffer
IRsend irsend; //Initializing IR Emitter

int tv_manufacturer_index = 0;
const int num_tv_manufacturers = 3;  //UPDATE ME AS NEW TVs ARE ADDED!!!

HACKERTV tv[] = {
  {SAMSUNG_FREQ, SAMSUNG_COMMAND_LENGTH, {0}, {0}, {0}, {0}, {0}, {0}, "SAMSUNG"},
  {LG_FREQ, LG_COMMAND_LENGTH, {0}, {0}, {0}, {0}, {0}, {0}, "LG"},
  {VIZIO_FREQ, VIZIO_COMMAND_LENGTH, {0}, {0}, {0}, {0}, {0}, {0}, "VIZIO"}
};




//////////////////////////////////////////////////////////////////////////
void setup() {
  //Configuring the buttons and the 5-way switch as inputs
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_C, INPUT);
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);

  tft.begin(); //LCD initialization
  tft.setRotation(3); //Setting LCD rotation
  spr.createSprite(TFT_HEIGHT, TFT_WIDTH); //Creating the buffer

  //initialize HACKERTV structure with frequencies, command length, and commands
  for (int i = 0; i < num_tv_manufacturers; i++) {
    initialize_tv_settings();
  }

  init_screen();
}



//////////////////////////////////////////////////////////////////////////////
void loop() {

  //tv select button, step through the different tv manufacturers
  if (digitalRead(WIO_KEY_C) == LOW) {
    tv_manufacturer_index++;
    if (tv_manufacturer_index > num_tv_manufacturers - 1) {
      tv_manufacturer_index = 0;
    }
    //update display
    spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
    spr.setTextSize(3);
    spr.setTextColor(TFT_WHITE);
    spr.drawString(tv[tv_manufacturer_index].tv_manufacturer_name, 10, 10);
    spr.pushSprite(0, 0); //Push to LCD
    delay(DELAYAMOUNT);

  }

  //power button
  else if (digitalRead(WIO_KEY_A) == LOW) { //Detecting the button press
    irsend.sendRaw(tv[tv_manufacturer_index].tv_power, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(57, 90, 40, TFT_RED); //Fill circle with red color
    delay(DELAYAMOUNT);
  }

  //mute button
  else if (digitalRead(WIO_KEY_B) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_mute, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(57, 180, 40, TFT_BLUE);
    delay(DELAYAMOUNT);
  }

  //volume up switch
  else if (digitalRead(WIO_5S_UP) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_volup, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(250, 85, 25, TFT_DARKGREEN);
    delay(DELAYAMOUNT);
  }

  //volume down switch
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_voldown, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(250, 185, 25, TFT_RED);
    delay(DELAYAMOUNT);
  }

  //channel up switch
  else if (digitalRead(WIO_5S_RIGHT) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_chup, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(173, 85, 25, TFT_DARKGREEN);
    delay(DELAYAMOUNT);
  }

  //channel down switch
  else if (digitalRead(WIO_5S_LEFT) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_chdown, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(173, 185, 25, TFT_RED);
    delay(DELAYAMOUNT);
  }

  spr.pushSprite(0, 0); //Push to LCD
}




/////////////////////////////////////////////////////////////////////////////////
void initialize_tv_settings() {

  switch (tv_manufacturer_index) {
    case 0:  //SAMSUNG
      memcpy(tv[tv_manufacturer_index].tv_power, SAMSUNG_POWER, sizeof(SAMSUNG_POWER));
      memcpy(tv[tv_manufacturer_index].tv_mute, SAMSUNG_MUTE, sizeof(SAMSUNG_MUTE));
      memcpy(tv[tv_manufacturer_index].tv_volup, SAMSUNG_VOLUP, sizeof(SAMSUNG_VOLUP));
      memcpy(tv[tv_manufacturer_index].tv_voldown, SAMSUNG_VOLDOWN, sizeof(SAMSUNG_VOLDOWN));
      memcpy(tv[tv_manufacturer_index].tv_chup, SAMSUNG_CHUP, sizeof(SAMSUNG_CHUP));
      memcpy(tv[tv_manufacturer_index].tv_chdown, SAMSUNG_CHDOWN, sizeof(SAMSUNG_CHDOWN));
      break;

    case 1:  //LG
      memcpy(tv[tv_manufacturer_index].tv_power, LG_POWER, sizeof(LG_POWER));
      memcpy(tv[tv_manufacturer_index].tv_mute, LG_MUTE, sizeof(LG_MUTE));
      memcpy(tv[tv_manufacturer_index].tv_volup, LG_VOLUP, sizeof(LG_VOLUP));
      memcpy(tv[tv_manufacturer_index].tv_voldown, LG_VOLDOWN, sizeof(LG_VOLDOWN));
      memcpy(tv[tv_manufacturer_index].tv_chup, LG_CHUP, sizeof(LG_CHUP));
      memcpy(tv[tv_manufacturer_index].tv_chdown, LG_CHDOWN, sizeof(LG_CHDOWN));
      break;

    case 2:  //VIZIO
      memcpy(tv[tv_manufacturer_index].tv_power, VIZIO_POWER, sizeof(VIZIO_POWER));
      memcpy(tv[tv_manufacturer_index].tv_mute, VIZIO_MUTE, sizeof(VIZIO_MUTE));
      memcpy(tv[tv_manufacturer_index].tv_volup, VIZIO_VOLUP, sizeof(VIZIO_VOLUP));
      memcpy(tv[tv_manufacturer_index].tv_voldown, VIZIO_VOLDOWN, sizeof(VIZIO_VOLDOWN));
      memcpy(tv[tv_manufacturer_index].tv_chup, VIZIO_CHUP, sizeof(VIZIO_CHUP));
      memcpy(tv[tv_manufacturer_index].tv_chdown, VIZIO_CHDOWN, sizeof(VIZIO_CHDOWN));
      break;

    default:    //SAMSUNG
      memcpy(tv[tv_manufacturer_index].tv_power, SAMSUNG_POWER, sizeof(SAMSUNG_POWER));
      memcpy(tv[tv_manufacturer_index].tv_mute, SAMSUNG_MUTE, sizeof(SAMSUNG_MUTE));
      memcpy(tv[tv_manufacturer_index].tv_volup, SAMSUNG_VOLUP, sizeof(SAMSUNG_VOLUP));
      memcpy(tv[tv_manufacturer_index].tv_voldown, SAMSUNG_VOLDOWN, sizeof(SAMSUNG_VOLDOWN));
      memcpy(tv[tv_manufacturer_index].tv_chup, SAMSUNG_CHUP, sizeof(SAMSUNG_CHUP));
      memcpy(tv[tv_manufacturer_index].tv_chdown, SAMSUNG_CHDOWN, sizeof(SAMSUNG_CHDOWN));
  }
}




/////////////////////////////////////////////////////////////////////
void init_screen() {

  spr.fillSprite(TFT_WHITE); //Setting Background color
  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Hacker TV v0.0.1", 20, 10);

  //Draw power button
  spr.setTextSize(2);
  spr.setTextColor(TFT_BLACK);
  spr.drawCircle(57, 90, 40, TFT_RED); //Drawing circle with red outline
  spr.drawString("POWER", 30, 85);

  //Draw mute button
  spr.drawCircle(57, 180, 40, TFT_BLUE);
  spr.drawString("MUTE", 35, 175);

  //Draw verticle line
  spr.drawFastVLine(115, 0, 240, TFT_DARKGREEN);

  //Draw channel buttons
  spr.setTextSize(3);
  spr.drawString("CH", 155, 125);
  spr.drawCircle(173, 85, 25, TFT_DARKGREEN);
  spr.drawCircle(173, 185, 25, TFT_RED);

  //Draw volume buttons
  spr.drawString("VOL", 230, 125);
  spr.drawCircle(250, 85, 25, TFT_DARKGREEN);
  spr.drawCircle(250, 185, 25, TFT_RED);

  spr.pushSprite(0, 0); //Push to LCD
  delay(2000);
  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);
  spr.drawString(tv[tv_manufacturer_index].tv_manufacturer_name, 10, 10);
  spr.pushSprite(0, 0); //Push to LCD
}
