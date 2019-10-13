/** @file data.h
 *  @data conversion operations
 *
 *  @Author Patrick Fitzgerald
 *  @date 13 Oct 2019
 *
 **/

#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "memory.h"


/*********** my_itoa() **************/
/*
 * @brief itoa = integer to ascii
 *
 * converts from standard integer to ascii string.  Function uses three inputs:
 *   data, ptr and base to specify the input for conversion 
 *
 *   @param data = the signed 32-bit integer data to be converted
 *   @param ptr = unsigned 8-bit integer pointer to ASCII string
 *   @param base = is input binary with base =2 or is input decimal with base = 10?
 *   @return = length of ASCII string
 *
 **/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/*********** my_atoi() **************/
/*
 * @brief atoi = ascii to integer
 *
 * converts from ascii character string to 32 bit signed integer
 *
 *   @param ptr = unsigned 8-bit pointer to the character string for conversion
 *   @param digits = quantity of digits
 *   @param base = integer value of base for conversion
 *   @return = 32-bit signed integer
 *
 **/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif
