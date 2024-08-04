/*
 * 7seg.h
 *
 *  Created on: 15-Apr-2023
 *      Author: chaman
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "stm32f4xx_hal.h"

typedef struct
{
	GPIO_TypeDef * SEG_GPIO[7];
	uint16_t       SEG_PIN[7];
}SEVEN_SEG_CfgType;


/*-----[ Prototypes For All Functions ]-----*/

void SEVEN_SEG_Init(void);
void SEVEN_SEG_Main(uint16_t);


#endif /* INC_7SEG_H_ */
