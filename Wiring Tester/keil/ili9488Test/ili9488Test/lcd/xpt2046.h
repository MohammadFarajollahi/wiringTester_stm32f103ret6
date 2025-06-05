#ifndef XPT2046_TOUCH_H_
#define XPT2046_TOUCH_H_

#include "main.h"
#include <stdbool.h>

/*** Redefine if necessary ***/

// Warning! Use SPI bus with < 2.5 Mbit speed, better ~650 Kbit to be save.
extern TIM_HandleTypeDef htim1;
#define time_us htim1

#define XPT2046_IRQ_Pin       T_IRQ_Pin
#define XPT2046_IRQ_GPIO_Port T_IRQ_GPIO_Port
#define XPT2046_CS_Pin        T_CS_Pin
#define XPT2046_CS_GPIO_Port  T_CS_GPIO_Port

// change depending on screen orientation
#define XPT2046_SCALE_X 479   //480
#define XPT2046_SCALE_Y 319	  //320

// to calibrate uncomment UART_Printf line in ili9341_touch.c
#define XPT2046_MIN_RAW_X 221
#define XPT2046_MAX_RAW_X 3898
#define XPT2046_MIN_RAW_Y 141
#define XPT2046_MAX_RAW_Y 3930

// call before initializing any SPI devices
bool XPT2046_TouchPressed(void);
bool XPT2046_TouchGetCoordinates(uint16_t* x, uint16_t* y);

#endif /* XPT2046_TOUCH_H_ */
