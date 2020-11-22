#ifndef samsung_codes_h
#define samsung_codes_h


const int SAMSUNG_COMMAND_LENGTH = 68;
const int SAMSUNG_FREQ = 38; 


//raw data arrays 

unsigned int  SAMSUNG_POWER[SAMSUNG_COMMAND_LENGTH] = {4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,
650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,
450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,
650,1600,650,1550,650,1550,700,1550,650,1550,650};


unsigned int  SAMSUNG_MUTE[SAMSUNG_COMMAND_LENGTH] = {4650,4350,650,1550,650,1550,700,1550,700,400,700,400,700,400,
700,450,650,450,650,1550,700,1500,700,1550,700,400,700,450,650,400,700,450,700,400,700,
1500,700,1550,650,1550,700,1500,700,450,700,400,700,400,700,400,700,400,700,450,650,450,
700,400,700,1500,700,1550,650,1550,700,1500,700};

unsigned int  SAMSUNG_VOLUP[SAMSUNG_COMMAND_LENGTH] = {4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,
650,450,700,400,700,1500,700,1550,650,1550,700,400,700,400,700,450,650,450,700,400,700,
1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,450,650,
1550,700,1500,700,1550,700,1500,700,1550,650};

unsigned int  SAMSUNG_VOLDOWN[SAMSUNG_COMMAND_LENGTH] = {4600,4350,700,1550,650,1550,700,1500,700,450,650,450,700,
400,700,400,700,400,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,
650,1550,700,1500,700,450,650,1550,700,400,700,400,700,450,700,400,700,400,700,400,700,
1550,700,400,700,1500,700,1500,700,1550,700,1500,700};

unsigned int  SAMSUNG_CHUP[SAMSUNG_COMMAND_LENGTH] = {4600,4350,700,1500,700,1500,700,1550,700,450,650,400,700,
50,650,450,700,400,700,1500,700,1550,650,1550,700,450,650,450,700,400,700,400,700,
400,700,400,700,1550,700,400,700,400,700,1550,650,450,700,400,700,400,700,1550,650,
450,650,1600,650,1550,650,450,700,1500,700,1500,700,1550,650};

unsigned int  SAMSUNG_CHDOWN[SAMSUNG_COMMAND_LENGTH] = {4650,4300,700,1550,700,1500,700,1550,700,400,700,400,
700,400,700,450,650,450,650,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,
700,400,700,400,700,400,700,450,650,450,650,1550,700,400,700,450,650,400,700,1550,
700,1500,700,1550,700,1500,700,400,700,1550,650,1550,700,1500,700};

#endif
