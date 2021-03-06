#ifndef lg_codes_h
#define lg_codes_h

const int LG_COMMAND_LENGTH = 68;
const int LG_FREQ = 38; 

unsigned int  LG_POWER[LG_COMMAND_LENGTH] = {4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,
650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,
450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,
650,1600,650,1550,650,1550,700,1550,650,1550,650};

unsigned int  LG_MUTE[LG_COMMAND_LENGTH] = {4650,4350,650,1550,650,1550,700,1550,700,400,700,400,700,400,
700,450,650,450,650,1550,700,1500,700,1550,700,400,700,450,650,400,700,450,700,400,700,
1500,700,1550,650,1550,700,1500,700,450,700,400,700,400,700,400,700,400,700,450,650,450,
700,400,700,1500,700,1550,650,1550,700,1500,700};

unsigned int  LG_VOLUP[LG_COMMAND_LENGTH] = {4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,
650,450,700,400,700,1500,700,1550,650,1550,700,400,700,400,700,450,650,450,700,400,700,
1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,450,650,
1550,700,1500,700,1550,700,1500,700,1550,650};

unsigned int  LG_VOLDOWN[LG_COMMAND_LENGTH] = {4600,4350,700,1550,650,1550,700,1500,700,450,650,450,700,
400,700,400,700,400,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,
650,1550,700,1500,700,450,650,1550,700,400,700,400,700,450,700,400,700,400,700,400,700,
1550,700,400,700,1500,700,1500,700,1550,700,1500,700};

unsigned int  LG_CHUP[LG_COMMAND_LENGTH] = {4600,4350,700,1500,700,1500,700,1550,700,450,650,400,700,
50,650,450,700,400,700,1500,700,1550,650,1550,700,450,650,450,700,400,700,400,700,
400,700,400,700,1550,700,400,700,400,700,1550,650,450,700,400,700,400,700,1550,650,
450,650,1600,650,1550,650,450,700,1500,700,1500,700,1550,650};

unsigned int  LG_CHDOWN[LG_COMMAND_LENGTH] = {4650,4300,700,1550,700,1500,700,1550,700,400,700,400,
700,400,700,450,650,450,650,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,
700,400,700,400,700,400,700,450,650,450,650,1550,700,400,700,450,650,400,700,1550,
700,1500,700,1550,700,1500,700,400,700,1550,650,1550,700,1500,700};

char LG_NAME[] = "LG";

#endif
