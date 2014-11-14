#ifndef BCONFIG_H_
#define BCONFIG_H_


/** TIME **/
//==>  >> 0: 1 unit of embedTime is 0.001s
//-->  const unsigned long maxTime        = 4294967295; // = 49d 17h 02m 47s
//-->  const unsigned int maxTime         = 65535;      // = 65s
//==>  >> 10: 1 unit of embedTime is 1.024s
//-->  const uint8_t maxEmbedTime         = 255;        // = 4mn 21s 120ms
//==>  >> 12: 1 unit of embedTime is 4.096s
//-->  const unsigned int maxEmbedTime    = 65535;      // = 3d 02h 33mn 51s 360ms
//     const unsigned int moduloEmbedTime = 63281;      // = 3d 00h 00mn 00s 000ms
//-->  const uint8_t maxEmbedTime         = 255;        // = 17mn 24s 480ms
//     const uint8_t moduloEmbedTime      = 219;        // = 15mn 00s 000ms
//==>  >> 14: 1 unit of embedTime is 16.384s
//-->  const uint8_t maxEmbedTime         = 255;        // = 1h 09mn 37s 920ms
//     const uint8_t moduloEmbedTime      = 219;        // = 1h 00mn 00s 000ms
//==>  >> 16: 1 unit of embedTime is 65.536s
//-->  const uint8_t maxEmbedTime         = 255;        // = 4h 38mn 31s 680ms
//     const uint8_t moduloEmbedTime      = 219;        // = 4h 00mn 00s 000ms

#define EMBEDTIME_1s_4m    byte(millis() >> 10)
#define EMBEDTIME_4s_15m   byte(millis() >> 12)
//#define EMBEDTIME_4s_3d    int(millis() >> 12)
#define EMBEDTIME_16s_1h   byte(millis() >> 14)
#define EMBEDTIME_65s_4h   byte(millis() >> 16)


// VELOCITY (choose inside macros.h)
//#define EMBEDTIME EMBEDTIME_65s_4h
//#define EMBEDTIME EMBEDTIME_16s_1h
#define EMBEDTIME EMBEDTIME_1s_4m


#endif
