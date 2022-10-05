/*
 * API_delay.h
 *
 *  Created on: Sep 7, 2022
 *      Author: diego
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

#include <stdbool.h>
#include <stdint.h>




#endif /* API_INC_API_DELAY_H_ */



typedef uint32_t tick_t; // Qué biblioteca se debe incluir para que esto compile?
typedef bool bool_t;	  // Qué biblioteca se debe incluir para que esto compile?
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;
void delayInit( delay_t * delay, tick_t duration );
bool_t delayReadState( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );
