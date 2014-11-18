#ifndef BusyLed_H_
#define BusyLed_H_

#include <Arduino.h>
#include <CoreSlave.h>



//#define LED_BUILTIN 13



class LedBuiltin : public Circuit {

  public:
  LedBuiltin(const byte pin);
  __attribute__((always_inline)) inline void custom(const uint8_t value) { analogWrite(this->_pin, value); };

  __attribute__((always_inline)) inline void on  () { digitalWrite(this->_pin, HIGH); };
  __attribute__((always_inline)) inline void off () { digitalWrite(this->_pin,  LOW); };

  //inline void check() { on(); };
  inline void work()  { this->custom(63); };
  inline void idle()  { this->custom(15); };
  inline void clean() { off(); };

  protected:
  byte _pin;

};


#endif
