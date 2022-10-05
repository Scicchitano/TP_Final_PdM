/*
 * API_uart.c
 *
 *  Created on: 21 sep. 2022
 *      Author: diego
 */

#include "API_uart.h"

/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_8
#define USARTx_TX_GPIO_PORT              GPIOD
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART3




/* MACROS DE USUARIO*/
#define BaudVel 115200  //Especifique la velocidad en baudios
#define Timeout_UART 1000
#define MAX_Size_String_UART 100 //Solo se enviara como maximo MAX_Size_String_UART caracteres

/* UART handler declaration */
UART_HandleTypeDef UartHandle;

bool uartInit(){
	/*##-1- Configure the UART peripheral ######################################*/
	  /* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	  /* UART configured as follows:
		  - Word Length = 8 Bits (7 data bit + 1 parity bit) :
						  BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
		  - Stop Bit    = One Stop bit
		  - Parity      = ODD parity
		  - BaudRate    = 9600 baud
		  - Hardware flow control disabled (RTS and CTS signals) */
	  UartHandle.Instance        = USARTx;

	  UartHandle.Init.BaudRate   = BaudVel;
	  UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	  UartHandle.Init.StopBits   = UART_STOPBITS_1;
	  UartHandle.Init.Parity     = UART_PARITY_ODD;
	  UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	  UartHandle.Init.Mode       = UART_MODE_TX_RX;
	  UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	  if (HAL_UART_Init(&UartHandle) != HAL_OK)
	  {
		return false;
	  }
	  return true;
}



void uartSendString(uint8_t * pstring){

	uint8_t * aux_string = pstring;
	uint8_t size_string = 0;
	while(*aux_string != 0){
		size_string++;
		aux_string++;
		if (size_string>=MAX_Size_String_UART) {
			break;
		}
	}
	HAL_UART_Transmit(&UartHandle, pstring , size_string, Timeout_UART);
}



void uartSendStringSize(uint8_t * pstring, uint16_t size){
	HAL_UART_Transmit(&UartHandle, pstring , size, Timeout_UART);
}

HAL_StatusTypeDef uartReceiveStringSize(uint8_t * pstring, uint16_t size){
	return HAL_UART_Receive(&UartHandle, pstring, 100, 1000);
}
