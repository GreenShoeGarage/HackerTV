# HackerTV
 Turning a Seeed Wio Terminal into a modular Universal TV Remote.
 
 You MUST use these libraries when using the Seeed Wio Terminal as they have support for SAMD51 architecture.
 
- IR Library: https://github.com/Seeed-Studio/Seeed_Arduino_IRSendRev
- Display Library: https://github.com/Seeed-Studio/Seeed_Arduino_LCD
 
 Code is a prototype, no guarentee of any sort is implied. Use at your own risk.
 
This project is based on:
 - https://www.youtube.com/watch?v=C9AlljLst2o
 - https://github.com/lakshanthad/Wio_Terminal_Classroom_Arduino/tree/main/Classroom%2011


To add a new TV do the following:

- create a header file (new_tv_example.h).  Use an existing header file as an example
- #include your header in HackerTV_Firmware.ino
- increment num_tv_manufacturers in HackerTV_Firmware.ino
- Add a new entry the HACKERTV tv Struct.  Follow the example of what is already there.
- A case in the SWITCH statement found in the function void initialize_tv_settings() which is found towards the bottom of HackerTV_Firmware.ino
