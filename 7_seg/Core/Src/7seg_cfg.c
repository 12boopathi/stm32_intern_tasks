/*
 * 7seg_cfg.c
 *
 *  Created on: 15-Apr-2023
 *      Author: chaman
 */


#include"7seg.h"

const SEVEN_SEG_CfgType SEVEN_SEG_CfgParam =
{
	// 7-Segments Display Unit 1 Configurations
    {
    	/* Seven Segments Pins Info */
	    {GPIOC, GPIOC, GPIOC, GPIOC, GPIOC, GPIOC, GPIOC},
		{GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6},
	}
};
