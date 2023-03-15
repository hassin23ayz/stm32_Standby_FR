#include "analog_capture.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "debug.h"
#include "cmsis_os.h"

uint16_t adcResultsDMA[TOTAL_SAMPLES];
volatile bool     adcConvComplete = false;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
//	DBG("%s callback", __func__);
	adcConvComplete  = true;
}

void analog_capture_init(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcResultsDMA, TOTAL_SAMPLES );
}

void analog_capture_run(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcResultsDMA, TOTAL_SAMPLES );
	while(adcConvComplete == false)
	{
		osDelay(100);
	}

     DBG("new set of adc samples ");
	DBG("---------------------------------");
	for(int i=0; i<TOTAL_SAMPLES; i++){
		DBG("ADC[%d] : %d", i, adcResultsDMA[i] );
	}

	// do parsing if channels are more than 1
	adcConvComplete  = false;
}

void analog_capture_print(void)
{
	DBG("---------------------------------");
	for(int i=0; i<TOTAL_SAMPLES; i++){
		DBG("ADC[%d] : %d", i, adcResultsDMA[i] );
	}
}
