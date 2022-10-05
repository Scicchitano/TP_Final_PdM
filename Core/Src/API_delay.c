/*
 * API_delay.c
 *
 *  Created on: Sep 7, 2022
 *      Author: diego
 */


#include "API_delay.h"

#define MAX_duration 3600000 //1 hora


/*delayInit debe cargar el valor de duración del retardo en la estructura, en el campo correspondiente.
 No debe iniciar el conteo del retardo. Debe inicializar el flag running en `false´.*/
void delayInit( delay_t * delay, tick_t duration ){
	if (delay!=0 && duration<MAX_duration && duration>0) {
		delay->duration = duration;
		delay->running = 0;
	}else{
		while(1);
	}

}


/*La siguiente funcion debe verificar el estado del flag running. si es false, debe tomar marca de tiempo y cambiar
 running a ‘true’. Si es true, debe hacer la cuenta para saber si el tiempo del retardo se cumplió o no y devolver
 'true' o 'false' respectivamente. */
bool_t delayReadState( delay_t * delay ){
	if (delay!=0){
		if (!delay->running){
			delay->startTime=HAL_GetTick();
			delay->running=1;
		}else{
			if(HAL_GetTick()-delay->startTime >= delay->duration){
				//delay->startTime = HAL_GetTick();
				delay->running=0;
				return true;
			}else{
				return false;
			}
		}
		return false;
	}else{
		while(1);
	}
	return false;
}



/*delayWrite debe permitir cambiar el tiempo de duración de un delay existente*/
void delayWrite( delay_t * delay, tick_t duration ){
	if (delay!=0 && duration<MAX_duration) {
		delay->duration = duration;
	}else{
		while(1);
	}
}
