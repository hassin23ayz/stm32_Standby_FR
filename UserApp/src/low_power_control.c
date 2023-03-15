#include "main.h"
#include "debug.h"
#include "low_power_control.h"

void low_power_standby_bootTime_check(void)
{
//	  if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
//	  {
//		  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);  // clear the flag
//
//		  /** display  the string **/
//		  DBG("Wakeup from the STANDBY MODE\n\n");
//
//		  /** Disable the WWAKEUP PIN **/
//		  HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);  // disable PA0
//
//		  /** Deactivate the RTC wakeup  **/
//		  HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
//	  }
}

void low_power_standby_enter(void)
{


}
