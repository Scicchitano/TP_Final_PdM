/*
 * API_uart.h
 *
 *  Created on: 21 sep. 2022
 *      Author: diego
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

/* P2_1 - Inclusión de tipos de datos de tamaño fijo */
#include <stdint.h>
#include <stdbool.h>

#include "stm32f4xx_hal.h"


/* Exported types ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/**
 * @fn void debounceFSM_init(void)
 * @brief
 *
 */
bool uartInit();	// debe cargar el estado inicial

/**
 * @fn void debounceFSM_update(void)
 * @brief Debe enviar un string por uart
 *
 */
void uartSendString(uint8_t * pstring);


/**
 * @fn bool_t readKey()
 * @brief Debe enviar un string por uart especificando el tamaño
 *
 * @return
 */
void uartSendStringSize(uint8_t * pstring, uint16_t size);


/**
 * @fn bool_t readKey()
 * @brief Debe recibir un string por uart especificando el tamaño
 *
 * @return
 */
HAL_StatusTypeDef uartReceiveStringSize(uint8_t * pstring, uint16_t size);






#endif /* API_INC_API_UART_H_ */
