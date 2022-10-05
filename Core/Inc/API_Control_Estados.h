/*
 * API_Control_Estados.h
 *
 *  Created on: 1 oct. 2022
 *      Author: diego
 */

#ifndef API_API_CONTROL_ESTADOS_INC_API_CONTROL_ESTADOS_H_
#define API_API_CONTROL_ESTADOS_INC_API_CONTROL_ESTADOS_H_

#include "API_debounce.h"
#include "SensorTemp.h"
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */

/**
 * @fn void debounceFSM_init(void)
 * @brief
 *
 */
void ControlFSM_init(void);	// debe cargar el estado inicial

/**
 * @fn void debounceFSM_update(void)
 * @brief debe leer las entradas, resolver la lógica de transición de estados
 * 		  y actualizar las salidas
 *
 */
void ControlFSM_update(void);



static void Activar_Estado_Critico(delay_t * delay);
static void Activar_Estado_Alto(void);
static void Activar_Estado_Medio(void);
static void Activar_Estado_Bajo(void);
static void Activar_Estado_Bajo_Cero(void);

static uint8_t Definir_Estado(int16_t Temp);




#endif /* API_API_CONTROL_ESTADOS_INC_API_CONTROL_ESTADOS_H_ */
