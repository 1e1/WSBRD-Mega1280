#ifndef FastTimer_H_
#define FastTimer_H_

#include <Arduino.h>


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

#define WS_EMBEDTIME_1s_4m    byte(millis() >> 10)
#define WS_EMBEDTIME_4s_15m   byte(millis() >> 12)
//#define WS_EMBEDTIME_4s_3d    int(millis() >> 12)
#define WS_EMBEDTIME_16s_1h   byte(millis() >> 14)
#define WS_EMBEDTIME_65s_4h   byte(millis() >> 16)


// VELOCITY (choose inside macros.h)
//#define WS_EMBEDTIME EMBEDTIME_65s_4h
//#define WS_EMBEDTIME EMBEDTIME_16s_1h
#define WS_EMBEDTIME WS_EMBEDTIME_1s_4m


#define WSFT_SECTION_1   7
#define WSFT_SECTION_2   6
#define WSFT_SECTION_4   5
#define WSFT_SECTION_8   4
#define WSFT_SECTION_16  3
#define WSFT_SECTION_32  2
#define WSFT_SECTION_64  1
#define WSFT_SECTION_128 0


/** BIT **/
#define bitRead_uint8_t(value, bit)             byte(((value) >> (bit)) & byte(1))
#define bitSet_uint8_t(value, bit)              ((value) |=  (byte(1) << (bit)))
#define bitClear_uint8_t(value, bit)            ((value) &= ~(byte(1) << (bit)))
#define bitWrite_uint8_t(value, bit, bitvalue)  (bitvalue ? bitSet_uint8_t(value, bit) : bitClear_uint8_t(value, bit))

#define bitRead_boolean(value, bit)             byte(((value) >> (bit)) & byte(1))
#define bitSet_boolean(value, bit)              ((value) |=  (byte(1) << (bit)))
#define bitClear_boolean(value, bit)            ((value) &= ~(byte(1) << (bit)))
#define bitWrite_boolean(value, bit, bitvalue)  (bitvalue ? bitSet_boolean(value, bit) : bitClear_boolean(value, bit))
/** === **/


class FastTimer {

  public:
  static void begin(); // call it in setup()
  static const uint8_t update(); // call it once in the main loop()

  // inline
  __attribute__((always_inline)) inline static const boolean isSection(const byte section) { return bitRead_boolean(FastTimer::_section, section); };

  __attribute__((always_inline)) inline static const boolean getDst()       { return FastTimer::_referenceTime >> 7; };
  __attribute__((always_inline)) inline static const uint8_t getDayOfWeek() { return (FastTimer::_referenceTime >> 4) & uint8_t(B111); };
  __attribute__((always_inline)) inline static const uint8_t getHour()      { return FastTimer::_referenceTime & uint8_t(B1111); };

  protected:
  static uint8_t _section;
  static uint8_t _embedTime;
  static uint8_t _referenceTime; // SDDD HHHH (DST[0..1], day[0..6], hour[0..23])

};


#endif
