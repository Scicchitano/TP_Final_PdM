/*
 * Buzzer.h
 *
 *  Created on: 28 sep. 2022
 *      Author: diego
 */

#ifndef BUZZER_INC_BUZZER_H_
#define BUZZER_INC_BUZZER_H_

void Buzzer_init(void); // Se inicializa la configuración del GPIO del buzzer
void Buzzer_write(GPIO_PinState Estado); // Se cambia el estado del buzzer
void Buzzer_toggle(void);






#endif /* BUZZER_INC_BUZZER_H_ */
