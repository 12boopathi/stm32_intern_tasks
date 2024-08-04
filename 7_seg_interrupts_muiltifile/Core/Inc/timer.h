/*
 * timer.h
 *
 *  Created on: Jul 30, 2024
 *      Author: boobathi
 */
TIM_HandleTypeDef htim6;

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim6);
void display_number(uint8_t number);

#endif /* INC_TIMER_H_ */
