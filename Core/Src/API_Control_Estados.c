/*
 * API_Control_Estados.c
 *
 *  Created on: 1 oct. 2022
 *      Author: diego
 */


#include "API_Control_Estados.h"


#define Delay_Alarma 200
#define Muestreo_Temp 3000

// Typedef enum?
#define Min_Temp_Critica 40
#define Min_Temp_Alta 30
#define Min_Temp_Media 15
#define Min_Temp_Baja 0

#define Estado_Critico 4
#define Estado_Alto 3
#define Estado_Medio 2
#define Estado_Bajo 1
#define Estado_Bajo_Cero 0



typedef enum {
	LECTURA_TEMP,
	DEFINICION_ESTADO,
	ACTIVACION_ESTADO,
} debounceState_t;


// P4_2 - Variable de estado (global)
static debounceState_t curr_state;

delay_t Timer_Temp;
delay_t Timer_Alarma;


uint8_t Estado = 0;
int16_t Temp = 0;

bool flagButton = false;


void ControlFSM_init(void){
	/* Initialize BSP Led for LED */
	delayInit(&Timer_Alarma, Delay_Alarma);
	delayInit(&Timer_Temp, Muestreo_Temp);


	/* Inicializo todos los LEDS en OFF*/
	BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);
	BSP_LED_Init(LED3);
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);


	BSP_LED_Off(LED1);
	BSP_LED_Off(LED2);
	BSP_LED_Off(LED3);

	curr_state = LECTURA_TEMP;

	debounceFSM_init();
	SensorTemp_Init();
}


void ControlFSM_update(void) {
	debounceFSM_update();
	switch (curr_state) {
		case LECTURA_TEMP:
			if (delayReadState(&Timer_Temp)) {
				Temp=SensorTemp_Read();
			}
			curr_state = DEFINICION_ESTADO;
			break;

		case DEFINICION_ESTADO:
			if (readKey()) {
				if (flagButton) {
					flagButton = false;
				}else {
					flagButton = true;
					Estado = Estado_Critico;
				}
			}
			if (!flagButton) {
				Estado = Definir_Estado(Temp);
			}
			curr_state = ACTIVACION_ESTADO;
			break;

		case ACTIVACION_ESTADO:
			switch (Estado) {
				case Estado_Critico:
					Activar_Estado_Critico(&Timer_Alarma);
					break;
				case Estado_Alto:
					Activar_Estado_Alto();
					break;
				case Estado_Medio:
					Activar_Estado_Medio();
					break;
				case Estado_Bajo:
					Activar_Estado_Bajo();
					break;
				case Estado_Bajo_Cero:
					Activar_Estado_Bajo_Cero();
					break;
				default:
					break;
			}
			curr_state = LECTURA_TEMP;
			break;

		default:
				//Si algo modificó la variable estadoActual
				// a un estado no válido llevo la MEF a un
				// lugar seguro, por ejemplo, la reinicio:
				//controlDeErrores();
				ControlFSM_init();
				break;
	}
}






uint8_t Definir_Estado(int16_t Temp){
	uint8_t Estado = 0;
	if (Temp>=Min_Temp_Critica) {
		Estado = Estado_Critico;
	} else if (Temp>=Min_Temp_Alta) {
		Estado = Estado_Alto;
	} else if (Temp>=Min_Temp_Media) {
		Estado = Estado_Medio;
	} else if (Temp>=Min_Temp_Baja) {
		Estado = Estado_Bajo;
	} else {
		Estado = Estado_Bajo_Cero;
	}

	return Estado;
}


void Activar_Estado_Critico (delay_t * delay){
	if (delayReadState(delay)) {
		BSP_LED_Toggle(LED1);
		BSP_LED_Toggle(LED2);
		BSP_LED_Toggle(LED3);
//		Buzzer_toggle();
	}

}
void Activar_Estado_Alto(void){
	BSP_LED_On(LED1);
	BSP_LED_On(LED2);
	BSP_LED_On(LED3);
//	Buzzer_write(GPIO_PIN_RESET);
}
void Activar_Estado_Medio(void){
	BSP_LED_On(LED1);
	BSP_LED_On(LED2);
	BSP_LED_Off(LED3);
//	Buzzer_write(GPIO_PIN_RESET);
}
void Activar_Estado_Bajo(void){
	BSP_LED_On(LED1);
	BSP_LED_Off(LED2);
	BSP_LED_Off(LED3);
//	Buzzer_write(GPIO_PIN_RESET);
}
void Activar_Estado_Bajo_Cero(void){
	BSP_LED_Off(LED1);
	BSP_LED_Off(LED2);
	BSP_LED_Off(LED3);
//	Buzzer_write(GPIO_PIN_SET);
}
