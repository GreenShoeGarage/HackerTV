#ifndef hackertv_h
#define hackertv_h

#define MAX_COMMAND_SIZE 100
#define MAX_TITLE_SIZE 20

typedef struct hackertv {
  int tv_freq;
  int tv_command_length;
  unsigned int tv_power[MAX_COMMAND_SIZE];
  unsigned int tv_mute[MAX_COMMAND_SIZE];
  unsigned int tv_volup[MAX_COMMAND_SIZE];
  unsigned int tv_voldown[MAX_COMMAND_SIZE];
  unsigned int tv_chup[MAX_COMMAND_SIZE];
  unsigned int tv_chdown[MAX_COMMAND_SIZE];
  char tv_manufacturer_name[MAX_TITLE_SIZE];
} HACKERTV ;

#endif
