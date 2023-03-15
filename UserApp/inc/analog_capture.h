#ifndef __ANG_CAPTURE_H
#define __ANG_CAPTURE_H

#include <stdint.h>

#define NO_OF_CH 1
#define NO_OF_SAMPLES_EACH_CH 64
#define TOTAL_SAMPLES NO_OF_CH*NO_OF_SAMPLES_EACH_CH

void analog_capture_init(void);
void analog_capture_run(void);
uint16_t analog_capture_Get_avg(void);

extern uint16_t adcResultsDMA[TOTAL_SAMPLES];

#endif
