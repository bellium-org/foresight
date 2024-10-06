/**
 * @file main.cpp
 * @brief The entry to my code base
 *
 * @author Nathan Nguyen
 *
 * @date 05/10/24
 */


#include "config.h"
#include "usart.h"
#include <util/delay.h>
#include <stdio.h>

int main(void) {
    USART_Init();

    while (1) {
		printf("Test\n");
    }

    return 0;
}