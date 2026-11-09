#ifndef LED7_H
#define LED7_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

typedef struct{
	 GPIO_TypeDef *port_GPIO;
	 uint16_t pin;
}LED7_GPIO_t;

typedef enum{
	LED7_ANODE,
	LE7_CATHODE,
}LED7_Type_t;

typedef struct{
	 LED7_GPIO_t seg[7];
	 LED7_Type_t type;
}LED7_Handdle_t; 

void LED7_Init(LED7_Handdle_t *hLed,
	             LED7_GPIO_t seg_a,
               LED7_GPIO_t seg_b,
               LED7_GPIO_t seg_c,
               LED7_GPIO_t seg_d,
               LED7_GPIO_t seg_e,
               LED7_GPIO_t seg_f,
               LED7_GPIO_t seg_g,
               LED7_Type_t type);

void LED7_Display(LED7_Handdle_t *hled,uint8_t number);


#endif 