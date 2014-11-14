#ifndef BusyLed_H_
#define BusyLed_H_

#include <Arduino.h>
#include "config.h"



class BusyLed {

  public:
  static void begin(const byte pin);
  __attribute__((always_inline)) inline static void custom(const uint8_t value) { analogWrite(BusyLed::_pin, value); };

  __attribute__((always_inline)) inline static void on  () { digitalWrite(BusyLed::_pin, HIGH); };
  __attribute__((always_inline)) inline static void work() { digitalWrite(BusyLed::_pin,   63); };
  __attribute__((always_inline)) inline static void idle() { digitalWrite(BusyLed::_pin,   15); };
  __attribute__((always_inline)) inline static void off () { digitalWrite(BusyLed::_pin,  LOW); };

  protected:
  static byte _pin;

};


#endif
