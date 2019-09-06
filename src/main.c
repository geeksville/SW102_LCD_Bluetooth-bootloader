#include <stdint.h>
#include "boards.h"
#include "nrf_delay.h"
#include "nrf_bootloader.h"
#include "nrf_bootloader_app_start.h"
#include "nrf_dfu_settings.h"
#include "nrf_bootloader_info.h"
#include "nrf_dfu.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

/** @brief User implementation of nrf_dfu_check_enter (__WEAK in nrf_dfu.c).
 */
bool nrf_dfu_enter_check(void)
{
  uint32_t cnt = 0;

  while (nrf_gpio_pin_read(BUTTON_PWR__PIN) && !nrf_gpio_pin_read(BUTTON_M__PIN) && cnt++ < 5000)
  {
    nrf_delay_ms(1);
    if (cnt >= 5000)
      return true;
  }

  /* Buttonless DFU seems kind of useless for us? */
  /* Because as soon as we reset, BUTTON_PWR__PIN resets too and power gets lost */
  // Update from kevinh: no, based on looking at the mfg bootloader this should work.  Because when the appload
  // reenters the bootloader it isn't doing a true reset, just jumping to the beginning of the bootloader 
  // (so GPIOs don't change)
  if (s_dfu_settings.enter_buttonless_dfu == 1)
  {
    s_dfu_settings.enter_buttonless_dfu = 0;
    APP_ERROR_CHECK(nrf_dfu_settings_write(NULL));
    return true;
  }

  return false;
}

/**@brief Function for application main entry.
 */
int main(void)
{
  /* TODO: After firmware update, start-up needs some seconds (~3 s) to boot into firmware.
   * If you let the power button go during this time, firmware (or setting page?) gets corrupted and SW102 starts in DFU again.
   */

  (void) NRF_LOG_INIT(NULL);

  nrf_gpio_cfg_input(BUTTON_M__PIN, NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_input(BUTTON_PWR__PIN, NRF_GPIO_PIN_NOPULL);
  nrf_gpio_cfg_output(SYSTEM_POWER_HOLD__PIN);
  /* SYSTEM_POWER_HOLD__PIN triggers in nrf_dfu.c */

  nrf_bootloader_init();

  // Either there was no DFU functionality enabled in this project or the DFU module detected
  // no ongoing DFU operation and found a valid main application.
  // Boot the main application.
  nrf_bootloader_app_start(MAIN_APPLICATION_START_ADDR);

  // Here be dragons!
}
