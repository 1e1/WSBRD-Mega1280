#ifndef BusyLed_H_
#define BusyLed_H_

#include <Arduino.h>
#include <CoreSlave.h>



//#define LED_BUILTIN 13



class LedBuiltin : public AbstractCircuit {

  public:
  typedef enum { OFF=0, IDLE=15, WORK=63, ON=255 } State;

  LedBuiltin(const byte pin);
  __attribute__((always_inline)) inline void state(const State value) { analogWrite(this->_pin, value); };

  inline void check() { this->state(State::ON  ); };
  inline void work()  { this->state(State::WORK); };
  inline void idle()  { this->state(State::IDLE); };
  inline void clean() { this->state(State::OFF ); };

  protected:
  byte _pin;

};


#endif
