#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "task_default.h"
#include "debug.h"

#include "analog_capture.h"
#include "low_power_control.h"

void task_default_init(void)
{
	DBG("%s", __func__);

	char *str = "Task Default init \n\n";
	HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

	low_power_standby_bootTime_check();
	analog_capture_init();
}

void task_default_run(void)
{
	printf("%s : %lu \n\r", __func__, xTaskGetTickCount() );
	analog_capture_run();
//	DBG("ADC: %lu", analog_capture_Get_avg());
	char str[64];
	memset(str, '\0', 64);
	sprintf(str, "adc is @%lu \n\r", analog_capture_Get_avg());
	HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

	if(analog_capture_Get_avg() < 3500)
	{
//		DBG("ADC is at %lu : system should go into standby mode", analog_capture_Get_avg());

		char *str = "adc is low ... system should go into standby mode\n\n";
		HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen (str), HAL_MAX_DELAY);

		low_power_standby_enter();
	}
}
