#ifndef vizio_codes_h
#define vizio_codes_h


const int VIZIO_COMMAND_LENGTH = 68;
const int VIZIO_FREQ = 38; 


//raw data arrays 

unsigned int  VIZIO_POWER[VIZIO_COMMAND_LENGTH] = {9024 ,4512 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,564 ,
564 ,564 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,
1692 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,
564 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,39756};


unsigned int  VIZIO_MUTE[VIZIO_COMMAND_LENGTH] = {9024 ,4512 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,564 ,
564 ,564 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,
1692 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,
1692 ,564 ,1692 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,39756};

unsigned int  VIZIO_VOLUP[VIZIO_COMMAND_LENGTH] = {9024 ,4512 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,564 ,
564 ,564 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,
564 ,564 ,564 ,1692 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,564 ,1692 ,564 ,564 ,564 ,1692 ,564 ,
1692 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,1692 ,564 ,39756};

unsigned int  VIZIO_VOLDOWN[VIZIO_COMMAND_LENGTH] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 
564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 
564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 
1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 39756};

unsigned int  VIZIO_CHUP[VIZIO_COMMAND_LENGTH] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 
564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 
564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 
564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 39756};

unsigned int  VIZIO_CHDOWN[VIZIO_COMMAND_LENGTH] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 
564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 
564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 
564, 1692, 564, 1692, 564, 1692, 564, 39756};

#endif
