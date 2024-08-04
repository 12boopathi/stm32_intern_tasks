/*
 * tim.c
 *
 *  Created on: Jul 30, 2024
 *      Author: boobathi
 */
#include "main.h"
#include "timer.h"



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim6) {
    if (htim6->Instance == TIM6) {  // Replace TIMx with your specific timer
        display_number(current_number);
        current_number = (current_number + 1) % 10;  // Increment and wrap around
    }
}
