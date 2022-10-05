/*
 * API_delay.c
 *
 *  Created on: Sep 7, 2022
 *      Author: diego
 */


#include "SensorTemp.h"
#include <stdlib.h>
#include "API_uart.h"

uint8_t msg[2] = {'a','b'};

void SensorTemp_Init(){
	uartInit();
}


int8_t SensorTemp_Read(void){

	uartReceiveStringSize((uint8_t *) msg, 2);
	uartSendString((uint8_t *) msg);
	return str_to_decimal((const char *) msg);
}



int str_to_decimal(const char *s)
{
    const char *digits = "0123456789";
    int result = 0;
    bool flagNegativo = false;
    if (*s == '-') {
    	flagNegativo = true;
	}

    for (; *s; ++s) {
        int digit_val;

        /* Find the index of the digit (equivalent to its numeric value) */
        for (digit_val = 0; digits[digit_val]; ++digit_val) {
            if (digits[digit_val] == *s)
                break;
        }

        /* Only process recognized digits */
        if (digits[digit_val])
            result = 10 * result + digit_val;
    }

    if (flagNegativo) {
		result = -result;
	}

    return result;
}

