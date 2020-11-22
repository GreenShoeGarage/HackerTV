#include <IRremote.h>
#include <TFT_eSPI.h>
#include "hackertv.h"
#include "samsung_codes.h"  // tv_manufacturer_index = 0
#include "lg_codes.h"       // tv_manufacturer_index = 1
#include "vizio_codes.h"    // tv_manufacturer_index = 2

TFT_eSPI tft; //Initializing TFT LCD library
TFT_eSprite spr = TFT_eSprite(&tft); //Initializing the buffer
IRsend irsend; //Initializing IR Emitter

int tv_manufacturer_index = 0;
const int num_tv_manufacturers = 3;  //UPDATE ME AS NEW TVs ARE ADDED!!!

HACKERTV tv[] = {
  {SAMSUNG_FREQ, SAMSUNG_COMMAND_LENGTH, {0}, {0}, {0}, {0}, {0}, {0}},
  {LG_FREQ, LG_COMMAND_LENGTH, {0}, {0}, {0}, {0}, {0}, {0}},
  {VIZIO_FREQ, VIZIO_COMMAND_LENGTH, {0}, {0}, {0}, {0}, {0}, {0}}
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

  spr.fillSprite(TFT_WHITE); //Setting Background color
  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Hacker TV", 80, 10);
  spr.drawNumber(tv_manufacturer_index, 250, 10);

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

  //initialize HACKERTV structure with frequencies, command length, and commands
  for (int i = 0; i < num_tv_manufacturers; i++) {
    initialize_tv_settings();
  }
}





//////////////////////////////////////////////////////////////////////////////
void loop() {

  //tv select button, step through the different tv manufacturers
  if (digitalRead(WIO_KEY_C) == LOW) {
    tv_manufacturer_index++;
    if (tv_manufacturer_index > num_tv_manufacturers - 1) {
      tv_manufacturer_index = 0;
    }
  }

  //power button
  else if (digitalRead(WIO_KEY_A) == LOW) { //Detecting the button press
    irsend.sendRaw(tv[tv_manufacturer_index].tv_power, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(57, 90, 40, TFT_RED); //Fill circle with red color
    delay(1000);
  }

  //mute button
  else if (digitalRead(WIO_KEY_B) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_mute, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(57, 180, 40, TFT_BLUE);
    delay(1000);
  }

  //volume up switch
  else if (digitalRead(WIO_5S_UP) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_volup, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(250, 85, 25, TFT_DARKGREEN);
    delay(1000);
  }

  //volume down switch
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_voldown, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(250, 185, 25, TFT_RED);
    delay(1000);
  }

  //channel up switch
  else if (digitalRead(WIO_5S_RIGHT) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_chup, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(173, 85, 25, TFT_DARKGREEN);
    delay(1000);
  }

  //channel down switch
  else if (digitalRead(WIO_5S_LEFT) == LOW) {
    irsend.sendRaw(tv[tv_manufacturer_index].tv_chdown, tv[tv_manufacturer_index].tv_command_length, tv[tv_manufacturer_index].tv_freq);
    tft.fillCircle(173, 185, 25, TFT_RED);
    delay(1000);
  }


  //update display
  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Hacker TV", 80, 10);
  spr.drawNumber(tv_manufacturer_index, 250, 10);
  spr.pushSprite(0, 0); //Push to LCD
  delay(50);
}




