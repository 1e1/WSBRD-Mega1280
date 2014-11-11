#ifndef FastTimer_H_
#define FastTimer_H_

#include <Arduino.h>
#include "config.h"


#define FT_SECTION_1   7
#define FT_SECTION_2   6
#define FT_SECTION_4   5
#define FT_SECTION_8   4
#define FT_SECTION_16  3
#define FT_SECTION_32  2
#define FT_SECTION_64  1
#define FT_SECTION_128 0


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
