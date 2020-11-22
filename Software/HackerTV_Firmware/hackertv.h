#ifndef hackertv_h
#define hackertv_h

#define MAX_COMMAND_SIZE 100

typedef struct hackertv {
  int tv_freq;
  int tv_command_length;
  unsigned int tv_power[MAX_COMMAND_SIZE];
  unsigned int tv_mute[MAX_COMMAND_SIZE];
  unsigned int tv_volup[MAX_COMMAND_SIZE];
  unsigned int tv_voldown[MAX_COMMAND_SIZE];
  unsigned int tv_chup[MAX_COMMAND_SIZE];
  unsigned int tv_chdown[MAX_COMMAND_SIZE];
} HACKERTV ;


#endif