/////////////////////////////////////////////////////////////////////////////////
void initialize_tv_settings() {

  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);

  switch (tv_manufacturer_index) {
    case 0:  //SAMSUNG
      tv[tv_manufacturer_index].tv_command_length = SAMSUNG_COMMAND_LENGTH;
      tv[tv_manufacturer_index].tv_freq = SAMSUNG_FREQ;
      memset(tv[tv_manufacturer_index].tv_power, 0, sizeof(tv[tv_manufacturer_index].tv_power));
      memcpy(tv[tv_manufacturer_index].tv_power, SAMSUNG_POWER, sizeof(SAMSUNG_POWER));

      memset(tv[tv_manufacturer_index].tv_mute, 0, sizeof(tv[tv_manufacturer_index].tv_mute));
      memcpy(tv[tv_manufacturer_index].tv_mute, SAMSUNG_MUTE, sizeof(SAMSUNG_MUTE));

      memset(tv[tv_manufacturer_index].tv_volup, 0, sizeof(tv[tv_manufacturer_index].tv_volup));
      memcpy(tv[tv_manufacturer_index].tv_volup, SAMSUNG_VOLUP, sizeof(SAMSUNG_VOLUP));

      memset(tv[tv_manufacturer_index].tv_voldown, 0, sizeof(tv[tv_manufacturer_index].tv_voldown));
      memcpy(tv[tv_manufacturer_index].tv_voldown, SAMSUNG_VOLDOWN, sizeof(SAMSUNG_VOLDOWN));

      memset(tv[tv_manufacturer_index].tv_chup, 0, sizeof(tv[tv_manufacturer_index].tv_chup));
      memcpy(tv[tv_manufacturer_index].tv_chup, SAMSUNG_CHUP, sizeof(SAMSUNG_CHUP));

      memset(tv[tv_manufacturer_index].tv_chdown, 0, sizeof(tv[tv_manufacturer_index].tv_chdown));
      memcpy(tv[tv_manufacturer_index].tv_chdown, SAMSUNG_CHDOWN, sizeof(SAMSUNG_CHDOWN));

      spr.drawString("SAMSUNG", 100, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
      break;




    case 1:  //LG
      tv[tv_manufacturer_index].tv_command_length = LG_COMMAND_LENGTH;
      tv[tv_manufacturer_index].tv_freq = LG_FREQ;

      memset(tv[tv_manufacturer_index].tv_power, 0, sizeof(tv[tv_manufacturer_index].tv_power));
      memcpy(tv[tv_manufacturer_index].tv_power, LG_POWER, sizeof(LG_POWER));

      memset(tv[tv_manufacturer_index].tv_mute, 0, sizeof(tv[tv_manufacturer_index].tv_mute));
      memcpy(tv[tv_manufacturer_index].tv_mute, LG_MUTE, sizeof(LG_MUTE));

      memset(tv[tv_manufacturer_index].tv_volup, 0, sizeof(tv[tv_manufacturer_index].tv_volup));
      memcpy(tv[tv_manufacturer_index].tv_volup, LG_VOLUP, sizeof(LG_VOLUP));

      memset(tv[tv_manufacturer_index].tv_voldown, 0, sizeof(tv[tv_manufacturer_index].tv_voldown));
      memcpy(tv[tv_manufacturer_index].tv_voldown, LG_VOLDOWN, sizeof(LG_VOLDOWN));

      memset(tv[tv_manufacturer_index].tv_chup, 0, sizeof(tv[tv_manufacturer_index].tv_chup));
      memcpy(tv[tv_manufacturer_index].tv_chup, LG_CHUP, sizeof(LG_CHUP));

      memset(tv[tv_manufacturer_index].tv_chdown, 0, sizeof(tv[tv_manufacturer_index].tv_chdown));
      memcpy(tv[tv_manufacturer_index].tv_chdown, LG_CHDOWN, sizeof(LG_CHDOWN));

      spr.drawString("LG", 150, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
      break;



    case 2:  //VIZIO
      tv[tv_manufacturer_index].tv_command_length = VIZIO_COMMAND_LENGTH;
      tv[tv_manufacturer_index].tv_freq = VIZIO_FREQ;

      memset(tv[tv_manufacturer_index].tv_power, 0, sizeof(tv[tv_manufacturer_index].tv_power));
      memcpy(tv[tv_manufacturer_index].tv_power, VIZIO_POWER, sizeof(VIZIO_POWER));

      memset(tv[tv_manufacturer_index].tv_mute, 0, sizeof(tv[tv_manufacturer_index].tv_mute));
      memcpy(tv[tv_manufacturer_index].tv_mute, VIZIO_MUTE, sizeof(VIZIO_MUTE));

      memset(tv[tv_manufacturer_index].tv_volup, 0, sizeof(tv[tv_manufacturer_index].tv_volup));
      memcpy(tv[tv_manufacturer_index].tv_volup, VIZIO_VOLUP, sizeof(VIZIO_VOLUP));

      memset(tv[tv_manufacturer_index].tv_voldown, 0, sizeof(tv[tv_manufacturer_index].tv_voldown));
      memcpy(tv[tv_manufacturer_index].tv_voldown, VIZIO_VOLDOWN, sizeof(VIZIO_VOLDOWN));

      memset(tv[tv_manufacturer_index].tv_chup, 0, sizeof(tv[tv_manufacturer_index].tv_chup));
      memcpy(tv[tv_manufacturer_index].tv_chup, VIZIO_CHUP, sizeof(VIZIO_CHUP));

      memset(tv[tv_manufacturer_index].tv_chdown, 0, sizeof(tv[tv_manufacturer_index].tv_chdown));
      memcpy(tv[tv_manufacturer_index].tv_chdown, VIZIO_CHDOWN, sizeof(VIZIO_CHDOWN));

      spr.drawString("VIZIO", 120, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
      break;


    default:    //SAMSUNG
      tv[tv_manufacturer_index].tv_command_length = SAMSUNG_COMMAND_LENGTH;
      tv[tv_manufacturer_index].tv_freq = SAMSUNG_FREQ;
      memset(tv[tv_manufacturer_index].tv_power, 0, sizeof(tv[tv_manufacturer_index].tv_power));
      memcpy(tv[tv_manufacturer_index].tv_power, SAMSUNG_POWER, sizeof(SAMSUNG_POWER));

      memset(tv[tv_manufacturer_index].tv_mute, 0, sizeof(tv[tv_manufacturer_index].tv_mute));
      memcpy(tv[tv_manufacturer_index].tv_mute, SAMSUNG_MUTE, sizeof(SAMSUNG_MUTE));

      memset(tv[tv_manufacturer_index].tv_volup, 0, sizeof(tv[tv_manufacturer_index].tv_volup));
      memcpy(tv[tv_manufacturer_index].tv_volup, SAMSUNG_VOLUP, sizeof(SAMSUNG_VOLUP));

      memset(tv[tv_manufacturer_index].tv_voldown, 0, sizeof(tv[tv_manufacturer_index].tv_voldown));
      memcpy(tv[tv_manufacturer_index].tv_voldown, SAMSUNG_VOLDOWN, sizeof(SAMSUNG_VOLDOWN));

      memset(tv[tv_manufacturer_index].tv_chup, 0, sizeof(tv[tv_manufacturer_index].tv_chup));
      memcpy(tv[tv_manufacturer_index].tv_chup, SAMSUNG_CHUP, sizeof(SAMSUNG_CHUP));

      memset(tv[tv_manufacturer_index].tv_chdown, 0, sizeof(tv[tv_manufacturer_index].tv_chdown));
      memcpy(tv[tv_manufacturer_index].tv_chdown, SAMSUNG_CHDOWN, sizeof(SAMSUNG_CHDOWN));

      spr.drawString("SAMSUNG", 100, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
  }
}
