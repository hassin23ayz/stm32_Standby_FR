#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "task_default.h"
#include "debug.h"

#include "analog_capture.h"


void task_default_init(void)
{
	DBG("%s", __func__);
	analog_capture_init();
}

void task_default_run(void)
{
//	printf("%s : %lu \n\r", __func__, xTaskGetTickCount() );
	analog_capture_run();
	analog_capture_print();
}
