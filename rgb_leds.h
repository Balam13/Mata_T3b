/*
 * rgb_leds.h
 *
 *  Created on: 9 jun. 2021
 *      Author: cmata
 */

#include <stdio.h>
#include "fsl_debug_console.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "fsl_pit.h"

#define PIN26        26u //led verde
#define PIN22        22u //led rojo
#define PIN21        21u //led azul
#define PIN06        6u  //switch2 PortC
#define PIN04        4u  //switch3 PortA

void limpiar(void);
void verde (void);
void azul (void);
void morado (void);
void rojo (void);
void amarillo (void);
void blanco(void);

volatile bool pitIsrFlag = false;

gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        1,
};

gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
};



void limpiar(void){
	GPIO_PortSet(GPIOB, 1u << PIN21);
	GPIO_PortSet(GPIOE, 1u << PIN26);
	GPIO_PortSet(GPIOB, 1u << PIN22);
}

void azul (void){
	limpiar();
	GPIO_PortClear(GPIOB, 1u << PIN21);
}

void morado (void){
	limpiar();
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOB, 1u << PIN21);
}


void rojo (void){
	limpiar();
	GPIO_PortClear(GPIOB, 1u << PIN22);
}


void amarillo (void){
	limpiar();
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOE, 1u << PIN26);
}


void verde (void){
	limpiar();
	GPIO_PortClear(GPIOE, 1u << PIN26);
}


void blanco(void){
	limpiar();
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOE, 1u << PIN26);
	GPIO_PortClear(GPIOB, 1u << PIN21);
}


