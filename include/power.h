#ifndef _POWER_H
#define _POWER_H

#include <Arduino.h>
#include <driver/adc.h>
#include <driver/rtc_io.h>
#include <esp_adc_cal.h>
#include "i2c.h"

#define DEFAULT_VREF 1100 // tbd: use adc2_vref_to_gpio() for better estimate
#define NO_OF_SAMPLES 64  // we do some multisampling to get better values

extern RTC_DATA_ATTR runmode_t RTC_runmode;

uint16_t read_voltage(void);
void calibrate_voltage(void);
bool batt_sufficient(void);
void enter_deepsleep(const int wakeup_sec, const gpio_num_t wakeup_gpio);
int64_t exit_deepsleep(void);

#ifdef HAS_PMU
#include <axp20x.h>
void AXP192_powerevent_IRQ(void);
void AXP192_power(bool on);
void AXP192_init(void);
void AXP192_showstatus(void);
uint8_t i2c_writeBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len);
uint8_t i2c_readBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len);
#endif // HAS_PMU

#endif