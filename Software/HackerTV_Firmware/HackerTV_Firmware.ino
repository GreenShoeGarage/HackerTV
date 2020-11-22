#include "IRremote.h" //IR remote library
#include "TFT_eSPI.h" //TFT LCD library
#include "samsung_codes.h"
#include "lg_codes.h"


#define MAX_COMMAND_SIZE 100


TFT_eSPI tft; //Initializing TFT LCD library
TFT_eSprite spr = TFT_eSprite(&tft); //Initializing the buffer
IRsend irsend; //Initializing IR Emitter

int tv_manufacturer_index = 0;
int num_tv_manufacturers = 2;

int tv_freq = SAMSUNG_FREQ;
int tv_command_length = SAMSUNG_COMMAND_LENGTH;
unsigned int tv_power[MAX_COMMAND_SIZE];
unsigned int tv_mute[MAX_COMMAND_SIZE];
unsigned int tv_volup[MAX_COMMAND_SIZE];
unsigned int tv_voldown[MAX_COMMAND_SIZE];
unsigned int tv_chup[MAX_COMMAND_SIZE];
unsigned int tv_chdown[MAX_COMMAND_SIZE];



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

  memset(tv_power, 0, sizeof(tv_power));
  memset(tv_mute, 0, sizeof(tv_mute));
  memset(tv_volup, 0, sizeof(tv_volup));
  memset(tv_voldown, 0, sizeof(tv_voldown));
  memset(tv_chup, 0, sizeof(tv_chup));
  memset(tv_chdown, 0, sizeof(tv_chdown));
}





//////////////////////////////////////////////////////////////////////////////
void loop() {

  //step through the different tv manufacturers
  if (digitalRead(WIO_KEY_C) == LOW) {
    tv_manufacturer_index++;
    if (tv_manufacturer_index > num_tv_manufacturers - 1) {
      tv_manufacturer_index = 0;
    }
    update_tv_settings();
  }

  //power button
  else if (digitalRead(WIO_KEY_A) == LOW) { //Detecting the button press
    irsend.sendRaw(tv_power, tv_command_length, tv_freq);
    tft.fillCircle(57, 90, 40, TFT_RED); //Fill circle with red color
    delay(1000);
  }

  
  //mute button
  else if (digitalRead(WIO_KEY_B) == LOW) {
    irsend.sendRaw(tv_mute, tv_command_length, tv_freq);
    tft.fillCircle(57, 180, 40, TFT_BLUE);
    delay(1000);
  }


  
  //volume up switch
  else if (digitalRead(WIO_5S_UP) == LOW) {
    irsend.sendRaw(tv_volup, tv_command_length, tv_freq);
    tft.fillCircle(250, 85, 25, TFT_DARKGREEN);
    delay(1000);
  }


  
  //volume down switch
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
    irsend.sendRaw(tv_voldown, tv_command_length, tv_freq);
    tft.fillCircle(250, 185, 25, TFT_RED);
    delay(1000);
  }


  
  //channel up switch
  else if (digitalRead(WIO_5S_RIGHT) == LOW) {
    irsend.sendRaw(tv_chup, tv_command_length, tv_freq);
    tft.fillCircle(173, 85, 25, TFT_DARKGREEN);
    delay(1000);
  }


  
  //channel down switch
  else if (digitalRead(WIO_5S_LEFT) == LOW) {
    irsend.sendRaw(tv_chdown, tv_command_length, tv_freq);
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




/////////////////////////////////////////////////////////////////////////////////
void update_tv_settings() {

  spr.fillRect(0, 0, 320, 45, TFT_DARKGREEN);
  spr.setTextSize(3);
  spr.setTextColor(TFT_WHITE);

  switch (tv_manufacturer_index) {
    case 0:  //SAMSUNG
      tv_command_length = SAMSUNG_COMMAND_LENGTH;
      tv_freq = SAMSUNG_FREQ;
      memset(tv_power, 0, sizeof(tv_power));
      memcpy(tv_power, SAMSUNG_POWER, sizeof(SAMSUNG_POWER));

      memset(tv_mute, 0, sizeof(tv_mute));
      memcpy(tv_mute, SAMSUNG_MUTE, sizeof(SAMSUNG_MUTE));

      memset(tv_volup, 0, sizeof(tv_volup));
      memcpy(tv_volup, SAMSUNG_VOLUP, sizeof(SAMSUNG_VOLUP));

      memset(tv_voldown, 0, sizeof(tv_voldown));
      memcpy(tv_voldown, SAMSUNG_VOLDOWN, sizeof(SAMSUNG_VOLDOWN));

      memset(tv_chup, 0, sizeof(tv_chup));
      memcpy(tv_chup, SAMSUNG_CHUP, sizeof(SAMSUNG_CHUP));

      memset(tv_chdown, 0, sizeof(tv_chdown));
      memcpy(tv_chdown, SAMSUNG_CHDOWN, sizeof(SAMSUNG_CHDOWN));

      spr.drawString("SAMSUNG", 100, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
      break;




    case 1:  //LG
      tv_command_length = LG_COMMAND_LENGTH;
      tv_freq = LG_FREQ;

      memset(tv_power, 0, sizeof(tv_power));
      memcpy(tv_power, LG_POWER, sizeof(LG_POWER));

      memset(tv_mute, 0, sizeof(tv_mute));
      memcpy(tv_mute, LG_MUTE, sizeof(LG_MUTE));

      memset(tv_volup, 0, sizeof(tv_volup));
      memcpy(tv_volup, LG_VOLUP, sizeof(LG_VOLUP));

      memset(tv_voldown, 0, sizeof(tv_voldown));
      memcpy(tv_voldown, LG_VOLDOWN, sizeof(LG_VOLDOWN));

      memset(tv_chup, 0, sizeof(tv_chup));
      memcpy(tv_chup, LG_CHUP, sizeof(LG_CHUP));

      memset(tv_chdown, 0, sizeof(tv_chdown));
      memcpy(tv_chdown, LG_CHDOWN, sizeof(LG_CHDOWN));

      spr.drawString("LG", 150, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
      break;






    default:    //SAMSUNG
      tv_command_length = SAMSUNG_COMMAND_LENGTH;
      tv_freq = SAMSUNG_FREQ;
      memset(tv_power, 0, sizeof(tv_power));
      memcpy(tv_power, SAMSUNG_POWER, sizeof(SAMSUNG_POWER));

      memset(tv_mute, 0, sizeof(tv_mute));
      memcpy(tv_mute, SAMSUNG_MUTE, sizeof(SAMSUNG_MUTE));

      memset(tv_volup, 0, sizeof(tv_volup));
      memcpy(tv_volup, SAMSUNG_VOLUP, sizeof(SAMSUNG_VOLUP));

      memset(tv_voldown, 0, sizeof(tv_voldown));
      memcpy(tv_voldown, SAMSUNG_VOLDOWN, sizeof(SAMSUNG_VOLDOWN));

      memset(tv_chup, 0, sizeof(tv_chup));
      memcpy(tv_chup, SAMSUNG_CHUP, sizeof(SAMSUNG_CHUP));

      memset(tv_chdown, 0, sizeof(tv_chdown));
      memcpy(tv_chdown, SAMSUNG_CHDOWN, sizeof(SAMSUNG_CHDOWN));

      spr.drawString("SAMSUNG", 100, 10);
      spr.pushSprite(0, 0); //Push to LCD
      delay(2000);
  }
}
