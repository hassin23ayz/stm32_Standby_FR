#include "main.h"
#include "debug.h"
#include "low_power_control.h"

void low_power_standby_bootTime_check(void)
{
	  if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
	  {
		  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);  // clear the flag

		  /** display  the string **/
		  DBG("Wakeup from the STANDBY MODE\n\n");

		  /** Disable the WWAKEUP PIN **/
		  //HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);  // disable PA0

	  }
	  else{
		  DBG("Normal Bootn\n");
	  }
}

void low_power_standby_enter(void)
{
	  /** Now enter the standby mode **/
	   /* Clear the WU FLAG */
	  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

	  DBG("About to enter the STANDBY MODE\n");
	   /* Enable the WAKEUP PIN */
//	  HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);


	  DBG("STANDBY MODE is On\n");

	   /* Finally enter the standby mode */
	  HAL_PWR_EnterSTANDBYMode();

}
