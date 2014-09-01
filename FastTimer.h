#ifndef FastTimer_H_
#define FastTimer_H_

#include <Arduino.h>
#include "config.h"


class FastTimer {

  public:
  static void begin(); // call it in setup()
  static const uint8_t update(); // call it once in the main loop()

  // inline
  __attribute__((always_inline)) inline static const boolean getDst()       { return FastTimer::_referenceTime >> 7; };
  __attribute__((always_inline)) inline static const uint8_t getDayOfWeek() { return (FastTimer::_referenceTime >> 4) & uint8_t(B111); };
  __attribute__((always_inline)) inline static const uint8_t getHour()      { return FastTimer::_referenceTime & uint8_t(B1111); };

  protected:
  static uint8_t _embedTime;
  static uint8_t _referenceTime; // SDDD HHHH (DST[0..1], day[0..6], hour[0..23])

};


#endif FastTimer_H_