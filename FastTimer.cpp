#include "FastTimer.h"




/***********************************************************
 *                       PROPERTIES                        *
 **********************************************************/




uint8_t FastTimer::_embedTime      = -1; // force "new time section" at startup
uint8_t FastTimer::_referenceTime  = B01111111;




/***********************************************************
 *                         PUBLIC                          *
 **********************************************************/




void FastTimer::begin()
{
}


/**
  *   0: same time section
  *   1: new time section
  * 255: new time section, new cycle
  *
  * @return int8_t
  */
const uint8_t FastTimer::update()
{
  const uint8_t previousTime = FastTimer::_embedTime;
  FastTimer::_embedTime = EMBEDTIME;
  return FastTimer::_embedTime ^ previousTime;
}
