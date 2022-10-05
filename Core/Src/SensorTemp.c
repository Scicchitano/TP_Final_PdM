/*
 * API_delay.c
 *
 *  Created on: Sep 7, 2022
 *      Author: diego
 */


#include "SensorTemp.h"
#include <stdlib.h>
#include "API_uart.h"


ADC_HandleTypeDef hadc1;

void SensorTemp_Init(){
	uartInit();
	MX_ADC1_Init();
}


int8_t SensorTemp_Read(void){
	uint16_t AD_RES = 0;
	HAL_ADC_Start(&hadc1);
	// Poll ADC1 Perihperal & TimeOut = 1mSec
	HAL_ADC_PollForConversion(&hadc1, 1);
	// Read The ADC Conversion Result & Map It To PWM DutyCycle
	AD_RES = HAL_ADC_GetValue(&hadc1);
	uartSendString((uint8_t *) &AD_RES);
	return AD_RES;
}



static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

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

