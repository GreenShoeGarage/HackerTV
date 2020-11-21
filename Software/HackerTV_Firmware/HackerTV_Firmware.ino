#include "IRremote.h" //IR remote library
#include "TFT_eSPI.h" //TFT LCD library
#include "samsung_codes.h"

TFT_eSPI tft; //Initializing TFT LCD library
TFT_eSprite spr = TFT_eSprite(&tft); //Initializing the buffer
IRsend irsend; //Initializing IR Emitter

int tv_manufacturer_index = 0;
unsigned int *tv_power = SAMSUNG_POWER;
unsigned int *tv_mute = SAMSUNG_MUTE;
unsigned int *tv_chup = SAMSUNG_CHUP;
unsigned int *tv_chdown = SAMSUNG_CHDOWN;
unsigned int *tv_volup = SAMSUNG_VOLUP;
unsigned int *tv_voldown = SAMSUNG_VOLDOWN;
int tv_command_length = 0;
int tv_freq = 0;

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
}

void loop() {

  //step through the different tv manufacturers
  if (digitalRead(WIO_KEY_C) == LOW) {
    tv_manufacturer_index++;
    if (tv_manufacturer_index > 12) {
      tv_manufacturer_index = 0;
    }
    changeTVSettings();
    delay(1000);
  }

  //power button
  else if (digitalRead(WIO_KEY_A) == LOW) { //Detecting the button press
    irsend.sendRaw(tv_power, tv_command_length, tv_freq); //Pass the array, array length, carrier frequency
    tft.fillCircle(57, 90, 40, TFT_RED); //Fill circle with red color
    delay(1000);
  }
  //mute button
  else if (digitalRead(WIO_KEY_B) == LOW) {
    irsend.sendRaw(SAMSUNG_MUTE, tv_command_length, tv_freq);
    tft.fillCircle(57, 180, 40, TFT_BLUE);
    delay(1000);
  }
  //volume up switch
  else if (digitalRead(WIO_5S_UP) == LOW) {
    irsend.sendRaw(SAMSUNG_VOLUP, tv_command_length, tv_freq);
    tft.fillCircle(250, 85, 25, TFT_DARKGREEN);
    delay(1000);
  }
  //volume down switch
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
    irsend.sendRaw(SAMSUNG_VOLDOWN, tv_command_length, tv_freq);
    tft.fillCircle(250, 185, 25, TFT_RED);
    delay(1000);
  }
  //channel up switch
  else if (digitalRead(WIO_5S_RIGHT) == LOW) {
    irsend.sendRaw(SAMSUNG_CHUP, tv_command_length, tv_freq);
    tft.fillCircle(173, 85, 25, TFT_DARKGREEN);
    delay(1000);
  }
  //channel down switch
  else if (digitalRead(WIO_5S_LEFT) == LOW) {
    irsend.sendRaw(SAMSUNG_CHDOWN, tv_command_length, tv_freq);
    tft.fillCircle(173, 185, 25, TFT_RED);
    delay(1000);
  }

  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);
  spr.drawString("Hacker TV", 80, 10);
  spr.drawNumber(tv_manufacturer_index, 250, 10);
  spr.pushSprite(0, 0); //Push to LCD
  delay(50);
}




void changeTVSettings() {
  switch (tv_manufacturer_index) {
    case 0:
      tv_power = SAMSUNG_POWER;
      tv_mute = SAMSUNG_MUTE;
      tv_volup = SAMSUNG_VOLUP;
      tv_voldown = SAMSUNG_VOLDOWN;
      tv_chup = SAMSUNG_CHUP;
      tv_chdown = SAMSUNG_CHDOWN;
      tv_command_length = SAMSUNG_COMMANDLENGTH;
      tv_freq = SAMSUNG_FREQ;
      break;
      
    default:
      tv_power = SAMSUNG_POWER;
      tv_command_length = SAMSUNG_COMMANDLENGTH;
      tv_freq = SAMSUNG_FREQ;
  }
}
