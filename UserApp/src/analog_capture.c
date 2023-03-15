#include "analog_capture.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "debug.h"
#include "cmsis_os.h"

uint16_t adcResultsDMA[TOTAL_SAMPLES];
volatile uint16_t adcAvg;

volatile bool     adcConvComplete = false;

static void sort(uint16_t* pArr, uint16_t sz)
{
    uint16_t tmp = 0;
    // take one element
    for (int i = 0; i < sz-1; i++)
    {
        for (int j = i+1; j < sz; j++)
        {
            if( pArr[i] <= pArr[j])
            {
                // do nothing
            }
            else
            {
                tmp = pArr[i];
                pArr[i] = pArr[j];
                pArr[j] = tmp;
            }
        }
    }

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
//	DBG("%s callback", __func__);
	adcConvComplete  = true;
}

void analog_capture_init(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcResultsDMA, TOTAL_SAMPLES );
}

static void filter_adc_to_avg(void)
{
	sort(adcResultsDMA, NO_OF_SAMPLES_EACH_CH);

	int midPos1 = NO_OF_SAMPLES_EACH_CH / 2;
	int midPos2 = (NO_OF_SAMPLES_EACH_CH / 2)+1;

	adcAvg  = (uint16_t)(adcResultsDMA[midPos1]  +  adcResultsDMA[midPos2])/2;
}

void analog_capture_run(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcResultsDMA, TOTAL_SAMPLES );
	while(adcConvComplete == false)
	{
		osDelay(100);
	}
	filter_adc_to_avg();
	// do parsing if channels are more than 1
	adcConvComplete  = false;
}

uint16_t analog_capture_Get_avg(void)
{
	return adcAvg;
}
