# HackerTV ReadMe

Turning a Seeed Wio Terminal into a modular Universal TV Remote.

You MUST use these libraries when using the Seeed Wio Terminal as they have support for SAMD51 architecture.

* IR Library: [https://github.com/Seeed-Studio/Seeed\_Arduino\_IRSendRev](https://github.com/Seeed-Studio/Seeed_Arduino_IRSendRev)
* Display Library: [https://github.com/Seeed-Studio/Seeed\_Arduino\_LCD](https://github.com/Seeed-Studio/Seeed_Arduino_LCD)

### Code is a prototype, no guarentee of any sort is implied. Use at your own risk.

This project is based on:

* [https://www.youtube.com/watch?v=C9AlljLst2o](https://www.youtube.com/watch?v=C9AlljLst2o)
* [https://github.com/lakshanthad/Wio\_Terminal\_Classroom\_Arduino/tree/main/Classroom 11](https://github.com/lakshanthad/Wio_Terminal_Classroom_Arduino/tree/main/Classroom%2011)

To add a new TV do the following:

* create a header file \(example\_new\_tv\_codes.h\).  Use an existing header file as an example
* **include your header in HackerTV\_Firmware.ino**
* increment num\_tv\_manufacturers in HackerTV\_Firmware.ino
* Add a new entry in the HACKERTV tv Struct.  Follow the example of what is already there.
* Add a new Case in the SWITCH statement found in the function void initialize\_tv\_settings\(\) which is found towards the bottom of HackerTV\_Firmware.ino

### Only use this project on TVs that you own. Don't be a jerk.

To use an external Grove IR transmitter, you must change the file IRremoteBoardDefs.h  
It is part of the IR library.  
The file should be found at ..\Arduino\libraries\Seeed\_Arduino\_IRSendRev-master\src\private

elif defined\(ARDUINO\_ARCH\_SAMD\)  
// use timer 3 hardcoded at this time  
ifdef WIO\_TERMINAL  
define IR\_SEND\_PIN WIO\_IR // USE D0 FOR WIO TERMINAL'S EXTERNAL GROVE D/A CONNECTOR, BY DEFAULT USES WIO\_IR\(D14\)  
else  
define IR\_SEND\_PIN 9  
endif

