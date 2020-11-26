# HackerTV
 Turning a Seeed Wio Terminal into a modular Universal TV Remote.
 
 You MUST use these libraries when using the Seeed Wio Terminal as they have support for SAMD51 architecture.
 
- IR Library: https://github.com/Seeed-Studio/Seeed_Arduino_IRSendRev
- Display Library: https://github.com/Seeed-Studio/Seeed_Arduino_LCD
 
### Code is a prototype, no guarentee of any sort is implied. Use at your own risk.
 
This project is based on:
 - https://www.youtube.com/watch?v=C9AlljLst2o
 - https://github.com/lakshanthad/Wio_Terminal_Classroom_Arduino/tree/main/Classroom%2011

To add a new TV do the following:

- create a header file (example_new_tv_codes.h).  Use an existing header file as an example
- #include your header in HackerTV_Firmware.ino
- increment num_tv_manufacturers in HackerTV_Firmware.ino
- Add a new entry in the HACKERTV tv Struct.  Follow the example of what is already there.
- Add a new Case in the SWITCH statement found in the function void initialize_tv_settings() which is found towards the bottom of HackerTV_Firmware.ino

### Only use this project on TVs that you own. Don't be a jerk.

To use an external Grove IR transmitter, you must change the file IRremoteBoardDefs.h  
It is part of the IR library.  
The file should be found at  ..\Arduino\libraries\Seeed_Arduino_IRSendRev-master\src\private  

#elif defined(ARDUINO_ARCH_SAMD)  
// use timer 3 hardcoded at this time  
#ifdef WIO_TERMINAL  
#define IR_SEND_PIN WIO_IR   // USE D0 FOR WIO TERMINALS GROVE D/A CONNECTOR,  BY DEFAULT WIO_IR SET FOR INTERNAL IR LED ON PIN D14  
#else  
#define IR_SEND_PIN 9  
#endif  
